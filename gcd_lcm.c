// Finds either the GCD or LCM of two numbers
// This might be able to be improved

#include <stdio.h>

#include "gcd_lcm.h"

void gcd_lcm_calculator(void)
{
    int command, m, n, num1, num2, gcd, lcm, sum;
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

    if (command == 0) {
        return;
    }

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
    sum = num1 * num2; // calculates both the gcd and lcm as the gcd is required for the lcm anyways
    lcm = sum / gcd;

    if (command == 1) {
        printf("\n\nThe GCD of %d and %d is %d.\n", num1, num2, gcd); // changes what it prints depending on what you chose
    } else if (command == 2) {
        printf("\n\nThe LCM of %d and %d is %d.\n", num1, num2, lcm);
    }
}