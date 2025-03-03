// RNG related functions.
// Includes a standard random number generator that can also
// Generate numbers in hexadecimal and octal.
// Also contains a generic random number generator than can be called
// by other functions in other files such as guessing_game.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "rng.h"

void rng(void)
{
    long int large, small, amount;
    int command;

    printf("\n\n** Random Number Generator **\n");
    printf("Press 1 to generate integer(s)\nPress 2 to generate hexadecimal\nPress 3 to generate octal\nPress 0 to exit\n");
    while (1)
    {
        printf("Enter your choice: ");
        scanf(" %d", &command);
        if (command == 1 || command == 2 || command == 3 || command == 0)
        {
            break;
        }
        printf("\nInvalid input. ");
    }
    
    printf("\nEnter the lowest number: ");
    scanf(" %ld", &small);
    printf("\nEnter the largest number: ");
    scanf(" %ld", &large);
    printf("\nEnter the amount of numbers to generate: ");
    scanf(" %ld", &amount);

    if (amount <= 0)
    {
        printf("\nThere must be at least one number to generate.");
        return;
    }

    srand(time(NULL));

    if (amount > 1)
    {
        printf("The random numbers are:\n");
    }
    else if (amount == 1)
    {
        printf("The random number is:\n");
    }

    for (int i = 0; i < amount; i++)
    {
        long int num = (rand() % (large - small + 1)) + small;
        switch (command)
        {
            case 1:
                printf("%ld ", num);
                break;
            case 2:
                printf("%lx ", num);
                break;
            case 3:
                printf("%lo ", num);
                break;
            default:
                break;
        }
        
    }
}

// RNG that returns an int from two doubles

double generate_random_number(double min, double max)
{
    static int seeded = 0;

    if (!seeded)
    {
        srand(time(NULL) ^ getpid());
        seeded = 1;
    }

    return (rand() % (int)(max - min + 1)) + (int)min;
}

// same thing as above but requires two ints rather than doubles

int generate_random_number2(int min, int max)
{
    static int seeded = 0;

    if (!seeded)
    {
        srand(time(NULL) ^ getpid());
        seeded = 1;
    }

    return (rand() % (int)(max - min + 1)) + (int)min;
}
