#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

char level1and2()
{
    char currChar;
    int randomIndex = rand() % 36;

    switch(randomIndex) 
        {
            case 0:
                currChar = 'A';
                break;
            case 1:
                currChar = 'B';
                break;
            case 2:
                currChar = 'C';
                break;
            case 3:
                currChar = 'D';
                break;
            case 4:
                currChar = 'E';
                break;
            case 5:
                currChar = 'F';
                break;
            case 6:
                currChar = 'G';
                break;
            case 7:
                currChar = 'H';
                break;
            case 8:
                currChar = 'I';
                break;
            case 9:
                currChar = 'J';
                break;
            case 10:
                currChar = 'K';
                break;
            case 11:
                currChar = 'L';
                break;
            case 12:
                currChar = 'M';
                break;
            case 13:
                currChar = 'N';
                break;
            case 14:
                currChar = 'O';
                break;
            case 15:
                currChar = 'P';
                break;
            case 16:
                currChar = 'Q';
                break;
            case 17:
                currChar = 'R';
                break;
            case 18:
                currChar = 'S';
                break;
            case 19:    
                currChar = 'T';
                break;
            case 20:
                currChar = 'U';
                break;
            case 21:
                currChar = 'V';
                break;
            case 22:
                currChar = 'W';
                break;
            case 23:
                currChar = 'X';
                break;
            case 24:
                currChar = 'Y';
                break;
            case 25:
                currChar = 'Z';
                break;
            case 26:
                currChar = '0';
                break;
            case 27:
                currChar = '1';
                break;
            case 28:
                currChar = '2';
                break;
            case 29:
                currChar = '3';
                break;
            case 30:
                currChar = '4';
                break;
            case 31:
                currChar = '5';
                break;
            case 32:
                currChar = '6';
                break;
            case 33:
                currChar = '7';
                break;
            case 34:
                currChar = '8';
                break;
            case 35:
                currChar = '9';
                break;
            default:
                currChar = '?';
                printf("Invalid number");
        }
    printf("The next character is %c\n", currChar);
    return currChar;
}


    

