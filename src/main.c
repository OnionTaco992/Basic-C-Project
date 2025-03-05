// Main file obviously. Just asks the user what they want to do and sends them to the respective function
// Other than that it contains the info functions (command list, extra misc info) and the exit function

// TODO add launch parameters

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

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
#include "random_path_generator.h"
#include "string_writer.h"

#include "tools.h"

#define MAX_ARRAY_LIMIT 100

int add_newlinechars = 0;

void show_command_list_page1(void);
void show_command_list_page2(void);
void extra_info(void);
void exit_program(void);
void page1(void);
void page2(void);
void clear_terminal_main(void);

int main(int argc, char *argv[])
{
    system("cls");

    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-open_command_page_one") == 0)
        {
            show_command_list_page1();
        }
        else if (strcmp(argv[i], "-open_command_page_two") == 0)
        {
            show_command_list_page2();
        }
        else if (strcmp(argv[i], "-Extra_Info") == 0)
        {
            extra_info();
        }
        else if (strcmp(argv[i], "-page_two") == 0)
        {
            page2();
        }
        else if (strcmp(argv[i], "-open_string_writer") == 0)
        {
            string_writer();
        }
    }

    page1(); // page1() is in it's own function as I plan on adding launch parameters and this will
             // make it look a bit cleaner
    return 0;
}

void page1(void)
{
    clear_terminal_main();

    while (1)
    {
        char command;

        if (add_newlinechars == 1)
        {
            prntsp(); // makes it so it automatically makes two new line characters when you finish something
        } // and return back to the main() function
        else if (add_newlinechars == 0) // however if you clear the terminal it doesn't create any new line characters
        {
            add_newlinechars = 1;
        }

        char start_message[] = {"** Page 1 **\n\nPress ? for a list of commands.\nWhat do you want to do?: "};

        write_text(start_message, 10);

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
            clear_terminal_main();
            system("start cmd /k \"ot_tools.exe -open_command_page_one\"");
            break;
        case 'h': // avoids case sensitivity
        case 'H':
            clear_terminal_main();
            system("start cmd /k \"ot_tools.exe -Extra_Info\"");
            break;
        case 'c':
        case 'C':
            clear_terminal_main();
            break;
        case '>':
            add_newlinechars = 0;
            page2();
            break;
        case '<':
            add_newlinechars = 0;
            page2(); // make this go to the last page if a third page is added
            break;
        default:
            clear_terminal_main();
            printf("\aInvalid input. Enter a valid input.\n");
            break;
        }
    }
}

void page2(void)
{
    clear_terminal_main();

    while (1)
    {
        char command;

        if (add_newlinechars == 1)
        {
            prntsp();
        }
        else if (add_newlinechars == 0)
        {
            add_newlinechars = 1;
        }

        char open_message[] = {"** Page 2 **\n\nPress ? for list of commands.\nWhat do you want to do?: "};

        write_text(open_message, 10);

        scanf(" %c", &command);

        switch (command)
        {
        case '1':
            guessing_game();
            break;
        case '2':
            is_prime();
            break;
        case '3':
            random_path_generator();
            break;
        case '4':
            system("start cmd /k \"ot_tools.exe -open_string_writer\""); // opens it's own window because I can't yet think of a way to let the user
            break;                                                       // close it without fully closing the program
        case '0':
            exit_program();
            break;
        case '?':
            clear_terminal_main();
            system("start cmd /k \"ot_tools.exe -open_command_page_two\"");
            break;
        case 'h':
        case 'H':
            clear_terminal_main();
            system("start cmd /k \"ot_tools.exe -Extra_Info\"");
            break;
        case 'c':
        case 'C':
            clear_terminal_main();
            break;
        case '>':
            add_newlinechars = 0;
            page1();
            break;
        case '<':
            add_newlinechars = 0;
            page1();
            break;
        default:
            printf("Invalid input. Enter a valid input.\n");
            break;
        }
    }
}

void show_command_list_page1(void)
{
    SetConsoleTitle("OT_Tools_Commands");

    cls();

    char command;

    printf("**** PAGE 1 ****\n\n");
    printf("**   Commands to be used on PAGE 1   **\n");
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
        printf("\n\aInvalid input. ");
    }

    switch (command)
    {
    case '0':
        HWND hwnd = FindWindow(NULL, "OT_Tools_Commands");

        if (hwnd)
        {
            SendMessage(hwnd, WM_CLOSE, 0, 0);
            printf("Window closed successfully.\n"); // Why the hell do I need all this just to close a damn window
        }
        else
        {
            printf("Window not found.\n");
        }
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
}

void show_command_list_page2(void)
{
    SetConsoleTitle("OT_Tools_Commands");

    cls();

    char command;

    printf("**** PAGE 2 ****\n\n");
    printf("**   Commands to be use on PAGE 2   **");
    printf("\nUse either < or > to change pages");
    printf("\nPress 0 to exit command list");
    printf("\nPress c to clear terminal");
    printf("\nPress h to display extra info (you don't really need to do this)\n");
    printf("\nPress 1 for a number guessing game");
    printf("\nPress 2 for a prime number calculator");
    printf("\nPress 3 for a random path generator");
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
        printf("\n\aInvalid input. ");
    }

    switch (command)
    {
    case '0':
        HWND hwnd = FindWindow(NULL, "OT_Tools_Commands");

        if (hwnd)
        {
            SendMessage(hwnd, WM_CLOSE, 0, 0);
            printf("Window closed successfully.\n"); // Once again why the hell do I need all this just to close a damn window
        }
        else
        {
            printf("Window not found.\n");
        }
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
}

void extra_info(void) // misc info that isn't too important
{                     // might add more to it at some point
    SetConsoleTitle("Extra_Info");

    printf("The largest a number will possibly be represented as is 2^1023");
    printf("\nThe lowest is -2^1023 obviously");
    printf("\nWhen asked for something like an exponent, it's stored as an integer");
    printf("\nSo don't make it a decimal");

    printf("\n");

    while (1) // inf loop so the window doesn't auto close
    {
    }
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
        printf("\a\nInvalid input. Enter a valid input (Y/N): ");
    }

    switch (command)
    {
    case 'y':
    case 'Y':
        clear_terminal_main();

        HWND mu_cmd = FindWindow(NULL, "OT_Tools_Commands");
        HWND ex_info = FindWindow(NULL, "Extra_Info");

        if (mu_cmd)
        {
            SendMessage(mu_cmd, WM_CLOSE, 0, 0);
        }
        if (ex_info)
        {
            SendMessage(ex_info, WM_CLOSE, 0, 0);
        }

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

void clear_terminal_main(void)
{
    add_newlinechars = 0;
    cls();
}
