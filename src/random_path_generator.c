// creates a random path in a grid

#include <stdio.h>
#include <stdlib.h>

#include "rng.h"
#include "tools.h"

void change_settings(char *background, char *path, int *amount);

void random_path_generator(void)
{
    int grid_x = 0, grid_y = 0, command, start[2], current[2], turns, i, j;
    int prev[2], options, turn_amount, exit_val = 0;
    char background, path_symbol, repeat;

    printf("\n\n** Random Path Generator **\n");
    printf("** It is recommnded to run this with the window maximised **\n\n");
    printf("Enter the X and Y axis: ");
    while (1)
    {
        printf("\n\nEnter your choice: ");
        scanf("%d %d", &grid_x, &grid_y);

        if (grid_x, grid_y)
        {
            break;
        }

        printf("Invalid input.");
    }

    printf("\n\nEnter 2 to change options\nPress 1 to continue");
    while (1)
    {
        printf("\n\nEnter your choice: ");
        scanf("%d", &options);

        if (options == 1 || options == 2)
        {
            break;
        }

        printf("\aInvalid input.");
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
            change_settings(&background, &path_symbol, &turn_amount); // lets user change the character used for both the background and path
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

    printf("Generate another grid? Y/N: ");
    while (1) // makes sure the user enters a valid input
    {
        scanf(" %c", &repeat);

        switch (repeat)
        {
            case 'y':
            case 'Y':
                random_path_generator();
                break;
            case 'n':
            case 'N':
                exit_val = 1;
                break;
            default:
            printf("\nInvalid input. Enter a valid input: ");
        }

        if (exit_val == 1)
        {
            break;
        }
    }
}

void change_settings(char *background, char *path, int *amount) // changes the background symbol
{                                                               // in it's own function so the main function looks a bit cleaner
    printf("\n\nEnter the character to use for the background: ");
    scanf(" %c", &background);

    printf("\n\nEnter the character to use for the path: ");
    scanf(" %c", &path);

    printf("\n\nEnter a number. The smaller the number the more space it will take up."
           "\nEnter the percent: ");
    scanf(" %d", &amount);
}