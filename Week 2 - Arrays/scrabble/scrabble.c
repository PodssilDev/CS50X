#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Scrabble
// Problem Set 2 - Week 2 - Arrays
// Author: John Serrano

// Constants and function prototypes
const char letters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                          'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const int letters_scores[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int get_player_score(string player_input);
void get_winer(int p1_score, int p2_score);

int main(void)
{
    // Input for both players
    string p1_input = get_string("Player 1: ");
    string p2_input = get_string("Player 2: ");

    // Score for both players
    int p1_score = get_player_score(p1_input);
    int p2_score = get_player_score(p2_input);

    // Determine the winer or tie
    get_winer(p1_score, p2_score);

    return 0;
}

// Input: A player's input, in string format
// Output: The score of the player, depending of it's input, in integer format
// Description: Function that calculates the total score of a player, depending on the
// input.
int get_player_score(string player_input)
{
    int player_score = 0;
    char actual_letter;
    for (int i = 0; i < strlen(player_input); i++)
    {
        actual_letter = player_input[i];
        actual_letter = toupper(actual_letter);
        for (int j = 0; j < 26; j++)
        {
            if (actual_letter == letters[j])
            {
                player_score += letters_scores[j];
            }
        }
    }
    return player_score;
}

// Input: The scores of both players, in integer format
// Output: No output (But it does print on console)
// Description: Function that compares both scores and figures out the winer or if there's a tie
void get_winer(int p1_score, int p2_score)
{
    if (p1_score > p2_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (p2_score > p1_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}