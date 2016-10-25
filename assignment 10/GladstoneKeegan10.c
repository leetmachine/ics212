/*
 Program that takes two integers and performs arthimatic on the inbetween.
 Gladstone, Keegan
 ICS212 Assignment 10
 02/8/16
 */


#include <stdio.h>
#include "getdouble.h"

void displayNums(int, int);
int addNums(int, int);
int multiplyNums(int, int);
int powerOfNums(int, int);
int gcdOfNums(int, int);



int main(void ) {
    int first = 1;
    int last = 1;
    int value = 0;
    
    puts("This program will ask for 2 user integers and calculate some arithmetic on them\n"
         "enter ^D on unix or ^Z on windows to exit the program\n");
    printf("Enter two positive integers, separeated by a space, the first smaller than the second: ");
    first = getdouble();
    last = getdouble();
    
    //Program while loop, exits on EOF keystroke
    while(first != 0){
        
        //ERROR CHECKING: the first integer must be smaller than the second.
        if (first > last) {
            printf("ERROR: %i is not less than %i\n", first, last);
            
         //ERROR CHECKING: input is not letters and both are positive.
        } else if( first < 1 || last < 1) {
            printf("ERROR: please enter two positive numbers\n");
            
         /*INPUT IS CORRECT, uses first and last integers to call functions:
          to print the range of numbers inbetween,
          to add the range together,
          to multiply the range together,
          to take the first number to the power of the last,
          to find the GCD of the first and last*/
        } else {
            printf("Counting from %i to %i: ", first, last);
            displayNums(first, last);
            
            value = addNums(first, last);
            printf("The sum of %i to %i = %i\n", first, last, value);
            
            value = multiplyNums(first, last);
            printf("The product of %i to %i = %i\n", first, last, value);
            
            value = powerOfNums(first, last);
            printf("%i to the power of %i = %i\n", first, last, value);
            
            value = gcdOfNums(last, first);
            printf("The GCD of %i and %i = %i\n", first, last, value);
            
        }
        
        //restates question to get new first and last integers or receive EOF keystroke to terminate loop.
        printf("\nEnter two positive integers, separeated by a space, the first smaller than the second: ");
        first = getdouble();
        last = getdouble();
        
    }

    
    return 0;
}


//Prints the numbers in the range from the first to last integer specified.
void displayNums(int first, int last) {
    
    if(first <= last) {
        printf("%i ", first);
        displayNums(first + 1, last);
    } else
        printf("\n");
        return;
}


//adds the numbers in the range from first to last specified, returns the sum
int addNums(int first, int last) {
    int sum = 0;
    
    if (first <= last) {
        sum = first + addNums(first+1, last);
        return sum;
    } else {
    
    return sum;
    }
}

//multiplies the numbers in the range from first to last specified, returns the value
int multiplyNums(int first, int last){
    int value = 1;
    
    if (first <= last) {
        value = first*(multiplyNums(first+1, last));
        return value;
    } else
    return value;
}

//returns the value of the first integer to the power of the last.
int powerOfNums(int first, int last) {
    int value = 1;
    
    if(last > 0) {
        value = first*powerOfNums(first, last-1);
        return value;
    } else
    
    return value;
}

//Euclids Algorithm
//Finds the Greatest Common Divisor of the first and last integers, returns the value.
int gcdOfNums(int m, int n) {
    int remainder = 1;
    
    if(n == 0) {
    return m;
    } else if(m%n == 0){
        return n;
    }
    else
        remainder = m % n;
        gcdOfNums(n, remainder);
    return remainder;
}

