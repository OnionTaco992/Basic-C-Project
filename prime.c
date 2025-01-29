#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_ARRAY_LIMIT 100

void is_prime(void)
{
    long int list[MAX_ARRAY_LIMIT];
    int check[MAX_ARRAY_LIMIT] = {0};
    const char* is_num_prime[MAX_ARRAY_LIMIT];
    int i, n, m, count = 0;
    char ch;

    printf("** Prime Number Calculator **");
    printf("\nDetermines if a number is prime or not.");

    printf("\n\nEnter a list of numbers, up to %d numbers: ", MAX_ARRAY_LIMIT);

    for (i = 0; i < MAX_ARRAY_LIMIT; i++)
    {
        if (scanf("%ld", &list[i]) != 1)
        {
            if (scanf("%c", &ch) == 1 && (ch == 't' || ch == 'T'))
            {
                break;
            }
            else
            {
                printf("Invalid input. Enter either a number or t to exit: ");
                i--;
                count--;
                continue;
            }
        }

        count++;
    }

    for (i = 0; i < count; i++) {
        n = list[i];

        for (m = n - 1; m > 1; m--) {
            if (n % m == 0) {
                check[i] = 1;
                break;
            }
        }

        if (n != 1 && check[i] == 0) {
            check[i] = 0;
        }
    }

    for (i = 0; i < count; i++)
    {
        if (check[i] == 0)
        {
            is_num_prime[i] = "Prime";
        } else if (check[i] == 1) {
            is_num_prime[i] = "Not Prime";
        }
    }

    for (i = 0; i < count; i++)
    {
        printf("\n%d.   %2.0ld: %s", i + 1, list[i], is_num_prime[i]);
    }
}