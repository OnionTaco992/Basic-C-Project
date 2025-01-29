// Converts temperatures. Quite self explanitory
// I don't think there is really anything else to add here
// Except maybe some code optimisations (if there are even any to be made)

#include <stdio.h>

#include "temperature_conversion.h"

#define MAX_ARRAY_LIMIT 100

void temp_convert(void)
{
    double temps[MAX_ARRAY_LIMIT], conversion;
    int command, i;
    char ch;

    printf("\n\n** Temperature Converter **");
    printf("\n\nPress 1 to convert celsius\nPress 2 to convert fahrenheit\nPress 3 to convert kelvin\nPress 0 to exit\n\n");

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

    printf("Enter a list of temperatures (or just one).\nThere can be up to %d temperatures in the list\nPress 't' to end the list\nEnter the temperatures:\n");

    for (i = 0; i < MAX_ARRAY_LIMIT; i++)
    {
        if (scanf("%lf", &temps[i]) != 1)
        {
            if (scanf("%c", &ch) == 1 && (ch == 't' || ch == 'T'))
            {
                break;
            }
            else
            {
                printf("Invalid input. Enter either a number or t to exit: ");
                i--;
                continue;
            }
        }
    }

    switch (command)
    {
        case 1:
            celsius(temps, i);
            break;
        case 2:
            fahrenheit(temps, i);
            break;
        case 3:
            kelvin(temps, i);
            break;
        case 0:
            break;
        default:
            break;
    }
}

void celsius(double array[MAX_ARRAY_LIMIT], int array_size) // Converts celsius to fahrenheit and kelvin
{
    int i;
    double conversion;

    printf("\n* Fahrenheit *\n");
    for (i = 0; i < array_size; i++) {
        conversion = (array[i] * 9 / 5) + 32; 
        printf("\nIndex %d: %.2lf = %.2lf", i + 1, array[i], conversion);
    }

    printf("\n\n* Kelvin *\n");
    for (i = 0; i < array_size; i++) {
        conversion = array[i] + 273.15; 
        printf("\nIndex %d: %.2lf = %.2lf", i + 1, array[i], conversion);
    }
}

void fahrenheit(double array[MAX_ARRAY_LIMIT], int array_size) // Converts fahrenheit to celsius and kelvin
{
    int i;
    double conversion;

    printf("\n* Celsius *\n");
    for (i = 0; i < array_size; i++) {
        conversion = (array[i] - 32) * 9 / 5; 
        printf("\nIndex %d: %.2lf = %.2lf", i + 1, array[i], conversion);
    }

    printf("\n\n* Kelvin *\n");
    for (i = 0; i < array_size; i++) {
        conversion = (array[i] - 32) * 9 / 5 + 273.15; 
        printf("\nIndex %d: %.2lf = %.2lf", i + 1, array[i], conversion);
    }
}

void kelvin(double array[MAX_ARRAY_LIMIT], int array_size) // Converts kelvin to celsius and fahrenheit
{
    int i;
    double conversion;

    printf("\n* Celsius *\n");
    for (i = 0; i < array_size; i++) {
        conversion = array[i] - 273.15; 
        printf("\nIndex %d: %.2lf = %.2lf", i + 1, array[i], conversion);
    }

    printf("\n\n* Fahrenheit *\n");
    for (i = 0; i < array_size; i++) {
        conversion = (array[i] - 273.15) * 9 /5 + 32; 
        printf("\nIndex %d: %.2lf = %.2lf", i + 1, array[i], conversion);
    }
}