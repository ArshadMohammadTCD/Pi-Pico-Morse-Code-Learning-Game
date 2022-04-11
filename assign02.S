#include "hardware/regs/addressmap.h"
#include "hardware/regs/io_bank0.h"
#include "hardware/regs/timer.h"
#include "hardware/regs/m0plus.h"
.syntax unified
.cpu cortex-m0plus
.thumb
.global main_asm
.align 4
.equ DFLT_STATE_STRT, 1 @ Specify the value to start flashing
.equ DFLT_STATE_STOP, 0 @ Specify the value to stop flashing
.equ GPIO_BTN_FALL_MSK, 0x00400000 @ Bit-22 for falling-edge event on GP21
.equ GPIO_BTN_RISE_MSK, 0x00800000 @ Bit-23 for rising-edge event on GP21
.equ GPIO_BTN, 21 @ Specify pin for the button
.equ GPIO_LED_PIN, 25 @ Specify pin for the built-in LED
.equ GPIO_DIR_IN, 0 @ Specify input direction for a GPIO pin
.equ GPIO_DIR_OUT, 1 @ Specify output direction for a GPIO pin
.equ LED_VAL_ON, 1 @ Specify value that turns the LED "on"
.equ LED_VAL_OFF, 0 @ Specify value that turns the LED "off"
.equ GPIO_ISR_OFFSET, 0x74 @ GPIO is int #13 (vector table entry 29)
.equ ONE_SECOND, 500000     //Approximate time for one second
.equ TWO_SECONDS, 1000000   //Approximate time for two seconds

.equ MORSE_MEMORY, 0x10000010   //Address where the morse string will be stored


@ Entry point to the ASM portion of the program
//
// Main entry point into the ASM portion of the code
//
main_asm:
    bl    init_leds           // Same as previous labs
    bl    init_btns           // Use asm_gpio_set_irq C function to setup falling-edge interrupts
    bl    install_gpio_isr    // See below
    ldr   r5, =1              //Boolean variable for checking if its first press
    ldr   r6, =-1             //Initialise time between presses register with -1
    ldr   r7, =0              // Counter variable for Morse Memory
loop:
    wfi                       // Wait here until any interrupt fires
    b     loop                // Always branch back to loop
    

//
// Service the pending interrupt from the ALARM0 TIMER
//

//
// Sets up the gpio_isr in the RAM vector table and enables the correct interrupt
//
install_gpio_isr:
    ldr     r2, =(PPB_BASE + M0PLUS_VTOR_OFFSET)            //Get the address of the RAM vector table using the (PPB_BASE + M0PLUS_VTOR_OFFSET) register
    ldr     r1, [r2]                        
    movs    r2, #GPIO_ISR_OFFSET            
    add     r2, r1                          
    ldr     r0, =gpio_isr   
    str     r0, [r2]                                        //Store the address of the gpio_isr handler to the correct offset for GPIO in the vector table
    
    ldr     r2, =(PPB_BASE + M0PLUS_NVIC_ICPR_OFFSET)       //Disable the GPIO IRQ by writing the correct value to (PPB_BASE + M0PLUS_NVIC_ICPR_OFFSET)
    ldr     r0, =1
    lsls    r0, #13                                         //Shift 1 to the correct bit position
    str     r0, [r2]

    ldr     r2, =(PPB_BASE + M0PLUS_NVIC_ISER_OFFSET)       //Enable the GPIO IRQ by writing the correct value to (PPB_BASE + M0PLUS_NVIC_ISER_OFFSET)
    str     r0, [r2] 
    bx      lr                                              //Exit subroutine
    
//
// Service the pending interrupt from the GPIO
//
.thumb_func
gpio_isr:
    PUSH    {lr}
    ldr     r1, =(IO_BANK0_BASE + IO_BANK0_PROC0_INTS2_OFFSET)      
    ldr     r0, [r1]
    ldr     r1, =GPIO_BTN_FALL_MSK                                        
    ands    r0, r1
    cmp     r0, r1
    beq     begin_timer

//Program reaches here if the button was released
    ldr     r1, =(TIMER_BASE + TIMER_TIMELR_OFFSET)
    subs    r0, r1, r4                                      //Duration of button press      
    bl      morse_writer

    ldr     r3, =(TIMER_BASE + TIMER_TIMELR_OFFSET)        //First time stamp for TIME_BETWEEN_PRESSES 
    ldr     r0, =GPIO_BTN_RISE_MSK
    b       end


begin_timer:
    ldr     r4, =(TIMER_BASE + TIMER_TIMELR_OFFSET)         //Get the current timer count from (TIMER_BASE + TIMER_TIMELR_OFFSET) register 
    cmp     r5, #1
    beq     disable_first_press
    subs    r6, r4, r3                                      //Time for TIME_BETWEEN_PRESSES
    ldr     r0, =GPIO_BTN_FALL_MSK                           
    b       end

disable_first_press:
    ldr     r5, =0  
    ldr     r0, =GPIO_BTN_FALL_MSK                       
    
end:
    ldr     r2, =(IO_BANK0_BASE + IO_BANK0_INTR2_OFFSET)
    str     r0, [r2]                                        //Acknowledge whatever interrupt was called by one of the three buttons
    POP     {pc}




init_leds:
    PUSH    {lr}
    movs    r0, #GPIO_LED_PIN            // This value is the GPIO LED pin on the PI PICO board
    bl      asm_gpio_init                // Initialise the GPIO LED pin
                                    
    movs    r0, #GPIO_LED_PIN            
    movs    r1, #GPIO_DIR_OUT            // We want this GPIO pin to be setup as an output pin
    bl      asm_gpio_set_dir             // Specify the GPIO pin as an output pin
    POP     {pc}





init_btns:
    PUSH    {lr}

    movs    r0, #GPIO_BTN                // This value is the GPIO DOWN BTN on the PI PICO board
    bl      asm_gpio_init                            
                                                               
    movs    r0, #GPIO_BTN             
    movs    r1, #GPIO_DIR_IN             // We want this GPIO pin to be setup as an output pin
    bl      asm_gpio_set_dir             // Specify the GPIO pin as an output pin                                   

    movs    r0, #GPIO_BTN
    bl      asm_gpio_set_irq_rise        //Enables rising edge interrupts for the specified pin

    movs    r0, #GPIO_BTN
    bl      asm_gpio_set_irq_fall        //Enables falling edge interrupts for the specified pin
    
    POP     {pc}

    


morse_writer:
    PUSH    {lr}
    ldr     r2, =-1
    cmp     r6, r2                                  //Check if this is the first press by reading r11 register
    beq     dot_or_dash                             //If so next input will be a dot or dash, can't be a space

    ldr     r2, =TWO_SECONDS
    cmp     r6, r2 
    bge     terminate_string
    ldr     r2, =ONE_SECOND                         
    cmp     r6, r2 
    bge     input_space

dot_or_dash:
    cmp     r0, r2                                  //r0 is how long the button was pressed for
    blt     its_a_dot

    ldr     r0, =45                                 //ASCII code for a hyphen
    ldr     r1, =MORSE_MEMORY
    strb    r0, [r1, r7]
    adds    r7, r7, #1
    b       end_morse


its_a_dot:
    ldr     r0, =46                                 //ASCII code for a period
    ldr     r1, =MORSE_MEMORY                       //Store 1 in MORSE_MEMORY
    strb    r0, [r1, r7]
    adds    r7, r7, #1
    b       end_morse

input_space:
    ldr     r0, =32                                 //ASCII code for a space
    ldr     r1, =MORSE_MEMORY
    strb    r0, [r1, r7]                           //Store space in memory using r12 offset for appropriate byte
    adds    r7, r7, #1
    b       dot_or_dash

terminate_string:
    ldr     r0, =0
    ldr     r1, =MORSE_MEMORY
    strb    r0, [r1, r7]
    ldr     r7, =0                                 //Reset counter variable for Morse Memory
    ldr     r6, =-1                                //Reset time between presses variable
    ldr     r5, =1                                 //Reset is_first_press variable
    ldr     r0, =MORSE_MEMORY
    bl      readMorseString
end_morse:
    POP     {pc}



main_loop:
 b main_loop

 .align 4

.data
lstate: .word DFLT_STATE_STRT
ltimer: .word DFLT_ALARM_TIME