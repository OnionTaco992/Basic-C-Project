// Didn't know what to name this file
// Should be easy to tell what this does
// It isn't complicated

#include <stdio.h>
#include <math.h>

#include "misc_maths.h"

void fibonacci_sequence(void)
{
    int length, i;
    double num1, num2, sum;

    printf("\n\n** Fibonacci **\n\n");
    printf("Enter the length of the sequence: ");
    scanf("%d", &length);
    printf("Enter the number to start at: ");
    scanf("%lf", &num1);

    num2 = (num1 + 1);

    printf("%.0lf ", num1);

    for (i = 0; i < length; i++)
    {
        sum = num1 + num2;
        printf("%.0lf ", sum);
        num1 = num2;
        num2 = sum;
    }

    printf("\n\n");
}

void factorial_sequence(void)
{
    int input, i;
    double sum = 1;

    printf("\n** Factorial **\n** The highest possible number you can input is 170 **\n** Anything above that will return \"inf\" **\nEnter a number: ");
    scanf("%d", &input);

    if (input < 0)
    {
        printf("\nFactorial doesn't work with negative numbers.");
    }

    for (i = 1; i <= input; i++)
    {
        sum *= i;
    }

    if (isinf(sum))
    {
        printf("\nFactorial is too large to compute.\nAny number larger than 170 is too large to compute."); // using factorial on numbers above 170 causes them to exceed 2^1023 which just displays as "inf" making it useless to actually display
        return;
    }
    else
    {
        printf("\n%.0lf", sum);
    }

    printf("\n\n");
}