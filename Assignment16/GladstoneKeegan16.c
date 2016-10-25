/*
This program takes as input four characters and 2 integers,
 to use in four bitwise operation functions.
Gladstone, Keegan
Assignment 16
03/05/16
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
//#include "printbits.h"

//function prototypes
bool typeCheck(char *, char *, char *, char *, char *, char *);
void twosComplement(unsigned int);
void packFourChars(unsigned char, unsigned char, unsigned char, unsigned char);
void printbits(unsigned int, bool);


int main(int argc,char *argv[]) {
    unsigned int number1 = 0;
    unsigned int number2 = 0;
    
    
    //int length = (sizeof(*argv[1]))/(sizeof(char));
    //printf("length of argv1 is %i \n", length);
    
    //ERROR CHECK: must have 7 arguments
    if(argc != 7) {
        puts("ERROR: Please enter the executable name, followed by FOUR characters, followed by TWO integers on the commandline");
        printf("You entered %i argument(s)\n", argc);
        
    } else {
        //number1 = *argv[5] - '0';
        //number2 = *argv[6] - '0';
        
        //ERROR CHECK: check arguments are correct type
        if (!typeCheck(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6])) {
            //ERROR print statement in function
        } else {
            //sets integer inputs to int variable
            number1 = atoi(argv[5]);
            number2 = atoi(argv[6]);
            
            //Error checking works, now runs four functions.
            puts("\nFunction #1: ");
            twosComplement(number1);
            
            puts("\nFunction #2: ");
            packFourChars(*argv[1], *argv[2], *argv[3], *argv[4]);
            
            
        }
        
    }
    
    return 0;
}

/*ERROR CHECKING FUNCTION: commandline inputs are of correct type
*/
bool typeCheck(char *first, char *second, char *third, char *fourth, char *number1, char *number2) {
    
    //check first char and no character after that
    if(isalpha(*(first+1))) {
        printf("ERROR: Please enter a character for character #1 on the commandline.\n");
        printf("You entered: %s \n", first);
        return false;
    }
    //check second char
    if(isalpha(*(second+1))) {
        printf("ERROR: Please enter a character for character #2 on the commandline.\n");
        printf("You entered: %s \n", second);
        return false;
    }
    //check third char
    if(isalpha(*(third+1))) {
        printf("ERROR: Please enter a character for character #3 on the commandline.\n");
        printf("You entered: %s \n", third);
        return false;
    }
    //check fourth char
    if(isalpha(*(fourth+1))) {
        printf("ERROR: Please enter a character for character #4 on the commandline.\n");
        printf("You entered: %s \n", fourth);
        return false;
    }
    //check interger 1 is a digit or a dash character was typed./
    if(isdigit(*number1) == 0 && *number1 != 45) {
        printf("ERROR: You are missing an integer argument.\n");
        printf("You entered: %s \n", number1);
        return false;
    }
    //check integer 2
    if(isdigit(*number2) == 0 && *number2 != 45) {
        printf("ERROR: You are missing an integer argument.\n");
        printf("You entered: %s \n", number2);
        return false;
    }

    else
        //printf("is alpha %c", *first);
    return true;
}



/*FUNCTION ONE:
 Calculates the two's complement of the first unsigned integer by using the ~ operator + 1
 */
void twosComplement(unsigned int number1) {
    puts("Input is unsigned integer: ");
    printbits(number1, 0);
    puts("Output is the twos complement of the integer: ");
    printbits((~number1) + 1, 0);

}

/*FUNCTION TWO:
packs four unsigned chars into one unsigned integer
 by using the OR operator to compare to 'result', then shifiting 8 bits to the left.
 */
void packFourChars(unsigned char first, unsigned char second, unsigned char third, unsigned char fourth) {
    int i = 0;
    int result = 0;
    printbits((first), 1);
    printbits((second), 1);
    printbits((third), 1);
    printbits((fourth), 1);
    
    unsigned int mask = 0x0000;
    result = mask | first;
    printbits(result, 0);
    puts("");
    result = result << 8;
    result = result | second;
    result = result << 8;
    result = result | third;
    result = result << 8;
    result = result | fourth;

    printbits(result, 0);
    
}


//author: professor Albritton, edited by Keegan Gladstone
//takes in an unsigned int and prints its 32 bits, leastSignificant flags to print 8 bits.
void printbits(unsigned int number, bool leastSignificant){
    int i = 0;
    int limit = 32;
    /*
     A mask is used by bitwise AND to determine
     if a specific 1 or a 0 is present.
     Masks are used to select some bits
     (using 1s - which returns 1, if 1, and returns 0, if 0)
     or hide other bits
     (using 0s - which make everything zero).
     This starts with a 1 at the 31st (leftmost) position,
     followed by 31 zeros.
     */
    unsigned int mask = 0x80000000;
    
    if(leastSignificant) {
        mask  = mask >> 24;
        limit = 8;
    }
    
    
    //loop through the 32 bits
    for(i= 1;i <= limit;i++) {
        //printf("i=%i, mask=0x%x",i,mask);
        //determine if a 1 or 0 exists at each bit location
        if(0 != (number & mask)){
            printf("1");
        }
        else{
            printf("0");
        }
        //add a space for easy reading
        if((24==i) || (16==i) || (8==i)){
            printf(" ");
        }
        //shift bits in mask to the right by one bit
        mask = mask >> 1;
    }//end of for loop
    
    /*
     Display the unsigned integer.
     %u is the format character for unsigned integers.
     %d is for signed integers - use if you want to display negative numbers.
     Leave room for 8 extra spaces for hexadecimal numbers.
     */
    if(leastSignificant) {
        printf(" = 0x%.2X = '%c' \n", number, number);
    }
    else
    printf(" = 0x%.8X = %d \n", number, number);
    
}
