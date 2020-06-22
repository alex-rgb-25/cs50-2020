#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include<math.h>

int count_letters(string a);
int count_words(string a);
int count_sentences(string a);
int main(void){


    string text = get_string("Text: ");
    //printf("%s\n", text);

    //printf("%i letter(s)\n %i word(s)\n%i sentence(s)\n\n", count_letters(text), count_words(text), count_sentences(text));


    float L = (float) count_letters(text) / (float) count_words(text) * 100;
    float S =(float) count_sentences(text) / (float) count_words(text) * 100;
    float CLI = 0.0588 * L - 0.296 * S - 15.8;
    if (round(CLI) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(round(CLI > 16))
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", round(CLI));
        printf("%i", count_sentences(text));
    }


}

int count_letters(string a)
{
    int count = 0;
    for(int i=0; i<strlen(a);i++)
    {
        if(isalpha(a[i])){
            count++;
        }
    }
    return count;
}

int count_words(string a){
    int words= 0;
    for(int i=0; i<strlen(a);i++)
    {
        if((int) (a[i])==32){
            words++;
        }
    }
    return words+1;
}

int count_sentences(string a){
    int sentences= 0;
    for(int i=0; i<strlen(a);i++)
    {
        if((int) (a[i])==46 || (int) (a[i]) ==33 || (int) (a[i]) ==63){
            sentences++;
        }
    }
    return sentences;
}