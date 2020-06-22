#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int val;
    if (argc == 2)
    {

        for(int i=0; i<strlen(argv[1]);i++){
            if(!isdigit(argv[1][i])){
                printf("char found!!!\n");
                return 1;
            }

        }
        val = atoi(argv[1]);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string text = get_string("Plain text: ");
    printf("ciphertext: ");
    for(int i=0;i<strlen(text);i++){
        if((int) text[i]>96 && (int) text[i]<123)   // lowercase a-z
        {
             if( (    (int) (text[i])+val) < 123)
             {
                    printf("%c", (text[i]+val));
            }
            else{
                    printf("%c",(text[i]+val-97)%26+97);
            }
        }
        if((int) text[i]>64 && (int) text[i]<91)  //uppercase A-Z
        {
            if( (    (int) (text[i])+val) < 91)
             {
                    printf("%c", (text[i]+val));
            }
            else{
                    printf("%c", (text[i]+val-65)%26+65);
            }
        } if((int) text[i]<65 || (int) text[i]>122) { // rest of cases
            printf("%c", text[i]);
        }

    }
    printf("\n");
}

