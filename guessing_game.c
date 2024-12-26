#include <stdio.h>

#include "guessing_game.h"

#include "rng.h"

void guessing_game(void)
{
    double low, high, random_number, guess, low_quarter, high_quarter;
    int count, original_count;

    printf("\n\n** Guessing Game **\n\n");
    printf("Enter the lowest the number can be: ");
    scanf(" %lf", &low);
    printf("Enter the highest the number can be: ");
    scanf(" %lf", &high);
    printf("Enter the amount of tries you want: ");
    scanf(" %d", &count);

    random_number = generate_random_number(low, high);

    original_count = count;
    low_quarter = random_number / 2;
    high_quarter = random_number * 1.5;

    while (count != 0)
    {
        printf("\nEnter your guess: ");
        scanf(" %lf", &guess);

        if (guess <= low_quarter) {
            printf("\nWay to low.");
        } else if (guess < random_number && guess > low_quarter) {
            printf("\nToo low.");
        } else if (guess > random_number && guess < high_quarter) {
            printf("\nToo high.");
        } else if (guess >= high_quarter) {
            printf("\nWay to high.");
        } else if (guess == random_number) {
            printf("You won in %d guesses!", original_count - count + 1);
            return;
        }
        count--;
        printf("\nYou have %d guesses left.", count);
    }

    printf("\n\nYou lost. The answer was %lf.", random_number);

    printf("\n\n");
}