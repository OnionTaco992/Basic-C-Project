// Functions related to powers/exponents such as multiplying numbers by an exponent
// Or finding a certain index/root of a number
// Might add more to this at some point, but probably not for a while.

#include <stdio.h>
#include <math.h>

#include "powers_and_exponents.h"

void power_actions(void)
{
    double number;
    int i, command;

    printf("\n** Powers **\nPress 1 to calculate exponents\nPress 2 to calculate roots\nPress 0 to exit.\n");

    while (1) // keeps repeating until a valid input is entered, avoiding the use of goto;
    {
        printf("Enter your choice: ");
        scanf(" %d", &command);
        if (command == 1 || command == 2 || command == 0)
        {
            break;
        }
        printf("\nInvalid input.");
    }

    switch (command)
    {
    case 1:
        exponential_math();
        break;
    case 2:
        root_math();
        break;
    default:
        break; // this shouldn't even be able to be triggered due to the while loop that checks for a valid input
    }

}

void exponential_math(void)
{
    double input_number, sum;
    int exponent, i;

    printf("\n** Exponential **\nEnter the number you want to multiply: ");
    scanf(" %lf", &input_number);
    printf("\nEnter the exponent: ");
    scanf(" %d", &exponent);

    sum = pow(input_number, exponent);

    printf("%.2lf to the power of %d = %.2lf", input_number, exponent, sum);
}

void root_math(void)
{
    double input_number, sum;
    int index, i;

    printf("\n** Root **\nEnter the number you want to find the root of: ");
    scanf(" %lf", &input_number);
    printf("\nEnter the index/degree: ");
    scanf(" %d", &index);

    if (index == 1)
    {
        printf("\nIndexing a number by 1 does nothing.");
        return;
    }

    sum = pow(input_number, 1.0 / index);

    switch (index)
    {
    case 2:
        printf("\nThe square root of %.2lf is %.2lf.", input_number, sum); // if the index is either 2 or 3 it will just display as either squared root or cubed root rather than saying the specific index
        break;
    case 3:
        printf("\nThe cubed root of %.2lf is %.2lf.", input_number, sum);
        break;
    default:
        printf("\nThe %dth index of %.2lf is %.2lf.", index, input_number, sum);
        break;
    }
}