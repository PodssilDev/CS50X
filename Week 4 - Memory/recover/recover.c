#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of total bytes to read / write
#define BYTES 512

// Recover
// Problem Set 4 - Week 4 - Memory
// Author: John Serrano

int main(int argc, char *argv[])
{
    // Check if the program is executed correctly
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    // Open the card file
    FILE *card = fopen(argv[1], "r");
    // Check if the card was opened correctly
    if (card == NULL)
    {
        printf("The card wasn't opened correctly\n");
        return 1;
    }
    // Buffer to store bytes and a counter to see how many JPEG files
    uint8_t buffer[BYTES];
    int cont = 0;
    // 8 spaces for "###.jpg\0"
    char filename[8];
    FILE *img = NULL;

    // While there is still content to read in the card file
    while (fread(buffer, 1, BYTES, card) == BYTES)
    {
        // If is the start of a JPEG file
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {
            // If it's not the first JPEG file
            if (img != NULL)
            {
                fclose(img);
            }
            // Create the new JPEG file and write the bytes
            sprintf(filename, "%03i.jpg", cont);
            img = fopen(filename, "w");
            fwrite(buffer, 1, BYTES, img);
            cont++;
        }
        else
        {
            // If there was already a JPEG file opened and it's not the start
            // Of a new JPEG file, keep writing content
            if (img != NULL)
            {
                fwrite(buffer, 1, BYTES, img);
            }
        }
    }

    // Close the remaining files
    if (img != NULL)
    {
        fclose(img);
    }

    fclose(card);
    return 0;
}
