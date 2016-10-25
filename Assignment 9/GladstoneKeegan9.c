/*
 Rock, Paper, Scissors game
 Gladstone, Keegan
 ICS212 Assignment 9
 02/06/16
 */


#include <stdio.h>
#include <stdlib.h>


//function prototypes
void userRock(char);
void userPaper(char);
void userScissors(char);

//global variables
int userWins = 0;
int compWins = 0;
int ties = 0;

int main(void) {
    char userHand;
    char compHand;
    int digit = 0;

    
    
    puts("Let's play Rock, Paper, Scissors! End the game by typing the EOF key, ^D on unix or ^Z on windows");
    printf("Enter an r, p, or s: ");
    userHand = getchar();
    getchar();
    
    while(userHand != EOF){
            //random digit with switch to set computer's hand
            digit = 1 + rand() % 3;
        
            switch(digit){
            case 1:
                compHand = 'r';
                break;
            case 2:
                compHand = 'p';
                break;
            case 3:
                compHand = 's';
                break;
            }
        
        //if equal this means tie, otherwise there is a winner or loser
        if(userHand == compHand) {
            printf(" %c VS. %c\n", userHand, compHand);
            printf("tie!\n");
            ties++;
        }
        else {
            //switch to determine users hand, calls functions to determine if they won or lost.
            switch(userHand){
            case 'r':
                    printf(" %c VS. %c\n", userHand, compHand);
                    userRock(compHand);
                    break;
            case 'p':
                    printf(" %c VS. %c\n", userHand, compHand);
                    userPaper(compHand);
                    break;
            case 's':
                    printf(" %c VS. %c\n", userHand, compHand);
                    userScissors(compHand);
                    break;
                 //error handling for user input
                default:
                    printf("USER INPUT ERROR\n");
                    break;
    
            }
        }
        
        printf("Enter an r, p, or s: ");
        userHand = getchar();
        getchar();
    }
    
    
    //game was ended by EOF keystroke, prints game statistics.
    puts("");
    puts("END OF GAME");
    printf("user wins: %i\n", userWins);
    printf("comp wins: %i\n", compWins);
    printf("ties: %i\n", ties);

    return 0;
}

/*function if user picks rock:
 if computer picks scissors, prints user wins and increments score.
 Otherwise, the user loses.
 */
void userRock(char compHand){

    if(compHand == 's'){
        printf("user wins!\n");
        userWins++;
        
    } else
        printf("comp wins!\n");
    compWins++;

    return;
}

/*function if user picks paper:
 if computer picks rock, prints user wins and increments score.
 Otherwise, the user loses.
 */
void userPaper(char compHand){
    
    if(compHand == 'r'){
        printf("user wins!\n");
        userWins++;
        
    } else
        printf("comp wins!\n");
    compWins++;
    
    return;
    
}
/*function if user picks scissors:
 if computer picks paper, prints user wins and increments score.
 Otherwise, the user loses.
 */
void userScissors(char compHand){
    
    if(compHand == 'p'){
        printf("user wins!\n");
        userWins++;
        
    } else
        printf("comp wins!\n");
    compWins++;
    
    return;
    
}



