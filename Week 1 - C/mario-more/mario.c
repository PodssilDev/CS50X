#include <cs50.h>
#include <stdio.h>

// Mario - more comfortable
// Problem Set 1 - Week 1 - C
// Author: John Serrano

int main(void)
{
    int height; // define height for user input

    do // do loop to only get numbers between 1 and 8 inclusive
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);

    int spaces = height - 1; // number of spaces to print
    int blocks = 1;          // number of "blocks" to print

    while (spaces >= 0) // while spaces aren't less than 0 (piramid completed)
    {
        for (int i = 0; i < spaces; i++)
        {
            printf(" "); // print the left side spaces
        }
        for (int j = 0; j < blocks; j++)
        {
            printf("#"); // print the left side "blocks"
        }

        printf("  "); // print the two spaces between sides

        for (int k = 0; k < blocks; k++)
        {
            printf("#"); // print the right side blocks
        }
        printf("\n"); // print the newline so piramid can grow

        blocks += 1; // blocks increase with each new line
        spaces -= 1; // spaces decrease with each new line
    }
}
