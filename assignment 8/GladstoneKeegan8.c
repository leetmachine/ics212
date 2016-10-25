/*
use 5 functions: pow, rand, fabs, floor, and ceil
Gladstone, Keegan
ICS212 Assignment 8
02/06/16
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "getdouble.h"


//Function Prototypes:
double growth(double);
double gambling(double);

int main(void) {
    double dollars = 0.0;
    double gamblingDollars = 0.0;
    double guess = 0;
    
    puts("This program will calculate 5 random facts with functions.");
    
    //Using function pow to determine a growth of money invested.
    puts("FUNCTION ONE, uses pow");
    printf("Please enter the $ amount of money in your wallet: ");
    dollars = getdouble();
    
    dollars = growth(dollars);
    printf("If you invest that money into the S&P500 index, in 50 years you can grow it to $%.2f, following historical market averages returns.\n", floor(dollars));
    
    /*Function 2 uses rand to generate heads or tails,
      and fabs to determine the difference between your starting and ending funds*/
    puts("FUNCTION TWO uses rand and fabs");
    printf("Please enter the $ amount of money you would like to gamble with: ");
    dollars = getdouble();
    
    puts("Thanks, you will play heads...");
    gamblingDollars = gambling(dollars);
    
    if( gamblingDollars > 0) {
        printf("Congrats! You won %.f\n", fabs(gamblingDollars));
    } else if(gamblingDollars == 0) {
        printf("It was a tie!\n");
    } else {
        printf("Boo! You lost $%.f\n", fabs(gamblingDollars));
    }

    /*Function 3 uses rand to generate a random number,
      and ceil to change the random number to the next integer. */
    puts("FUNCTION THREE, uses rand and ceil");
    printf("guess a number 0 or 1:");
    guess = getdouble();
    
    
    double random = 0 + rand() % 2;
    random = ceil(random);
    
    printf("The computer drew %.f\n", random);
    
    if (guess == random){
        printf("Congrats you matched the number!\n");
    } else {
        printf("Sorry you didn't guess the number.\n");
    }
    
    
    return 0;
}


//Function definitions:

//function which compounds growth of an inputed dollar amount of 50 years, using the S&P500 historical market average return.
double growth(double dollars){
    double newDollars = 0.0;

    newDollars = dollars*pow((1 + .088/1), 50);
    

    return newDollars;
}

double gambling(double dollars){
    double newDollars = 0.0;
    int side = 0;
    newDollars = 0;
    int i = 0;
    
    for (0; i < dollars; i++){
        side = 1 + rand() % 2;
        
        switch(side) {
            case 1:
                puts("heads won");
                newDollars++;
                break;
            case 2:
                puts("tails won");
                newDollars--;
                break;
        }
    }
    
    return newDollars;
}






