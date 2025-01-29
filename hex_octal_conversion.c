// Converter that can convert integers to hexadecimal and octal
// hexadecimal to integers and octal
// and octal to integers and hexadecimal

#include <stdio.h>
#include <math.h>

#include "hex_octal_conversion.h"

#define MAX_ARRAY_LIMIT 100

void hex_octal_conv(void)
{
    int command, i, j, n;
    double list[MAX_ARRAY_LIMIT], high = -INFINITY;
    char ch;

    printf("Press 1 to convert integers to hex/octal\nPress 2 to convert hex to integers/octal\nPress 3 to convert octal to integers/hex\nPress 0 to exit\nEnter a number: ");

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

    printf("\n\nEnter a set of numbers, up to %d numbers\nPress t to finish list\nEnter the list: ", MAX_ARRAY_LIMIT);
    for (i = 0; i < MAX_ARRAY_LIMIT; i++)
    {
        if (scanf("%lf", &list[i]) != 1)
        {
            if (scanf(" %c", &ch) == 1 && (ch == 't' || ch == 'T'))
            {
                break;
            }
            else
            {
                printf("Invalid input. Enter either a number or 't' to exit: ");
                i--;
                continue;
            }
        }
    }

    switch (command)
    {
    case 1:
        integer_to_hex_octal(list, i);
        break;
    case 2:
        hex_to_integer_octal(list, i);
        break;
    case 3:
        octal_to_integer_hex(list, i);
        break;
    case 0:
        return;
        break;
    default:
        break;
    }
}

void integer_to_hex_octal(double list[], int j)
{
    int i;

    printf("\n\n** Integer conversion **\nConverts integers to\nHexadecimal and Octal");

    printf("\n\nHexadecimal conversion:\n");

    for (i = 0; i < j; i++)
    {
        printf("\nIndex %3d: %.0lf = %x ", i + 1, list[i], (int)list[i]);
    }

    printf("\n\nOctal conversion:\n");

    for (i = 0; i < j; i++)
    {
        printf("\nIndex %3d: %.0lf = %o ", i + 1, list[i], (int)list[i]);
    }

    printf("\n\n");
}

void hex_to_integer_octal(double list[], int j)
{
    int i;

    printf("\n\n** Hex conversion **\nConverts hexadecimal to\nintegers and Octal");

    printf("\n\nInteger conversion:\n");

    for (i = 0; i < j; i++)
    {
        printf("\nIndex %3d: %x = %.0lf ", i + 1, (int)list[i], list[i]);
    }

    printf("\n\nOctal conversion:\n");

    for (i = 0; i < j; i++)
    {
        printf("\nIndex %3d: %x = %o ", i + 1, (int)list[i], (int)list[i]);
    }

    printf("\n\n");
}

void octal_to_integer_hex(double list[], int j)
{
    int i;

    printf("\n\n** Octal conversion **\nConverts Octal to\nintegers and hexadecimal");

    printf("\n\nInteger conversion:\n");

    for (i = 0; i < j; i++)
    {
        printf("\nIndex %3d: %o = %.0lf ", i + 1, (int)list[i], list[i]);
    }

    printf("\n\nHexadecimal conversion:\n");

    for (i = 0; i < j; i++)
    {
        printf("\nIndex %3d: %o = %x ", i + 1, (int)list[i], (int)list[i]);
    }

    printf("\n\n");
}