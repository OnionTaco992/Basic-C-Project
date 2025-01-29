// TODO make a basic calculator. Maybe try using a float array and a character array for numbers and operators respectively
// Should hopefully be able to use addition, subtraction, multiplication, division, and should be able to exponents
// The exponents might be a bit difficult, but hopefully it should work
// If the calculator doesn't work than try to make a more simple version
// Just as long as there is a functional calculator

#include <stdio.h>

#include "calculator.h"

void calculator(void) // Currently really basic, just using this for testing
{
    double num1, num2, ans;
    char operator;

    printf("\n\n** Calculator **\n\nEnter a number followed by an operator (+ - * /) then another number: ");
    scanf("%lf %c %lf", &num1, &operator, &num2);
    
    switch (operator)
    {
        case '+':
            ans = num1 + num2;
            break;
        case '-':
            ans = num1 - num2;
            break;
        case '*':
            ans = num1 * num2;
            break;
        case '/':
            ans = num1 / num2;
            break;
        default:
            printf("\n\nInvalid operator.");
    }

    printf("\n\n%lf %c %lf = %lf", num1, operator, num2, ans);
}