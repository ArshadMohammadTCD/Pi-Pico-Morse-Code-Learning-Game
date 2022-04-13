#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pio.h"
#include "assign02.h"
#include <time.h>
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

void clearMorseString()
{
    for(int i = 0; i < 50; i++)
    {
        morseString[i] = 0;
    }
    morseStringIndex = 0;
}

void increaseLifeCount()
{
    if(lifeCount < 3) lifeCount++;
}

char * findMorseCode()
{
    if(a.AsciiChar == currentCharacter) return A;
    if(b.AsciiChar == currentCharacter) return B;
    if(c.AsciiChar == currentCharacter) return C;
    if(d.AsciiChar == currentCharacter) return D;
    if(e.AsciiChar == currentCharacter) return E;
    if(f.AsciiChar == currentCharacter) return F;
    if(g.AsciiChar == currentCharacter) return G;
    if(h.AsciiChar == currentCharacter) return H;
    if(i.AsciiChar == currentCharacter) return I;
    if(j.AsciiChar == currentCharacter) return J;
    if(k.AsciiChar == currentCharacter) return K;
    if(l.AsciiChar == currentCharacter) return L;
    if(m.AsciiChar == currentCharacter) return M;
    if(n.AsciiChar == currentCharacter) return N;
    if(o.AsciiChar == currentCharacter) return O;
    if(p.AsciiChar == currentCharacter) return P;
    if(q.AsciiChar == currentCharacter) return Q;
    if(r.AsciiChar == currentCharacter) return R;
    if(s.AsciiChar == currentCharacter) return S;
    if(t.AsciiChar == currentCharacter) return T;
    if(u.AsciiChar == currentCharacter) return U;
    if(v.AsciiChar == currentCharacter) return V;
    if(w.AsciiChar == currentCharacter) return W;
    if(x.AsciiChar == currentCharacter) return X;
    if(y.AsciiChar == currentCharacter) return Y;
    if(z.AsciiChar == currentCharacter) return Z;

    if(zero.AsciiChar == currentCharacter) return ZERO;
    if(one.AsciiChar == currentCharacter) return ONE;
    if(two.AsciiChar == currentCharacter) return TWO;
    if(three.AsciiChar == currentCharacter) return THREE;
    if(four.AsciiChar == currentCharacter) return FOUR;
    if(five.AsciiChar == currentCharacter) return FIVE;
    if(six.AsciiChar == currentCharacter) return SIX;
    if(seven.AsciiChar == currentCharacter) return SEVEN;
    if(eight.AsciiChar == currentCharacter) return EIGHT;
    if(nine.AsciiChar == currentCharacter) return NINE;
}

//This function checks what character the input morse string represents, and returns that character if there is a match. Else it returns the space character
void readMorseString()
{
    printf("\n");               //skip line from morse adding
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
        if(currChar == 'E') 
        {
            currentLevel = 1;
            lifeCount = 3;
            currentCharacter = level01();
        }
        else if(currChar == '2')
        {
            currentLevel = 2;
            lifeCount = 3;
            currentCharacter = level02();
        }
        else printf("wrong input");
    }
    else
    {
        if(currentCharacter == currChar)
        {
            correctInARow++;
            printf("Correct! Current win streak: %i\n", correctInARow);
            if(correctInARow == 5)
            {
                correctInARow = 0;
                if(currentLevel == 1) currentLevel = 2;
                if(currentLevel == 2) printf("You Win!");
            }
            increaseLifeCount();
            printf("%i\n", correctInARow);
            if(currentLevel == 1) currentCharacter = level01();
            else if (currentLevel == 2) currentCharacter = level02();
        }
        else 
        {
            lifeCount--;
            correctInARow = 0;
            if(lifeCount == 0) printf("You Lost!");
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
    printf("\nHow to Play:\n");
    printf("You will be presented with an alphanumeric character (A-Z/0-9)\n");
	printf("Enter the correct equivalent Morse Code sequence to progress!\n");
	printf("Choose a Level:\n");
	printf("Level 1: Morse Code equivalent shown\n");
	printf("Level 2: Morse Code equivalent not shown\n");
    printf("Enter .. for Level 1\n");
    printf("Enter -- for Level 2\n");

    //char input = readMorseString;
    main_asm(); // Jump into the ASM code
    return 0; // Application return code
}
