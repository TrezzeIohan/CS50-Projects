#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    /*
    Check each pixel in the image
        take the average between it's rgb values
        change it's rgb values to that value (must
        be an int)
    */
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Getting the values of rgb
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            float red = image[i][j].rgbtRed;
            //Finding the corresponding gray
            int gray = round((blue + green + red) / 3);

            //changing the rgb values of the pixel
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtRed = gray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Getting the values for sepia's rgb
            int sepiaBlue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));
            int sepiaGreen = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            int sepiaRed = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));


            //changing the rgb values of the pixel
            //and making sure they are equal to
            //or less than 255
            if (sepiaBlue <= 255)
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
            else
            {
                image[i][j].rgbtBlue = 255;
            }

            if (sepiaGreen <= 255)
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            else
            {
                image[i][j].rgbtGreen = 255;
            }

            if (sepiaRed <= 255)
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            else
            {
                image[i][j].rgbtRed = 255;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2 ; j++)
        {
            //Storing the values of the last part of the row
            //in temporary variables
            int tempBlue = image[i][width - (j + 1)].rgbtBlue;
            int tempGreen = image[i][width - (j + 1)].rgbtGreen;
            int tempRed = image[i][width - (j + 1)].rgbtRed;

            //Changing the values of the last part to those of the first
            image[i][width - (j + 1)].rgbtBlue = image[i][j].rgbtBlue;
            image[i][width - (j + 1)].rgbtGreen = image[i][j].rgbtGreen;
            image[i][width - (j + 1)].rgbtRed = image[i][j].rgbtRed;

            //Changing the values of the first part for of the last
            //stored in the temporary variables
            image[i][j].rgbtBlue = tempBlue;
            image[i][j].rgbtGreen = tempGreen;
            image[i][j].rgbtRed = tempRed;
        }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    /*PSEUDOCODE

    Create a temporary copy of the image to work with

    Iterate between the pixels to find it's neighbours
        Check if they are valid
            If true
                Calculate the sum of them
                Get the number of valid neighbouring pixels
                Get the average rgb values

            Round up the average to the nearest integer
            Copy the new pixels into the image
    */

    //Storing the values of the image
    //in temporary variables
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed, totalBlue, totalGreen;
            totalRed = totalBlue = totalGreen = 0;

            //A float is used here in counter because
            //we will divide the RGB values by it
            float counter = 0.00;

            //Get neighbouring pixels
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    //Checking if the current pixel is
                    //a valid one
                    if (currentX < 0 || currentX > (height - 1) ||
                        currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;

                    counter++;
                }

                temp[i][j].rgbtRed = round(totalRed / counter);
                temp[i][j].rgbtGreen = round(totalGreen / counter);
                temp[i][j].rgbtBlue = round(totalBlue / counter);
            }
        }
    }

    //Passing the new pixels into the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
