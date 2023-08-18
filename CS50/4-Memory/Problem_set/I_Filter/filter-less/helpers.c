#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i =0; i< height; i ++)
    {
        for( int j = 0; j < width; j ++)
        {
            float average = ((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed )/3.0)+0.5;
            image[i][j].rgbtBlue = (int) average;
            image[i][j].rgbtGreen = (int) average;
            image[i][j].rgbtRed = (int) average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height ; i ++)
    {
        for (int j = 0; j< width; j++)
        {

            float sepiaRed = (.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue)+0.5;
            float sepiaGreen = (.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue)+0.5;
            float sepiaBlue = (.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue)+0.5;

            if(sepiaRed > 255){ sepiaRed = 255;}
            if(sepiaGreen > 255){ sepiaGreen = 255;}
            if(sepiaBlue > 255){ sepiaBlue = 255;}

            image[i][j].rgbtBlue = (int) sepiaBlue;
            image[i][j].rgbtGreen = (int) sepiaGreen;
            image[i][j].rgbtRed = (int) sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i ++)
    {
        for(int j = 0, semiWidth = width/2; j < semiWidth; j ++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width]; 

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            int count = 0;
            
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int row = i + k;
                    int col = j + l;
                    
                    if (row >= 0 && row < height && col >= 0 && col < width)
                    {
                        sumRed += image[row][col].rgbtRed;
                        sumGreen += image[row][col].rgbtGreen;
                        sumBlue += image[row][col].rgbtBlue;
                        count++;
                    }
                }
            }
            
            temp[i][j].rgbtRed = (float) sumRed / count + 0.5;
            temp[i][j].rgbtGreen = (float) sumGreen / count + 0.5;
            temp[i][j].rgbtBlue = (float) sumBlue / count + 0.5;
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}
