#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "assign02.h"


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
