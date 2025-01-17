// TODO find some way to optimise this code

#include <stdio.h>

#include "length_conversion.h"

void convert_choice(void)
{
    int type, command;

    printf("Press 1 for metric\nPress 2 for imperial\nPress 0 to exit\n\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf(" %d", &command);
        if (command == 1 || command == 2 || command == 0)
        {
            break;
        }
        printf("\nInvalid input. ");
    }

    switch (type)
    {
        case 1:
            metric_conv();
            break;
        case 2:

            break;
        case 0:
            return;
            break;
        default:
            break;
    }
}

void metric_conv(void)
{
    double number;
    char unit[2], unit2[2], temp;
    int i;

    printf("\n\nEnter the number followed by the unit: ");
    scanf("%lf", &number);

    while (1)
    {
        scanf("%c", &temp);
        if (temp != '\n')
        {
            break;
        }
        unit[i] = temp;
        i++;
    }

    printf("\n\nEnter the unit to convert to: ");

    while (1)
    {
        scanf("%c", &temp);
        if (temp != '\n')
        {
            break;
        }
        unit2[i] = temp;
        i++;
    }
}