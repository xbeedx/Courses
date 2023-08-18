#include "helpers.h"
#include <math.h>

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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width]; 
    int Gx[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
    int Gy[3][3] = {{-1,-2,-1},{0,0,0},{1,2,1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRedx = 0, sumRedy = 0;
            int sumGreenx = 0, sumGreeny = 0;
            int sumBluex = 0, sumBluey = 0;
            
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int row = i + k;
                    int col = j + l;
                    
                    if (row >= 0 && row < height && col >= 0 && col < width)
                    {
                        sumRedx += image[row][col].rgbtRed * Gx[k+1][l+1];
                        sumRedy += image[row][col].rgbtRed * Gy[k+1][l+1];
                        
                        sumGreenx += image[row][col].rgbtGreen * Gx[k+1][l+1];
                        sumGreeny += image[row][col].rgbtGreen * Gy[k+1][l+1];

                        sumBluex += image[row][col].rgbtBlue * Gx[k+1][l+1];
                        sumBluey += image[row][col].rgbtBlue * Gy[k+1][l+1];

                    }
                }
            }

            int gradientRed = round(sqrt(sumRedx * sumRedx + sumRedy * sumRedy));
            int gradientGreen = round(sqrt(sumGreenx * sumGreenx + sumGreeny * sumGreeny));
            int gradientBlue = round(sqrt(sumBluex * sumBluex + sumBluey * sumBluey));

            gradientRed = gradientRed > 255 ? 255 : gradientRed;
            gradientGreen = gradientGreen > 255 ? 255 : gradientGreen;
            gradientBlue = gradientBlue > 255 ? 255 : gradientBlue;

            temp[i][j].rgbtRed = gradientRed;
            temp[i][j].rgbtGreen = gradientGreen;
            temp[i][j].rgbtBlue = gradientBlue;
            
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
