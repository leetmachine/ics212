/*
 This program uses pointers to to output and manipulate 3 different variable types.
 Gladstone, Keegan
 Assignment 12
 02/10/16
 */

#include <stdio.h>


int main() {
    
    //declares and initializes the variables
    char myChar = 'a';
    int myInt = 5;
    double myDouble = 6.3;
    
    //declares the pointers and initializes them to the address of the given variable with the '&' operator.
    char *myCharPointer = &myChar;
    int *myIntPointer = &myInt;
    double *myDoublePointer = &myDouble;
    
    
    puts("This program uses pointers to output and manipulate 3 different variables:");
    
    //displays the address of the variable that is stored in the pointer.
    //we use %p as the format specifier because we want the address that the pointer refers to.
    puts("DISPLAY THE ADDRESS OF THE VARIABLES:");
    printf("The address of the variable myChar is %p\n", myCharPointer);
    printf("The address of the variable myInt is %p\n", myIntPointer);
    printf("The address of the variable myDouble is %p\n", myDoublePointer);
    
    //displays the value of the variable each pointer points to.
    //we use %c, %i, %f because we are dereferencing the pointer, to the value it points to.
    puts("\nDISPLAY THE VALUE OF THE VARIABLES:");
    printf("The value of the variable myChar is %c\n", *myCharPointer);
    printf("The value of the variable myInt is %i\n", *myIntPointer);
    printf("The value of the variable myDouble is %f\n", *myDoublePointer);
    
    //adds 3 to each variable by dereferencing
    *myCharPointer = *myCharPointer + 3;
    *myIntPointer = *myIntPointer + 3;
    *myDoublePointer = *myDoublePointer + 3;
    
    //outs the values of the variables by dereferencing
    puts("\nDISPLAY THE NEW VALUES OF THE VARIABLES:");
    printf("The value of the variable myChar + 3 is %c\n", *myCharPointer);
    printf("The value of the variable myInt + 3 is %i\n", *myIntPointer);
    printf("The value of the variable myDouble + 3 is %f\n", *myDoublePointer);
    
    
    
    
    
    
    return 0;
}