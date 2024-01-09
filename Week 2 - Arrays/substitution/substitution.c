#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Substitution (more comfortable)
// Problem Set 2 - Week 2 - Arrays
// Author: John Serrano

// Constants and function prototypes
const char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                           'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
bool validate_key(string key);
string substitution(string key, string plaintext);

int main(int argc, string argv[])
{
    // Check if the program is executed only using the key. If not, stop the program
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else
    {
        // Obtain the key from argv position 1
        string key = argv[1];
        // Check if the key is a correct key
        bool validated = validate_key(key);
        if (validated)
        {
            // Get the input only if the key is valid
            string plaintext = get_string("plaintext: ");
            // Cipher the input text
            string ciphertext = substitution(key, plaintext);
            // Print the cipher text and end
            printf("ciphertext: %s\n", ciphertext);
            return 0;
        }
        else
        {
            // If the key is not valid, end with a integer value of 1
            return 1;
        }
    }
}

// Input: A cipher key, of type string
// Output: A boolean value that represents if the key is valid (true) or not (false)
// Description: Function that checks if the key provided is valid (has a lenght of 26 characters,
// only alphabetical characters and cero repeated letters) or not.
bool validate_key(string key)
{
    char actual_character;
    int cont;
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            actual_character = key[i];
            if (isalpha(actual_character))
            {
                cont = 0;
                for (int j = 0; j < 26; j++)
                {
                    if (actual_character == key[j])
                    {
                        cont += 1;
                    }
                }
                if (cont > 1)
                {
                    printf("Key must not contain repeated letters.\n");
                    return false;
                }
            }
            else
            {
                printf("Key must only contain alphabetical characters.\n");
                return false;
            }
        }
        return true;
    }
}

// Input: Two strings, one representing the cypher key and the other being the plaintext to cypher
// Output: A string consisting of the cypher text
// Description: Functions that uses a valid cypher key to cypher a plaintext, replacing each character
// with the one according to the key
string substitution(string key, string plaintext)
{
    char actual_letter;
    for (int i = 0; i < strlen(plaintext); i++)
    {
        actual_letter = plaintext[i];
        for (int j = 0; j < 26; j++)
        {
            if (toupper(actual_letter) == alphabet[j])
            {
                if (islower(actual_letter))
                {
                    plaintext[i] = tolower(key[j]);
                }
                else
                {
                    plaintext[i] = toupper(key[j]);
                }
            }
        }
    }
    return plaintext;
}
