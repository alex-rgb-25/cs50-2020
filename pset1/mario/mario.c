#include <cs50.h>
#include <stdio.h>

int main(void){

    int val;
    do{
    val = get_int("Enter value 1-8 \n");


    }while(val<1 || val>8);


    for(int i=0; i<val; i++){
            int k = i;
            while(k<val-1){
                printf(" ");
                k++;
            }
        for(int j=0;j<i+1;j++)
        {

            printf("#");
        }

        printf("\n");
    }

}