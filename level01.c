#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "level01.h"

void level01 ()
{
    lifeCount = 3;
    correctInARow = 0;
    randomArrayIndex = 0;
    printf("Welcome to level 1");
    printf("Ascii characters will appear along with their morse codes. Enter the correct code to move onto next character");
    int randomIndex = rand() % 36;

    switch(randomIndex) 
        {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            case 13:
                break;
            case 14:
                break;
            case 15:
                break;
            case 16:
                break;
            case 17:
                break;
            case 18:
                break;
            case 19:
                break;
            case 20:
                break;
            case 21:
                break;
            case 22:
                break;
            case 23:
                break;
            case 24:
                break;
            case 25:
                break;
            case 26:
                break;
            case 27:
                break;
            case 28:
                break;
            case 29:
                break;
            case 30:
                break;
            case 31:
                break;
            case 32:
                break;
            case 33:
                break;
            case 34:
                break;
            case 35:
                break;
            default:
                printf("Invalid number");
        }
    
}


    // for(int i = 0; i < 36; i++)                     //Randomly shuffles the array
    // {
    //     int temp = randomNumberOrder[i];
    //     int randomIndex = rand() % 36;

    //     randomNumberOrder[i] = randomNumberOrder[randomIndex];
    //     randomNumberOrder[randomIndex] = temp;
    // }

    // while(correctInARow != 5)
    // {
    //     switch(randomNumberOrder[randomArrayIndex]) 
    //     {
    //         case 0:
                
    //             break;
    //         case 1:
    //             break;
    //         case 2:
    //             break;
    //         case 3:
    //             break;
    //         case 4:
    //             break;
    //         case 5:
    //             break;
    //         case 6:
    //             break;
    //         case 7:
    //             break;
    //         case 8:
    //             break;
    //         case 9:
    //             break;
    //         case 10:
    //             break;
    //         case 11:
    //             break;
    //         case 12:
    //             break;
    //         case 13:
    //             break;
    //         case 14:
    //             break;
    //         case 15:
    //             break;
    //         case 16:
    //             break;
    //         case 17:
    //             break;
    //         case 18:
    //             break;
    //         case 19:
    //             break;
    //         case 20:
    //             break;
    //         case 21:
    //             break;
    //         case 22:
    //             break;
    //         case 23:
    //             break;
    //         case 24:
    //             break;
    //         case 25:
    //             break;
    //         case 26:
    //             break;
    //         case 27:
    //             break;
    //         case 28:
    //             break;
    //         case 29:
    //             break;
    //         case 30:
    //             break;
    //         case 31:
    //             break;
    //         case 32:
    //             break;
    //         case 33:
    //             break;
    //         case 34:
    //             break;
    //         case 35:
    //             break;
    //         default:
    //             printf("Invalid number");
    //     }
    // }
    

void iterateRandomArrayIndex()
{
    if(randomArrayIndex < 35) randomArrayIndex++;
    else randomArrayIndex = 0;
}