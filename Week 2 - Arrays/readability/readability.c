#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Readability
// Problem Set 2 - Week 2 - Arrays
// Author: John Serrano

int main(void)
{
    // Declaration of words, sentences and letters variables
    int words = 0;
    int sentences = 0;
    int letters = 0;
    // Text input as string
    string text = get_string("Text: ");
    // Analyze the string; search for words, sentences and letters
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
        else if (isblank(text[i]))
        {
            words += 1;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences += 1;
        }
    }
    // Increment words as 1 since a space separates two words
    words += 1;
    // Calcule L and S to use in Coleman-Liau index
    float L = 100.0 * ((float) letters / (float) words);
    float S = 100.0 * ((float) sentences / (float) words);

    // Use both L and S and apply Coleman-Liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;
    // Round Coleman-Liau index to get the final grade
    int final_index = round(index);

    // Output print, depending on the grade
    if (final_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (final_index > 1 && final_index < 16)
    {
        printf("Grade %i\n", final_index);
    }
    else if (final_index >= 16)
    {
        printf("Grade 16+\n");
    }

    return 0;
}
