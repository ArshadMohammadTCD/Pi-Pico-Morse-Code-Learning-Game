#include <stdio.h>
#include <stdlib.h>
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

char * morseString;     //Declare array to store morse string in
int morseStringIndex = 0;

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
    else return ' ';
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
