// creates a random path in a grid

#include <stdio.h>
#include <stdlib.h>

#include "rng.h"
#include "tools.h"

void change_background(char *background);
void change_path(char *path);
void change_path_amount(int *amount);

void random_path_generator(void)
{
    int grid_x, grid_y, command, start[2], current[2], turns, i, j;
    int prev[2], options, turn_amount;
    char background, path_symbol;

    printf("\n\n** Random Path Generator **\n\n");
    printf("Enter the x axis size: ");
    scanf("%d", &grid_x);

    printf("\n\nEnter the y axis size: ");
    scanf("%d", &grid_y);

    printf("\n\nEnter 2 to change options\nPress 1 to continue");
    while (1)
    {
        printf("\n\nEnter your choice: ");
        scanf("%d", &options);

        if (options == 1 || options == 2)
        {
            break;
        }

        printf("Invalid input.");
    }

    turns = grid_x * grid_y;

    switch (options)
    {
        case 1:
            background = '*'; // default symbols if the user doesn't want to change them
            path_symbol = 'o';
            turns /= 2;
            break;
        case 2:
            change_background(&background); // lets user change the character used for both the background and path
            change_path(&path_symbol);
            change_path_amount(&turn_amount);
            turns /= turn_amount;
            break;
        default:
            break;
    }

    printf("\n\nPress 1 to start at the left of the grid\n"
           "Press 2 to start at the right of the grid\n"
           "Press 3 to start in a random spot");
    while (1)
    {
        printf("\n\nEnter your choice: ");
        scanf("%d", &command);

        if (command == 1 || command == 2 || command == 3)
        {
            break;
        }

        printf("Invalid input.");
    }

    
    
    char **grid = malloc(grid_y * sizeof(char *)); // creates the grid variable
    for (i = 0; i < grid_y; i++)
    {
        grid[i] = malloc(grid_x * sizeof(char));
    }

    for (i = 0; i < grid_y; i++) // creates the grid
    {
        for (j = 0; j < grid_x; j++)
        {
            grid[j][i] = background; // sets the background to the set character
        }
    }

    switch (command)
    {
    case 1:
        start[0] = 0;
        start[1] = generate_random_number2(0, grid_y - 1); // generates random y axis on (x = 0)
        break;
    case 2:
        start[0] = grid_x - 1;
        start[1] = generate_random_number2(0, grid_y - 1); // same as above but on (x = grid_x - 1)
        break;
    case 3:
        start[0] = generate_random_number2(0, grid_x - 1); // generates a completely random place for it to start
        start[1] = generate_random_number2(0, grid_y - 1);
        break;
    default:
        break; // switch can't get here as the previous loop prevents invalid inputs
    }

    prntsp();

    printf("Start coordinates: [%d, %d]\n\n", start[0], start[1]); // for some reason getting rid of this crashes the program????

    current[0] = start[0]; // sets current[] to the starting position
    current[1] = start[1];

    for (i = 0; i != turns; i++)
    {
        prev[0] = current[0]; // keeps the previous move
        prev[1] = current[1];

        grid[current[0]][current[1]] = path_symbol; // changes the position current[] is at to whatever path_symbol is set to

        while (1) // loops until a valid move is chosen
        {
            int nextmove = generate_random_number2(1, 4); // generates a random from 1 to 4, with each number corresponding to a direction

            if (nextmove == 1)
            {
                if (current[0] == grid_x || current[0] == start[0] - 1) // makes sure current[] doesn't cause strange results by going to off the grid
                {
                    continue;
                }

                current[0]++;

                if (current[0] == prev[0]) // checks if current[] went back to the previous position and undoes the move if so
                {
                    current[0]--;
                } else break; // breaks out of the loop if move is valid
            }
            else if (nextmove == 2)
            {
                if (current[0] == 0 || current[0] == start[0] + 1)
                {
                    continue;
                }

                current[0]--;

                if (current[0] == prev[0])
                {
                    current[0]++;
                } else break;
            }
            else if (nextmove == 3)
            {
                if (current[1] == grid_y || current[1] == start[1] - 1)
                {
                    continue;
                }

                current[1]++;

                if (current[1] == prev[1])
                {
                    current[1]++;
                } else break;
            }
            else if (nextmove == 4)
            {
                if (current[1] == 0 || current[0] == start[0] + 1)
                {
                    continue;
                }

                current[1]--;

                if (current[1] == prev[1])
                {
                    current[1]++;
                } else break;
            }
        }
        

    }

    grid[start[0]][start[1]] = 'S'; // lets the user know where the path started

    for (i = 0; i < grid_y; i++) // prints the grid
    {
        for (j = 0; j < grid_x; j++)
        {
            printf("%c", grid[j][i]);
        }
        printf("\n");
    }

    for (i = 0; i < grid_y; i++) // frees grid from memory
    {
        free(grid[i]);
    }
    free(grid);
}

void change_background(char *background) // changes the background symbol
{                            // in it's own function so the main function looks a bit cleaner
    printf("\n\nEnter the character to use for the background: ");
    scanf("%c", &background);
}

void change_path(char *path) // same as above but for the path symbol
{
    printf("\n\nEnter the character to use for the path: ");
    scanf("%c", &path);
}

void change_path_amount(int *amount)
{
    printf("\n\nEnter a number. The smaller the number the more space it will take up."
           "\n\nEnter the percent: ");
    scanf("%d", &amount);
}