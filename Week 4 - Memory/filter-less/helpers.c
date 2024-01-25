#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE average = 1;
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get the average of RGB as the new pixel values
            average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int red = 0;
    int blue = 0;
    int green = 0;
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Apply the formula for sepia
            red = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            green = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            blue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            // Check if red is not over 255
            if (red > 255)
            {
                red = 255;
                image[i][j].rgbtRed = red;
            }
            else
            {
                image[i][j].rgbtRed = red;
            }
            // Check if green is not over 255
            if (green > 255)
            {
                green = 255;
                image[i][j].rgbtGreen = green;
            }
            else
            {
                image[i][j].rgbtGreen = green;
            }
            // Check if blue is not over 255
            if (blue > 255)
            {
                blue = 255;
                image[i][j].rgbtBlue = blue;
            }
            else
            {
                image[i][j].rgbtBlue = blue;
            }
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int k = 0;
    int z = width - 1;
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        k = 0;
        for (int j = z; j >= 0; j--)
        {
            // Using a temp array, copy the value from the last position to the first position
            temp[i][k] = image[i][j];
            // Use k as an index to loop from the first to last position
            k++;
        }
    }

    // Copy the values from temp to image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    // Create variables for getting the new color values
    int red, green, blue;
    float count;
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            red = 0;
            green = 0;
            blue = 0;
            count = 0.0;
            // Getting the center pixel
            red += copy[i][j].rgbtRed;
            green += copy[i][j].rgbtGreen;
            blue += copy[i][j].rgbtBlue;
            count += 1.0;
            // Getting the upper row pixels
            if ((i - 1) >= 0)
            {
                red += copy[i - 1][j].rgbtRed;
                green += copy[i - 1][j].rgbtGreen;
                blue += copy[i - 1][j].rgbtBlue;
                count += 1.0;
                if ((j - 1) >= 0)
                {
                    red += copy[i - 1][j - 1].rgbtRed;
                    green += copy[i - 1][j - 1].rgbtGreen;
                    blue += copy[i - 1][j - 1].rgbtBlue;
                    count += 1.0;
                }
                if ((j + 1) <= (width - 1))
                {
                    red += copy[i - 1][j + 1].rgbtRed;
                    green += copy[i - 1][j + 1].rgbtGreen;
                    blue += copy[i - 1][j + 1].rgbtBlue;
                    count += 1.0;
                }
            }
            // Getting the left pixel
            if ((j - 1) >= 0)
            {
                red += copy[i][j - 1].rgbtRed;
                green += copy[i][j - 1].rgbtGreen;
                blue += copy[i][j - 1].rgbtBlue;
                count += 1.0;
            }
            // Getting the right pixel
            if ((j + 1) <= (width - 1))
            {
                red += copy[i][j + 1].rgbtRed;
                green += copy[i][j + 1].rgbtGreen;
                blue += copy[i][j + 1].rgbtBlue;
                count += 1.0;
            }
            // Getting the botom row pixels
            if ((i + 1) <= (height - 1))
            {
                red += copy[i + 1][j].rgbtRed;
                green += copy[i + 1][j].rgbtGreen;
                blue += copy[i + 1][j].rgbtBlue;
                count += 1.0;
                if ((j - 1) >= 0)
                {
                    red += copy[i + 1][j - 1].rgbtRed;
                    green += copy[i + 1][j - 1].rgbtGreen;
                    blue += copy[i + 1][j - 1].rgbtBlue;
                    count += 1.0;
                }
                if ((j + 1) <= (width - 1))
                {
                    red += copy[i + 1][j + 1].rgbtRed;
                    green += copy[i + 1][j + 1].rgbtGreen;
                    blue += copy[i + 1][j + 1].rgbtBlue;
                    count += 1.0;
                }
            }
            // Get the final RGB values
            red = round(red / count);
            green = round(green / count);
            blue = round(blue / count);
            // Copy the RGB values to the original image
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
}
