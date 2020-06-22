#include "helpers.h"
#include "math.h"
#include "stdio.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            avg=round((image[i][j].rgbtRed+image[i][j].rgbtBlue+image[i][j].rgbtGreen)/3.0);

            image[i][j].rgbtRed=avg;
            image[i][j].rgbtGreen=avg;
            image[i][j].rgbtBlue=avg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed, sepiaGreen, sepiaBlue;
    for(int i=0;i<height; i++){
        for(int j=0;j<width;j++){
            sepiaRed=round(0.393*image[i][j].rgbtRed + 0.769* image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            sepiaBlue=round(0.272*image[i][j].rgbtRed + 0.534* image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            if(sepiaRed>255) {
                sepiaRed=255;
            }
            if(sepiaGreen>255) {
                sepiaGreen=255;
            }
            if(sepiaBlue>255) {
                sepiaBlue=255;
            }
            image[i][j].rgbtRed=sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

void swap(RGBTRIPLE *p1, RGBTRIPLE *p2){
    RGBTRIPLE aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height; i++){
        for(int j=0;j<width/2;j++){
            swap(&image[i][j], &image[i][width-j-1]);
        }
    }
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int Blue;
    int Green;
    int Red;
    float counter;

    RGBTRIPLE copy[height][width];

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            Blue = 0;
            Green = 0;
            Red = 0;
            counter = 0.00;
            for (int k=-1; k<2; k++)
            {
                if (j+k < 0 || j+k > height-1){
                    continue;
                }

                for (int h=-1; h<2; h++){
                    if (i + h < 0 || i + h > width - 1){
                        continue;
                    }

                    Blue += image[j + k][i + h].rgbtBlue;
                    Green += image[j + k][i + h].rgbtGreen;
                    Red += image[j + k][i + h].rgbtRed;
                    counter++;
                }
            }

            copy[j][i].rgbtBlue = round(Blue / counter);
            copy[j][i].rgbtGreen = round(Green / counter);
            copy[j][i].rgbtRed = round(Red / counter);
        }
    }

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            image[j][i].rgbtBlue = copy[j][i].rgbtBlue;
            image[j][i].rgbtGreen = copy[j][i].rgbtGreen;
            image[j][i].rgbtRed = copy[j][i].rgbtRed;
        }
    }
}