#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "assign02.h"
#include <time.h>

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

    printf("enter .. for level 1\n");
    printf("enter -- for level 2\n");

    //char input = readMorseString;
    main_asm(); // Jump into the ASM code
    return 0; // Application return code
}
