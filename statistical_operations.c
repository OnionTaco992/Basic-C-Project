// Operations related to statistics
// Includes things like functions that find the mean, median, mode and range of an array/list
// I think this is mostly done. I doubt I will need to add anything to this.

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#include "statistical_operations.h"

#define MAX_ARRAY_LIMIT 100

void statistical_functions(void)
{
    int command;

    printf("** Statistical functions **\nPress 1 to calculate mean\nPress 2 calculate median\nPress 3 to calculate the mode\nPress 4 to calculate the range\nPress 0 to exit\n\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf(" %d", &command);
        if (command == 1 || command == 2 || command == 3 || command == 4 || command == 0)
        {
            break;
        }
        printf("\nInvalid input. ");
    }

    switch (command) // to avoid a massive function each statistical function is inside of it's own function
    {                // which helps to make it more readable and easier to make changes to
    case 1:
        find_mean();
        break;
    case 2:
        find_median();
        break;
    case 3:
        find_mode();
        break;
    case 4:
        find_range();
        break;
    case 0:
        return;
        break;
    default:
        break;
    }
}

void find_mean(void)
{
    double list[MAX_ARRAY_LIMIT], sum = 0, mean;
    int i, j;
    char ch;

    printf("\n** Mean **\nEnter a list of numbers, up to %d\nPress t to exit\nEnter the list: ", MAX_ARRAY_LIMIT);

    for (i = 0; i < MAX_ARRAY_LIMIT; i++)
    {
        if (scanf("%lf", &list[i]) != 1)
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

    j = i;

    for (i = 0; i < j; i++)
    {
        sum += list[i];
    }

    mean = sum / i;

    if (j > 0)
    {
        printf("The mean of the list is %.2lf", mean);
    }
    else
    {
        printf("No numbers were entered.\n");
    }
}

int compare(const void *a, const void *b)
{
    double diff = (*(double *)a - *(double *)b);
    return (diff > 0) - (diff < 0);
}

void find_median(void)
{
    double list[MAX_ARRAY_LIMIT], median;
    int i = 0, j;
    char ch;

    printf("** Median **\nEnter a list of numbers (max %d)\nPress t to exit:\n", MAX_ARRAY_LIMIT);

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

    j = i;

    if (j == 0)
    {
        printf("No numbers entered.\n");
        return;
    }

    qsort(list, j, sizeof(double), compare);

    if (j % 2 == 0)
    {
        median = (list[j / 2 - 1] + list[j / 2]) / 2.0;
    }
    else
    {
        median = list[j / 2];
    }

    printf("The median is: %.2lf\n", median);
}

void find_mode(void)
{
    double list[MAX_ARRAY_LIMIT], mode, current;
    int i, j, k, count, max_count = 0;
    char ch;

    printf("** Mode **\nEnter a list of numbers (max %d)\nPress t to exit:\n", MAX_ARRAY_LIMIT);

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

    k = i;

    for (i = 0; i < k; i++)
    {
        current = list[i];
        count = 0;

        for (j = 0; j < k; j++)
        {
            if (list[j] == current)
            {
                count++;
            }
        }

        if (count > max_count)
        {
            max_count = count;
            mode = current;
        }
    }

    if (max_count == 1)
    {
        printf("No mode.\n");
    }
    else
    {
        printf("The mode is: %.2lf which appeared %d times\n", mode, max_count);
    }
}

void find_range(void)
{
    double list[MAX_ARRAY_LIMIT], lowest = DBL_MAX, highest = DBL_MIN;
    int i, k;
    char ch;

    printf("** Range **\nEnter a list of numbers (max %d)\nPress t to exit:\n", MAX_ARRAY_LIMIT);

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

    k = i;

    for (i = 0; i < k; i++)
    {
        if (list[i] < lowest)
        {
            lowest = list[i];
        }
        else if (list[i] > highest)
        {
            highest = list[i];
        }
    }

    printf("\nThe range of the list is %.0lf", highest - lowest);
}