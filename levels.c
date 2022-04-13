#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

char level1and2()
{
    char currWord;
    int randomIndex = rand() % 36;

    switch(randomIndex) 
        {
            case 0:
                currWord = 'A';
                break;
            case 1:
                currWord = 'B';
                break;
            case 2:
                currWord = 'C';
                break;
            case 3:
                currWord = 'D';
                break;
            case 4:
                currWord = 'E';
                break;
            case 5:
                currWord = 'F';
                break;
            case 6:
                currWord = 'G';
                break;
            case 7:
                currWord = 'H';
                break;
            case 8:
                currWord = 'I';
                break;
            case 9:
                currWord = 'J';
                break;
            case 10:
                currWord = 'K';
                break;
            case 11:
                currWord = 'L';
                break;
            case 12:
                currWord = 'M';
                break;
            case 13:
                currWord = 'N';
                break;
            case 14:
                currWord = 'O';
                break;
            case 15:
                currWord = 'P';
                break;
            case 16:
                currWord = 'Q';
                break;
            case 17:
                currWord = 'R';
                break;
            case 18:
                currWord = 'S';
                break;
            case 19:    
                currWord = 'T';
                break;
            case 20:
                currWord = 'U';
                break;
            case 21:
                currWord = 'V';
                break;
            case 22:
                currWord = 'W';
                break;
            case 23:
                currWord = 'X';
                break;
            case 24:
                currWord = 'Y';
                break;
            case 25:
                currWord = 'Z';
                break;
            case 26:
                currWord = '0';
                break;
            case 27:
                currWord = '1';
                break;
            case 28:
                currWord = '2';
                break;
            case 29:
                currWord = '3';
                break;
            case 30:
                currWord = '4';
                break;
            case 31:
                currWord = '5';
                break;
            case 32:
                currWord = '6';
                break;
            case 33:
                currWord = '7';
                break;
            case 34:
                currWord = '8';
                break;
            case 35:
                currWord = '9';
                break;
            default:
                currWord = '?';
                printf("Invalid number");
        }
    printf("The next character is %c\n", currWord);
    return currWord;
}

char * level3and4()
{
    char * currWord;
    int randomIndex = rand() % 40;

    switch(randomIndex) 
        {
            case 0:
                currWord = 'GORILLA';
                break;
            case 1:
                currWord = 'SPINNER';
                break;
            case 2:
                currWord = 'RODENT';
                break;
            case 3:
                currWord = 'MOTHER';
                break;
            case 4:
                currWord = 'HOUSE';
                break;
            case 5:
                currWord = 'BADMINTON';
                break;
            case 6:
                currWord = 'LEAGUE';
                break;
            case 7:
                currWord = 'ALARM';
                break;
            case 8:
                currWord = 'PARK';
                break;
            case 9:
                currWord = 'RUN';
                break;
            case 10:
                currWord = 'SIT';
                break;
            case 11:
                currWord = 'CHAIR';
                break;
            case 12:
                currWord = 'PICO';
                break;
            case 13:
                currWord = 'PI';
                break;
            case 14:
                currWord = 'MICROPROCESSOR';
                break;
            case 15:
                currWord = 'DISCORD';
                break;
            case 16:
                currWord = 'VSCODE';
                break;
            case 17:
                currWord = 'LIFTING';
                break;
            case 18:
                currWord = 'SQUAT';
                break;
            case 19:    
                currWord = 'DEADLIFT';
                break;
            case 20:
                currWord = 'DOG';
                break;
            case 21:
                currWord = 'CAT';
                break;
            case 22:
                currWord = 'FISH';
                break;
            case 23:
                currWord = 'BROTHER';
                break;
            case 24:
                currWord = 'DAD';
                break;
            case 25:
                currWord = 'IRELAND';
                break;
            case 26:
                currWord = 'TRINITY';
                break;
            case 27:
                currWord = 'JAMIE';
                break;
            case 28:
                currWord = 'TOM';
                break;
            case 29:
                currWord = 'ARSHAD';
                break;
            case 30:
                currWord = 'AMMAR';
                break;
            case 31:
                currWord = 'KEVIN';
                break;
            case 32:
                currWord = 'COLLEGE';
                break;
            case 33:
                currWord = 'COW';
                break;
            case 34:
                currWord = 'POT';
                break;
            case 35:
                currWord = 'CLAY';
                break;
            case 36:
                currWord = 'PC';
                break;
            case 37:
                currWord = 'MOUSE';
                break;
            case 38:
                currWord = 'MONKEY';
                break;
            case 39:
                currWord = 'JOSH';
                break;
            default:
                currWord = '?';
                printf("Invalid number");
        }
    printf("The next character is %c\n", currWord);
    return currWord;
}



    

