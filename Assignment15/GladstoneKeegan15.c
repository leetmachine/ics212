/*
 This program interprets a message written in morse code using . and - symbols.
 Gladstone, Keegan
 Assignment 15
 03/04/16
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LETTERSIZE 5
#define SIZE 36


const char *morse[SIZE] = {
    "0 ----- ",
    "1 .---- ",
    "2 ..--- ",
    "3 ...-- ",
    "4 ....- ",
    "5 ..... ",
    "6 -.... ",
    "7 --... ",
    "8 ---.. ",
    "9 ----. ",
    "a .- ",
    "b -... ",
    "c -.-. ",
    "d -.. ",
    "e . ",
    "f ..-. ",
    "g --. ",
    "h .... ",
    "i .. ",
    "j .--- ",
    "k -.- ",
    "l .-.. ",
    "m -- ",
    "n -. ",
    "o --- ",
    "p .--. ",
    "q --.- ",
    "r .-. ",
    "s ... ",
    "t - ",
    "u ..- ",
    "v ...- ",
    "w .-- ",
    "x -..- ",
    "y -.-- ",
    "z --.. ",
};



int main(int argc, char *argv[]) {
    int m = 0; //index for morse alphabet array
    int j = 1; //index for argv, starts at 1 to ignore ./program
    int argLength = 0;
    int codeLength = 0;
    
    //ERROR CHECKING: must have more than 1 commandline inputs
    if(argc < 2) {
        puts("ERROR: please enter at least two commandline arguements.");
    
    } else {
        //loops over all j user entries, argv[j]
        for(j = 1; j < argc; j++) {
            m = 0;
            //loops over morse alphabet until a match is found for argv[j]
            while(m < SIZE) {
                
                
                //gets lengths of user entry and current morse alphabet
                argLength = strlen(argv[j]);
                codeLength = strlen(morse[m]);
                
                /*
                 The morse entry table contains 3 extra characters than any user entry,
                 therefore we only need to check for a matching substring on alphabet rows that are
                 equal to the user's entry length + 3.
                 */
                if(codeLength == argLength+3) {
                    
                    //checks that the current user entry is a substring of the current morse row
                    char *substring = strstr(morse[m], argv[j]);
                    if(substring != NULL) {
                        //prints the matching letter, exits the morse alphabet loop
                        printf("%c", morse[m][0]);
                        m = SIZE;
                    }
                }
                m++;
            }
        }
    }
    printf("\n");
    
    return 0;
}