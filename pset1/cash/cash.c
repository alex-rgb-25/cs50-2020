#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void){

    int coins = 0;
    float change;
    do{
        change = get_float("Change owed: ");
    }while(change<=0);

    int cents = round(change * 100);
    printf("Change and converted: %f, %i\n", change, cents);   // converting change to cents


    while(cents!=0){
        while(cents>=25){
            cents-=25;
            coins++;
        }

        while(cents>=10){
            cents-=10;
            coins++;
        }


        while(cents>=5){
            cents-=5;
            coins++;
        }


        while(cents>=1){
            cents-=1;
            coins++;
        }

    }

    printf("Final coins needed is:%i\n", coins);


}