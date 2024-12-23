// Finds either the GCD or LCM of two numbers
// This could most certainly be improved
// TODO make it all happen in a single function, using a bool
// to determine if it calculates the GCD or LCM of a number
// as the GCD is required to find the LCM 

#include <stdio.h>
#include "gcd_lcm.h"

void gcd_lcm_command(void)
{
    int command;
    char ch;

    printf("\n\n** GCD/LCM calculator **\nDetermines either the GCD (Greatest Common Devisor)\nOr LCM (Lowest Common Multiplier)");
    printf("\n\nPress 1 to calculate GCD\nPress 2 to calculate LCM\nPress 0 to exit\n");

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

    switch (command)
    {
    case 1:
        gcd();
        break;
    case 2:
        lcm();
        break;
    case 0:
        return;
        break;
    default:
        break;
    }
}

void gcd(void)
{
    int m, n, num1, num2, sum, gcd;

    printf("\n\nEnter the first number: ");
    scanf("%d", &num1);
    printf("\nEnter the second number: ");
    scanf("%d", &num2);

    m = num1;
    n = num2;

    while (n != 0)
    {
        sum = m % n;
        m = n;
        n = sum;
    }

    gcd = m;
    printf("\n\nThe gcd of %d and %d is %d.\n", num1, num2, gcd);
}


void lcm(void)
{
    int m, n, num1, num2, gcd, lcm, sum;

    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("\nEnter the second number: ");
    scanf("%d", &num2);

    m = num1;
    n = num2;

    while (n != 0)
    {
        sum = m % n;
        m = n;
        n = sum;
    }

    gcd = m;
    sum = num1 * num2;
    lcm = sum / gcd;

    printf("\n\nThe lcm of %d and %d is %d.\n", num1, num2, lcm);
}
