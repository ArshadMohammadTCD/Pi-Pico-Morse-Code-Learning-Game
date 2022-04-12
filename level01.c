#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

char level01();
void increaseLifeCount();


char level01 ()
{
    char currChar;
    printf("Welcome to level 1");
    printf("Ascii characters will appear along with their morse codes. Enter the correct code to move onto next character");
    int randomIndex = rand() % 36;

    switch(randomIndex) 
        {
            case 0:
                currChar = 'A';
                printf("A");
                break;
            case 1:
                currChar = 'B';
                printf("B");
                break;
            case 2:
                currChar = 'C';
                printf("C");
                break;
            case 3:
                currChar = 'D';
                printf("D");
                break;
            case 4:
                currChar = 'E';
                printf("E");
                break;
            case 5:
                currChar = 'F';
                printf("F");
                break;
            case 6:
                currChar = 'G';
                printf("G");
                break;
            case 7:
                currChar = 'H';
                printf("H");
                break;
            case 8:
                currChar = 'I';
                printf("I");
                break;
            case 9:
                currChar = 'J';
                printf("J");
                break;
            case 10:
                currChar = 'K';
                printf("K");
                break;
            case 11:
                currChar = 'L';
                printf("L");
                break;
            case 12:
                currChar = 'M';
                printf("M");
                break;
            case 13:
                currChar = 'N';
                printf("N");
                break;
            case 14:
                currChar = 'O';
                printf("O");
                break;
            case 15:
                currChar = 'P';
                printf("P");
                break;
            case 16:
                currChar = 'Q';
                printf("Q");
                break;
            case 17:
                currChar = 'R';
                printf("R");
                break;
            case 18:
                currChar = 'S';
                printf("S");
                break;
            case 19:    
                currChar = 'T';
                printf("T");
                break;
            case 20:
                currChar = 'U';
                printf("U");
                break;
            case 21:
                currChar = 'V';
                printf("V");
                break;
            case 22:
                currChar = 'W';
                printf("W");
                break;
            case 23:
                currChar = 'X';
                printf("X");
                break;
            case 24:
                currChar = 'Y';
                printf("Y");
                break;
            case 25:
                currChar = 'Z';
                printf("Z");
                break;
            case 26:
                currChar = '0';
                printf("0");
                break;
            case 27:
                currChar = '1';
                printf("1");
                break;
            case 28:
                currChar = '2';
                printf("2");
                break;
            case 29:
                currChar = '3';
                printf("3");
                break;
            case 30:
                currChar = '4';
                printf("4");
                break;
            case 31:
                currChar = '5';
                printf("5");
                break;
            case 32:
                currChar = '6';
                printf("6");
                break;
            case 33:
                currChar = '7';
                printf("7");
                break;
            case 34:
                currChar = '8';
                printf("8");
                break;
            case 35:
                currChar = '9';
                printf("9");
                break;
            default:
                currChar = '?';
                printf("Invalid number");
        }
    return currChar;
}
    

