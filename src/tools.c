// misc functions used for coding only
// doesn't have much yet but this might be helpful later

// i might move the rng functions here as they are just tools to make the code cleaner
// but i also like keeping it in easy to find rng.c file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void prntsp(void)
{
    printf("\n\n");
}

void cls(void)
{
    system("cls");
}

void write_text(char array[], int ms)
{
    int i;

    for (i = 0; array[i] != '\0'; i++)
    {
        printf("%c", array[i]);
        Sleep(ms);
    }
}