/*
Count capital and lowercase letters from an input
Gladstone, Keegan
Assignment 11
02/10/2016
*/


#include<stdio.h>
#include<stdlib.h>

#define SIZE 26

//function prototypes
void introduction();
void characterCount(int [], char);
void printResults(int [], int);


int main() {
    int i = 0;
    int characters[SIZE] = {0};
    char current = 'a';
    
    //prints program description and instructions for user.
    introduction();
    
    
    current = getchar();
    
    /*run program loop to count letters of the alphabet in the user input or file redirection
     calls characterCount function.
     */
    while(EOF != current) {
        characterCount(characters, current);
        current = getchar();
    }
    
    
    //print letters array results
    printResults(characters, SIZE);
    return 0;
}


//introduction function to display description and beginning user instructions.
void introduction() {
    puts("This program will count the letters of the alphabet");
    puts("Type a few sentences, or use input redirection to input a file");
    
}

/*takes array and current character as input
 checks if character is in the bounds of A to Z, or a to z based on decimal ASCII value
 and takes the difference from the starting value in that range to determine the relative place in the array to
 increment the counter.
 */
void characterCount(int characters[], char current) {
    int i = 0;
    
    if( current >= 'a' && current <= 'z') {
        i = current - 97;
        characters[i]++;
        
    }
    else if(current >= 'A' && current <= 'Z') {
        i = current - 65;
        characters[i]++;
    } else {
        return;
    }
        
    
}

//prints the results in the characters[] array
void printResults(int characters[], int max) {
    int i = 0;
    
    for(i = 0; i < max; i++) {
        printf(" %c     %i\n", (char) i + 97, characters[i]);
    }
    
}