#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pio.h"
#include "assign02.h"
#include "ws2812.pio.h"

#define IS_RGBW true        // Will use RGBW format
#define NUM_PIXELS 1        // There is 1 WS2812 device in the chain
#define WS2812_PIN 28       // The GPIO pin that the WS2812 connected to


// Declare the main assembly code entry point.
void main_asm();


// Initialise a GPIO pin – see SDK for detail on gpio_init()
void asm_gpio_init(uint pin) {
 gpio_init(pin);
}


// Set direction of a GPIO pin – see SDK for detail on gpio_set_dir()
void asm_gpio_set_dir(uint pin, bool out) {
 gpio_set_dir(pin, out);
}


// Get the value of a GPIO pin – see SDK for detail on gpio_get()
bool asm_gpio_get(uint pin) {
 return gpio_get(pin);
}


// Set the value of a GPIO pin – see SDK for detail on gpio_put()
void asm_gpio_put(uint pin, bool value) {
    gpio_put(pin, value);
}


// Enable falling-edge interrupt – see SDK for detail on gpio_set_irq_enabled()
void asm_gpio_set_irq_fall(uint pin) {
     gpio_set_irq_enabled(pin, GPIO_IRQ_EDGE_FALL, true);
}


// Enable rising-edge interrupt – see SDK for detail on gpio_set_irq_enabled()
void asm_gpio_set_irq_rise(uint pin) {
    gpio_set_irq_enabled(pin, GPIO_IRQ_EDGE_RISE, true);
}

static inline void put_pixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
    return  ((uint32_t) (r) << 8)  |
            ((uint32_t) (g) << 16) |
            (uint32_t) (b);
}

void set_led_color(int color) {
    if(color == 1) put_pixel(urgb_u32(0x7F, 0x00, 0x00)); // red
    else if (color == 2) put_pixel(urgb_u32(0xFF, 0xAF, 0x00)); // orange
    else if (color == 3) put_pixel(urgb_u32(0x00, 0x00, 0x7F)); // blue
}

void morseStringAdd(char characterToAdd)
{
    morseString[morseStringIndex] = characterToAdd;
    printf("%c", morseString[morseStringIndex]);
    morseStringIndex++;
}

bool compareMorseStruct(char * inputMorse, int inputLength, char * patternMorse, int patternLength)
{
    if(inputLength != patternLength) return false;
    for(int i = 0; i < inputLength; i++)
    {
        if(inputMorse[i] != patternMorse[i]) return false;
    }   
    return true;
}

//This function checks what character the input morse string represents, and returns that character if there is a match. Else it returns the space character
char readMorseString()
{
    char currChar = morseString[0];
    int length = 0;
    for(int i = 0; currChar != '\0'; i++)
    {
        currChar = morseString[i];
        length++;
    }

    if(compareMorseStruct(morseString, length, A, a.morseLength)) return a.AsciiChar;
    else if(compareMorseStruct(morseString, length, B, b.morseLength)) return b.AsciiChar;
    else if(compareMorseStruct(morseString, length, C, c.morseLength)) return c.AsciiChar;
    else if(compareMorseStruct(morseString, length, D, d.morseLength)) return d.AsciiChar;
    else if(compareMorseStruct(morseString, length, E, e.morseLength)) return e.AsciiChar;
    else if(compareMorseStruct(morseString, length, F, f.morseLength)) return f.AsciiChar;
    else if(compareMorseStruct(morseString, length, G, g.morseLength)) return g.AsciiChar;
    else if(compareMorseStruct(morseString, length, H, h.morseLength)) return h.AsciiChar;
    else if(compareMorseStruct(morseString, length, I, i.morseLength)) return i.AsciiChar;
    else if(compareMorseStruct(morseString, length, J, j.morseLength)) return j.AsciiChar;
    else if(compareMorseStruct(morseString, length, K, k.morseLength)) return k.AsciiChar;
    else if(compareMorseStruct(morseString, length, L, l.morseLength)) return l.AsciiChar;
    else if(compareMorseStruct(morseString, length, M, m.morseLength)) return m.AsciiChar;
    else if(compareMorseStruct(morseString, length, N, n.morseLength)) return n.AsciiChar;
    else if(compareMorseStruct(morseString, length, O, o.morseLength)) return o.AsciiChar;
    else if(compareMorseStruct(morseString, length, P, p.morseLength)) return p.AsciiChar;
    else if(compareMorseStruct(morseString, length, Q, q.morseLength)) return q.AsciiChar;
    else if(compareMorseStruct(morseString, length, R, r.morseLength)) return r.AsciiChar;
    else if(compareMorseStruct(morseString, length, S, s.morseLength)) return s.AsciiChar;
    else if(compareMorseStruct(morseString, length, T, t.morseLength)) return t.AsciiChar;
    else if(compareMorseStruct(morseString, length, U, u.morseLength)) return u.AsciiChar;
    else if(compareMorseStruct(morseString, length, V, v.morseLength)) return v.AsciiChar;
    else if(compareMorseStruct(morseString, length, W, w.morseLength)) return w.AsciiChar;
    else if(compareMorseStruct(morseString, length, X, x.morseLength)) return x.AsciiChar;
    else if(compareMorseStruct(morseString, length, Y, y.morseLength)) return y.AsciiChar;
    else if(compareMorseStruct(morseString, length, Z, z.morseLength)) return z.AsciiChar;

    else if(compareMorseStruct(morseString, length, ZERO, zero.morseLength)) return zero.AsciiChar;
    else if(compareMorseStruct(morseString, length, ONE, one.morseLength)) return one.AsciiChar;
    else if(compareMorseStruct(morseString, length, TWO, two.morseLength)) return two.AsciiChar;
    else if(compareMorseStruct(morseString, length, THREE, three.morseLength)) return three.AsciiChar;
    else if(compareMorseStruct(morseString, length, FOUR, four.morseLength)) return four.AsciiChar;
    else if(compareMorseStruct(morseString, length, FIVE, five.morseLength)) return five.AsciiChar;
    else if(compareMorseStruct(morseString, length, SIX, six.morseLength)) return six.AsciiChar;
    else if(compareMorseStruct(morseString, length, SEVEN, seven.morseLength)) return seven.AsciiChar;
    else if(compareMorseStruct(morseString, length, EIGHT, eight.morseLength)) return eight.AsciiChar;
    else if(compareMorseStruct(morseString, length, NINE, nine.morseLength)) return nine.AsciiChar;
    else return '?';
}

// Main entry point of the application
int main() {
    morseString = calloc(50, sizeof(char));
    stdio_init_all(); // Initialise all basic IO

    // Initialise the PIO interface with the WS2812 code
    PIO pio = pio0;
    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, 0, offset, WS2812_PIN, 800000, IS_RGBW);

    // Do forever...
    while(true) {

        // Set the color to red at half intensity
        put_pixel(urgb_u32(0x7F, 0x00, 0x00));
        sleep_ms(500);

        // Set the color to green at half intensity
        put_pixel(urgb_u32(0x00, 0x7F, 0x00));
        sleep_ms(500);

        // Set the color to blue at half intensity
        put_pixel(urgb_u32(0x00, 0x00, 0x7F));
        sleep_ms(500);

    }
 
    printf("██     ██ ███████ ██       ██████  ██████  ███    ███ ███████ ██ \n");
    printf("██     ██ ██      ██      ██      ██    ██ ████  ████ ██      ██ \n");
    printf("██  █  ██ █████   ██      ██      ██    ██ ██ ████ ██ █████   ██ \n");
    printf("██ ███ ██ ██      ██      ██      ██    ██ ██  ██  ██ ██         \n");
    printf(" ███ ███  ███████ ███████  ██████  ██████  ██      ██ ███████ ██ \n");
    printf("                                                                 \n");
    printf("                                                                 \n");
    printf(" ██████  ██████   ██████  ██    ██ ██████      ██████   █████    \n");
    printf("██       ██   ██ ██    ██ ██    ██ ██   ██          ██ ██   ██   \n");
    printf("██   ███ ██████  ██    ██ ██    ██ ██████       █████   █████    \n");
    printf("██    ██ ██   ██ ██    ██ ██    ██ ██          ██      ██   ██   \n");
    printf(" ██████  ██   ██  ██████   ██████  ██          ███████  █████    \n");

    main_asm(); // Jump into the ASM code
    return 0; // Application return code
}
