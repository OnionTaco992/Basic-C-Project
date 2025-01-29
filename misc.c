// Misc functions. Anything that I don't feel like putting in
// A specific .c file will just go here
// And if this file manages to get large enough,
// I'll just make a misc2.c ;)

#include <stdio.h>

#define MAX_ARRAY_LIMIT 100

void number_reverser(void)
{
    long int list[MAX_ARRAY_LIMIT], reversed = 0;
    int i, j;
    char ch;

    printf("\n\n** Number Reverser **\n\n");
    printf("Enter a set of numbers up to %d numbers: ", MAX_ARRAY_LIMIT);
    for (i = 0; i < MAX_ARRAY_LIMIT; i++)
    {
        if (scanf("%ld", &list[i]) != 1)
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

    for (i = 0; i < j; i++)
    {
        reversed = 0;
        while (list[i] != 0)
        {
            reversed = reversed * 10 + list[i] % 10;
            list[i] /= 10;
        }
        printf("Reversed number %3d: %ld\n", i + 1, reversed);
    }
}