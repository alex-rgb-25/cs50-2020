#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    if (argc < 2){
        printf("Usage: ./recover image\n");
        return 1;
    }
    FILE *input = fopen(argv[1], "r");
    FILE* picture = NULL;

    unsigned char buffer[BUFFER_SIZE];
    int found = 0;
    int counter = 0;

     while (fread(buffer, BUFFER_SIZE, 1, input) == 1){
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0){
            if (found == 1){
                fclose(picture);
            }
             else{
                found = 1;
            }
            char filename[8];
            sprintf(filename, "%03d.jpg", counter);
            picture = fopen(filename, "a");
            counter++;
        }
         if (found == 1){
            fwrite(&buffer, BUFFER_SIZE, 1, picture);
        }
    }

    fclose(input);
    fclose(picture);

    return 0;
}