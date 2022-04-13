#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pio.h"
#include "assign02.h"
#include <time.h>
#include "ws2812.pio.h"
#include "hardware/watchdog.h"

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

//Loads the watchdog timer again after the specified time has passed
void watchdog_update_asm(){
    watchdog_update();
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
    else if (color == 3) put_pixel(urgb_u32(0x00, 0x7F, 0x00)); // green
    else if (color == 4) put_pixel(urgb_u32(0x00, 0x00, 0x7F)); // blue
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

void clearMorseString()
{
    for(int i = 0; i < 50; i++)
    {
        morseString[i] = 0;
    }
    morseStringIndex = 0;
}

void changeLifeCount(bool upOrDown)
{
    if(upOrDown)
    {
        if(lifeCount < 3) lifeCount++;
    }
    else 
    {
        if(lifeCount > 0) lifeCount--;
    }
    
    if(lifeCount == 3) set_led_color(3);
    else if(lifeCount == 2) set_led_color(2);
    else set_led_color(1);
}

char * findMorseCode()
{
    if(a.AsciiChar == currentCharacter) return A;
    else if(b.AsciiChar == currentCharacter) return B;
    else if(c.AsciiChar == currentCharacter) return C;
    else if(d.AsciiChar == currentCharacter) return D;
    else if(e.AsciiChar == currentCharacter) return E;
    else if(f.AsciiChar == currentCharacter) return F;
    else if(g.AsciiChar == currentCharacter) return G;
    else if(h.AsciiChar == currentCharacter) return H;
    else if(i.AsciiChar == currentCharacter) return I;
    else if(j.AsciiChar == currentCharacter) return J;
    else if(k.AsciiChar == currentCharacter) return K;
    else if(l.AsciiChar == currentCharacter) return L;
    else if(m.AsciiChar == currentCharacter) return M;
    else if(n.AsciiChar == currentCharacter) return N;
    else if(o.AsciiChar == currentCharacter) return O;
    else if(p.AsciiChar == currentCharacter) return P;
    else if(q.AsciiChar == currentCharacter) return Q;
    else if(r.AsciiChar == currentCharacter) return R;
    else if(s.AsciiChar == currentCharacter) return S;
    else if(t.AsciiChar == currentCharacter) return T;
    else if(u.AsciiChar == currentCharacter) return U;
    else if(v.AsciiChar == currentCharacter) return V;
    else if(w.AsciiChar == currentCharacter) return W;
    else if(x.AsciiChar == currentCharacter) return X;
    else if(y.AsciiChar == currentCharacter) return Y;
    else if(z.AsciiChar == currentCharacter) return Z;

    else if(zero.AsciiChar == currentCharacter) return ZERO;
    else if(one.AsciiChar == currentCharacter) return ONE;
    else if(two.AsciiChar == currentCharacter) return TWO;
    else if(three.AsciiChar == currentCharacter) return THREE;
    else if(four.AsciiChar == currentCharacter) return FOUR;
    else if(five.AsciiChar == currentCharacter) return FIVE;
    else if(six.AsciiChar == currentCharacter) return SIX;
    else if(seven.AsciiChar == currentCharacter) return SEVEN;
    else if(eight.AsciiChar == currentCharacter) return EIGHT;
    else if(nine.AsciiChar == currentCharacter) return NINE;
    else return "?";
}

//This function checks what character the input morse string represents, and returns that character if there is a match. Else it returns the space character
void readMorseString()
{
    watchdog_enable(0x2328, 1);

    printf("\n\n");               //skip line from morse adding
    char currChar = morseString[0];
    int length = 0;
    for(int i = 0; currChar != '\0'; i++)
    {
        currChar = morseString[i];
        length++;
    }
    
    if(compareMorseStruct(morseString, length, A, a.morseLength)) currChar = a.AsciiChar;
    else if(compareMorseStruct(morseString, length, B, b.morseLength)) currChar = b.AsciiChar;
    else if(compareMorseStruct(morseString, length, C, c.morseLength)) currChar = c.AsciiChar;
    else if(compareMorseStruct(morseString, length, D, d.morseLength)) currChar = d.AsciiChar;
    else if(compareMorseStruct(morseString, length, E, e.morseLength)) currChar = e.AsciiChar;
    else if(compareMorseStruct(morseString, length, F, f.morseLength)) currChar = f.AsciiChar;
    else if(compareMorseStruct(morseString, length, G, g.morseLength)) currChar = g.AsciiChar;
    else if(compareMorseStruct(morseString, length, H, h.morseLength)) currChar = h.AsciiChar;
    else if(compareMorseStruct(morseString, length, I, i.morseLength)) currChar = i.AsciiChar;
    else if(compareMorseStruct(morseString, length, J, j.morseLength)) currChar = j.AsciiChar;
    else if(compareMorseStruct(morseString, length, K, k.morseLength)) currChar = k.AsciiChar;
    else if(compareMorseStruct(morseString, length, L, l.morseLength)) currChar = l.AsciiChar;
    else if(compareMorseStruct(morseString, length, M, m.morseLength)) currChar = m.AsciiChar;
    else if(compareMorseStruct(morseString, length, N, n.morseLength)) currChar = n.AsciiChar;
    else if(compareMorseStruct(morseString, length, O, o.morseLength)) currChar = o.AsciiChar;
    else if(compareMorseStruct(morseString, length, P, p.morseLength)) currChar = p.AsciiChar;
    else if(compareMorseStruct(morseString, length, Q, q.morseLength)) currChar = q.AsciiChar;
    else if(compareMorseStruct(morseString, length, R, r.morseLength)) currChar = r.AsciiChar;
    else if(compareMorseStruct(morseString, length, S, s.morseLength)) currChar = s.AsciiChar;
    else if(compareMorseStruct(morseString, length, T, t.morseLength)) currChar = t.AsciiChar;
    else if(compareMorseStruct(morseString, length, U, u.morseLength)) currChar = u.AsciiChar;
    else if(compareMorseStruct(morseString, length, V, v.morseLength)) currChar = v.AsciiChar;
    else if(compareMorseStruct(morseString, length, W, w.morseLength)) currChar = w.AsciiChar;
    else if(compareMorseStruct(morseString, length, X, x.morseLength)) currChar = x.AsciiChar;
    else if(compareMorseStruct(morseString, length, Y, y.morseLength)) currChar = y.AsciiChar;
    else if(compareMorseStruct(morseString, length, Z, z.morseLength)) currChar = z.AsciiChar;

    else if(compareMorseStruct(morseString, length, ZERO, zero.morseLength)) currChar = zero.AsciiChar;
    else if(compareMorseStruct(morseString, length, ONE, one.morseLength)) currChar = one.AsciiChar;
    else if(compareMorseStruct(morseString, length, TWO, two.morseLength)) currChar = two.AsciiChar;
    else if(compareMorseStruct(morseString, length, THREE, three.morseLength)) currChar = three.AsciiChar;
    else if(compareMorseStruct(morseString, length, FOUR, four.morseLength)) currChar = four.AsciiChar;
    else if(compareMorseStruct(morseString, length, FIVE, five.morseLength)) currChar = five.AsciiChar;
    else if(compareMorseStruct(morseString, length, SIX, six.morseLength)) currChar = six.AsciiChar;
    else if(compareMorseStruct(morseString, length, SEVEN, seven.morseLength)) currChar = seven.AsciiChar;
    else if(compareMorseStruct(morseString, length, EIGHT, eight.morseLength)) currChar = eight.AsciiChar;
    else if(compareMorseStruct(morseString, length, NINE, nine.morseLength)) currChar = nine.AsciiChar;
    else currChar = '?';

    printf("You entered %c\n", currChar);

    if(currentLevel == 0) 
    {
        if(currChar == '1') 
        {
            questionsCorrect = 0;
            questionsIncorrect = 0;
            set_led_color(3);
            printf("Welcome to level 1\n");
            printf("Ascii characters will appear along with their morse codes. Enter the correct code to move onto next character\n");
            currentLevel = 1;
            lifeCount = 3;
            currentCharacter = level1and2();
            char * morseRepresentation = findMorseCode();
            printf("Its morse code represenation is %s\n\n", morseRepresentation);
        }
        else if(currChar == '2')
        {
            questionsCorrect = 0;
            questionsIncorrect = 0;
            set_led_color(3);
            printf("Welcome to level 2\n");
            printf("Ascii characters will appear without their morse codes. Enter the correct code to move onto next character\n");
            currentLevel = 2;
            lifeCount = 3;
            currentCharacter = level1and2();
        }
        else printf("wrong input\n");
    }
    else
    {
        if(currentCharacter == currChar)
        {
            questionsCorrect++;
            correctInARow++;
            printf("Correct! Current win streak: %i\n", correctInARow);
            if(correctInARow == 5)
            {
                correctInARow = 0;
                if(currentLevel == 1) 
                {
                    currentLevel = 2;
                    printf("Level 1 complete!\n");
                    printf("Correct answers: %i\n", questionsCorrect);
                    printf("Incorrect answers: %i\n", questionsIncorrect);
                    correctPercentage = ((float) questionsCorrect / ( (float) questionsCorrect + (float) questionsIncorrect)) * 100.0;
                    printf("Percentage correct: %%%i\n", (int) correctPercentage);
                    questionsCorrect = 0;
                    questionsIncorrect = 0;
                }
                else if(currentLevel == 2) 
                {
                    printf("You Win!");
                    printf("Correct answers: %i\n", questionsCorrect);
                    printf("Incorrect answers: %i\n", questionsIncorrect);
                    correctPercentage = ((float) questionsCorrect / ( (float) questionsCorrect + (float) questionsIncorrect)) * 100.0;
                    printf("Percentage correct: %%%i", (int) correctPercentage);
                    questionsCorrect = 0;
                    questionsIncorrect = 0;
                }
            }
            changeLifeCount(1);
            if(currentLevel == 1) 
            {
                currentCharacter = level1and2();
                char * morseRepresentation = findMorseCode();
                printf("Its morse code represenation is %s\n\n", morseRepresentation);
            }
            else if (currentLevel == 2) 
            {
                currentCharacter = level1and2();
            }
        }
        else 
        {
            questionsIncorrect++;
            changeLifeCount(0);
            correctInARow = 0;
            if(lifeCount == 0) 
            {
                printf("You Lost!\n");
                printf("Correct answers: %i\n", questionsCorrect);
                printf("Incorrect answers: %i\n", questionsIncorrect);
                correctPercentage = ((float) questionsCorrect / ( (float) questionsCorrect + (float) questionsIncorrect)) * 100.0;
                printf("Percentage correct: %%%i", (int) correctPercentage);
                questionsCorrect = 0;
                questionsIncorrect = 0;
            }
            else if(lifeCount == 1) printf("Wrong! You lost a life! You have %i life remaining\n", lifeCount);
            else printf("Wrong! You lost a life! You have %i lives remaining\n", lifeCount);
        }
    }
    clearMorseString();
}

// Main entry point of the application
int main() {
    srand ( time(NULL) );
    currentLevel = 0;
    morseString = calloc(50, sizeof(char));
    stdio_init_all(); // Initialise all basic IO

    //Resets the game if 9 seconds pass
    if (watchdog_caused_reboot()) {
        printf("Time out! Game has been reset\n\n");
    }

    // Initialise the PIO interface with the WS2812 code
    PIO pio = pio0;
    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, 0, offset, WS2812_PIN, 800000, IS_RGBW);

    set_led_color(4);           //set LED to blue
 
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
    printf("\nHow to Play:\n");
    printf("You will be presented with an alphanumeric character (A-Z/0-9)\n");
	printf("Enter the correct equivalent Morse Code sequence to progress!\n");
	printf("Choose a Level:\n");
	printf(".---- Level 1: Morse Code equivalent shown\n");
	printf("..--- Level 2: Morse Code equivalent not shown\n\n");

    //char input = readMorseString;
    main_asm(); // Jump into the ASM code
    return 0; // Application return code
}
