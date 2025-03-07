#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "rng.h"
#include "string_writer.h"
#include "tools.h"

void string_writer(void)
{
    Sleep(100);
    printf("** String Generator **\n");
    printf("** Prints a random string then gets rid of it **\n\n\n");

    int prev = -1;

    char *strings[] = {"I sure hope this workes properly!",
                       "Why did I even make this...",
                       "You can launch this directly using a certain launch parameter...\nNot that you ever would want to though...",
                       "Error: String not found\nJust kidding ;)",
                       "100% bug free...\nUntil it isn't",
                       "Run this at 3am and your whole computer will blow up...",
                       "Press a button here and something could happen, Good or Bad, you never know.",
                       "Jumpscare in two seconds...\nBoo",
                       "Open the main program with -olpl for a list of cool stuff"};

    while (1)
    {
        int chosen_string;
        while (1)
        {
            chosen_string = generate_random_number2(0, 8);
            if (chosen_string != prev)
            {
                break;
            }
        }

        prev = chosen_string;

        int len, i, new_line_length;

        for (i = 0; strings[chosen_string][i] != '\0'; i++)
        {
            if (strings[chosen_string][i] == '\n')
            {
                new_line_length = i;
                Sleep(2000); // Creates a short pause if a new line is the current character
            }
            printf("%c", strings[chosen_string][i]);
            Sleep(15);
        }

        Sleep(3500);
        len = i;

        for (i = len; i > 0; i--)
        {
            if (strings[chosen_string][i - 1] == '\n')
            {
                printf("\033[A");
                printf("\033[%dC", new_line_length);
            }
            printf("\b \b");
            Sleep(15);
            
        }
    }
}

void strng_launch_thing(void)
{
    char open_text[] = "Haha made you open this ;)";
    char timer[] = "Returning to normal program in ";
    int i;

    write_text(open_text, 35);

    prntsp();

    write_text(timer, 25);

    for (i = 5; i > 0; i--)
    {
        printf("%d", i);

        Sleep(1000);

        printf("\b \b");
    }
}