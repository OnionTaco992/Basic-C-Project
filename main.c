// Main file obviously. Just asks the user what they want to do and sends them to the respective function
// Other than that it contains the info functions (command list, extra misc info) and the exit function

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "misc_maths.h"
#include "hex_octal_conversion.h"
#include "powers_and_exponents.h"
#include "rng.h"
#include "statistical_operations.h"
#include "gcd_lcm.h"
#include "misc.h"
#include "temperature_conversion.h"
#include "guessing_game.h"
#include "prime.h"

#define MAX_ARRAY_LIMIT 100

bool just_opened = true;

void show_command_list_page1(void);
void show_command_list_page2(void);
void extra_info(void);
void exit_program(void);
void page2(void);
void clear_terminal(void);

int main(void)
{
    if (just_opened = true) // clears any previous commands done in the terminal when you open the program
    {                       // there might be a better way to do this but I can't think of one currently
        clear_terminal();
        just_opened = false;
    }

    while (1)
    {
        char command;
        printf("** Page 1 **\n\nPress ? for list of commands.\nWhat do you want to do?: ");

        scanf(" %c", &command); // input is stored as a character so '?', 'c'/'C' and 'h'/'H' can be read.

        switch (command)
        {
        case '1':
            fibonacci_sequence();
            break;
        case '2':
            factorial_sequence();
            break;
        case '3':
            power_actions();
            break;
        case '4':
            statistical_functions();
            break;
        case '5':
            rng();
            break;
        case '6':
            hex_octal_conv();
            break;
        case '7':
            gcd_lcm_calculator();
            break;
        case '8':
            number_reverser();
            break;
        case '9':
            temp_convert();
            break;
        case '0':
            exit_program();
            break;
        case '?':
            show_command_list_page1();
            break;
        case 'h': // avoids case sensitivity
        case 'H':
            extra_info();
            break;
        case 'c':
        case 'C':
            clear_terminal();
            break;
        case '>':
            page2();
            break;
        case '<':
            page2(); // make this go to the last page if a third page is added
            break;
        default:
            printf("Invalid input. Enter a valid input.\n");
            break;
        }
    }

    return 0;
}

void page2(void)
{
    clear_terminal();

    while (1) // just reuses the code from main()
    {
        char command;
        printf("** Page 2 **\n\nPress ? for list of commands.\nWhat do you want to do?: ");

        scanf(" %c", &command);

        switch (command)
        {
        case '1':
            guessing_game();
            break;
        case '2':
            is_prime();
            break;
        case '0':
            exit_program();
            break;
        case '?':
            show_command_list_page2();
            break;
        case 'h':
        case 'H':
            extra_info();
            break;
        case 'c':
        case 'C':
            clear_terminal();
            break;
        case '>':
            main();
            break;
        case '<':
            main();
            break;
        default:
            printf("Invalid input. Enter a valid input.\n");
            break;
        }
    }
}

void show_command_list_page1(void)
{
    clear_terminal();

    char command;

    printf("**** PAGE 1 ****\n\n");
    printf("**   Commands to be use on PAGE 1   **");
    printf("\nUse either < or > to change pages");
    printf("\nPress 0 to exit command list");
    printf("\nPress c to clear terminal");
    printf("\nPress h to display extra info (you don't really need to do this)\n");
    printf("\nPress 1 for a fibonacci sequence.");
    printf("\nPress 2 for a factorial sequence.");
    printf("\nPress 3 for things relating to powers.");
    printf("\nPress 4 for statistical functions.");
    printf("\nPress 5 for a random number generator.");
    printf("\nPress 6 for hex/octal conversion");
    printf("\nPress 7 for a GCD/LCM calculator");
    printf("\nPress 8 for a number reverser");
    printf("\nPress 9 for temperature converter");
    printf("\nPress 0 to exit program");
    printf("\nUse < and > to change command list pages\n\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf(" %c", &command);
        if (command == '0' || command == '<' || command == '>')
        {
            break;
        }
        printf("\nInvalid input. ");
    }

    switch (command)
    {
    case '0':
        break;
    case '<':
        show_command_list_page2();
        break;
    case '>':
        show_command_list_page2();
        break;
    default:
        break;
    }

    clear_terminal();
}

void show_command_list_page2(void)
{
    clear_terminal();

    char command;

    printf("**** PAGE 2 ****\n\n");
    printf("**   Commands to be use on PAGE 2   **");
    printf("\nUse either < or > to change pages");
    printf("\nPress 0 to exit command list");
    printf("\nPress c to clear terminal");
    printf("\nPress h to display extra info (you don't really need to do this)\n");
    printf("\nPress 1 for a number guessing game");
    printf("\nPress 2 for a prime number calculator");
    printf("\nPress 0 to exit the program");
    printf("\nUse < and > to change command list pages\n\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf(" %c", &command);
        if (command == '0' || command == '<' || command == '>')
        {
            break;
        }
        printf("\nInvalid input. ");
    }

    switch (command)
    {
    case '0':
        break;
    case '<':
        show_command_list_page1();
        break;
    case '>':
        show_command_list_page1();
        break;
    default:
        break;
    }

    clear_terminal();
}

void extra_info(void) // misc info that isn't too important
{                     // might add more to it at some point
    clear_terminal();

    printf("\nThe largest a number will possibly be represented as is 2^1023");
    printf("\nThe lowest is -2^1023 obviously");
    printf("\nWhen asked for something like an exponent, it's stored as an integer");
    printf("\nSo don't make it a decimal");
}

void exit_program(void) // exit prompt to ensure that the user wants to exit
{

    char command;
    printf("\nAre you sure? (Y/N): ");

    while (1)
    {
        scanf(" %c", &command);
        if (command == 'y' || command == 'Y' || command == 'n' || command == 'N')
        {
            break;
        }
        printf("Invalid input. Enter a valid input (Y/N): ");
    }

    switch (command)
    {
    case 'y':
    case 'Y':
        clear_terminal();
        printf("Program terminated...\n");
        exit(EXIT_SUCCESS);
        break;
    case 'n':
    case 'N':
        printf("\nReturning to program...");
        break;
    default:
        return;
        break;
    }
}

void clear_terminal(void)
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear"); // should make it so this works on UNIX
    #endif
}
