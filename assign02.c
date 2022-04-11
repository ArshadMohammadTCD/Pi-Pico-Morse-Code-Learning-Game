#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define A ".-"
#define B "-.."
#define C "-.-."
#define D "-.."
#define E "."
#define F "..-."
#define G "--."
#define H "...."
#define I ".."
#define J ".---"
#define K "-.-"
#define L ".-.."
#define M "--"
#define N "-."
#define O "---"
#define P ".--."
#define Q "--.-"
#define R ".-."
#define S "..."
#define T "-"
#define U "..-"
#define V "...-"
#define W ".--"
#define X "-..-"
#define Y "-.--"
#define Z "--.."

typedef struct {
    char AsciiChar;
    char * morseRepresentation;
    int morseLength;
} morseChar;

// morseChar newChar (char AsciiChar, char * morseRepresentation, int length)
// {   
//     morseChar character;

//     character.AsciiChar = AsciiChar;
//     character.morseRepresentation = morseRepresentation;
//     character.morseLength = length;
// }

const morseChar a = {65, A, 3};
const morseChar b = {66, B, 5};
const morseChar c = {67, C, 5};
const morseChar d = {68, D, 4};
const morseChar e = {69, E, 2};
const morseChar f = {70, F, 5};
const morseChar g = {71, G, 4};
const morseChar h = {72, H, 5};
const morseChar i = {73, I, 3};
const morseChar j = {74, J, 5};
const morseChar k = {75, K, 4};
const morseChar l = {76, L, 5};
const morseChar m = {77, M, 3};
const morseChar n = {78, N, 3};
const morseChar o = {79, O, 4};
const morseChar p = {80, P, 5};
const morseChar q = {81, Q, 5};
const morseChar r = {82, R, 4};
const morseChar s = {83, S, 4};
const morseChar t = {84, T, 2};
const morseChar u = {85, U, 4};
const morseChar v = {86, V, 5};
const morseChar w = {87, W, 4};
const morseChar x = {88, X, 5};
const morseChar y = {89, Y, 5};
const morseChar z = {90, Z, 5};

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

bool compareMorseStruct(char * inputMorse, int inputLength, char * patternMorse, int patternLength)
{
    if(inputLength != patternLength) return false;
    for(int i = 0; i < inputLength; i++)
    {
        if(inputMorse[i] != patternMorse[i]) return false;
    }   
    return true;
}

char readMorseString(char * morseString)
{
    char currChar = morseString[0];
    int length = 0;
    for(int i = 0; currChar != '\0'; i++)
    {
        currChar = morseString[i];
        length++;
    }
    length++;

    compareMorseStruct(morseString, length, A, a.morseLength);
    compareMorseStruct(morseString, length, B, b.morseLength);
    compareMorseStruct(morseString, length, C, c.morseLength);
    compareMorseStruct(morseString, length, D, d.morseLength);
    compareMorseStruct(morseString, length, E, e.morseLength);
    compareMorseStruct(morseString, length, F, f.morseLength);
    compareMorseStruct(morseString, length, G, g.morseLength);
    compareMorseStruct(morseString, length, H, h.morseLength);
    compareMorseStruct(morseString, length, I, i.morseLength);
    compareMorseStruct(morseString, length, J, j.morseLength);
    compareMorseStruct(morseString, length, K, k.morseLength);
    compareMorseStruct(morseString, length, L, l.morseLength);
    compareMorseStruct(morseString, length, M, m.morseLength);
    compareMorseStruct(morseString, length, N, n.morseLength);
    compareMorseStruct(morseString, length, O, o.morseLength);
    compareMorseStruct(morseString, length, P, p.morseLength);
    compareMorseStruct(morseString, length, Q, q.morseLength);
    compareMorseStruct(morseString, length, R, r.morseLength);
    compareMorseStruct(morseString, length, S, s.morseLength);
    compareMorseStruct(morseString, length, T, t.morseLength);
    compareMorseStruct(morseString, length, U, u.morseLength);
    compareMorseStruct(morseString, length, V, v.morseLength);
    compareMorseStruct(morseString, length, W, w.morseLength);
    compareMorseStruct(morseString, length, X, x.morseLength);
    compareMorseStruct(morseString, length, Y, y.morseLength);
    compareMorseStruct(morseString, length, Z, z.morseLength);
    return ' ';
}

// Main entry point of the application
int main() {
    

    stdio_init_all(); // Initialise all basic IO

    printf("%i", a.morseLength);
 
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
