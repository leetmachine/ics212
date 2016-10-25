/*
This program shows how a variable is changed through a function using call-by-reference
    and shows how a pointer can be used with an array to display single values, all values, and addresses.
 Gladstone, Keegan
 ICS212 #12
 02/11/16
 */


#include <stdio.h>
#define SIZE 5

//function prototype
void changeIntByReference(int *);

int main() {
    int i = 0;
    
    /*PART A:
     uses a function call to changeIntByReference() to change the variable myInt from 5 to 10
     by using pointers
     */
    puts("The first part of this program changes a function using call-by-reference:");
    int myInt = 5;
    printf("myInt is declared and initialized to %i\n", myInt);
    changeIntByReference(&myInt);
    printf("myInt after the function call finishes is %i\n", myInt);
    
    /*PART B:
    Display the 5th element of the array through 4 different notation styles.
     declare and init myArray*/
    int myArray[] = {5, 7, 22, 11, 3};
    int *pointer = myArray;
    
    puts("The second part of this program uses pointers to display values in an array of 5 elements:");
    puts("DISPLAY THE FIFTH ELEMENT IN THE ARRAY:");
    
    //using array subscript notation
    printf("myArray[4] is %i \n", myArray[4]);
    
    //pointer/offset notation using the array name
    printf(" *(myArray + 4) is %i \n", *(myArray + 4));
    
    //array subscript notation using the pointer
    printf("pointer[4] is %i \n", pointer[4]);
    
    //pointer/offset notation with the pointer
    printf(" *(pointer + 4) is %i \n", *(pointer + 4));
    
    /*Part C:
     Display the entire array through 4 different notation styles.
     */
    puts("DISPLAY THE ENTIRE ARRAY:");
    
    //array subscript notation
    printf("array[i] for all i is ");
    for(i = 0; i < SIZE; i++) {
        printf("%i ", myArray[i]);
    }
    puts(" ");
    
    //array pointer/offset notation using the array name
    printf("*(array + i) is ");
    for(i = 0; i < SIZE; i++) {
        printf("%i ", *(myArray + i));
    }
    puts(" ");
    
    //array subscript notation using the pointer
    printf("pointer[] is ");
    for(i = 0; i < SIZE; i++) {
        printf("%i ", pointer[i]);
    }
    puts(" ");
    
    //pointer/offset notation with the pointer
    printf("*(pointer + i) is ");
    for(i = 0; i < SIZE; i++) {
        printf("%i ", *(pointer + i));
    }
    puts(" ");
    
    //display the addresses of each element of the arry:
    puts("DISPLAY THE ADDRESS OF EACH ELEMENT IN THE ARRAY");
    for(i = 0; i < SIZE; i++) {
        printf("The address of the %ith item is %p \n", i, pointer + i);
    }
    
    
    return 0;
}

//this function uses call-by-reference. It takes an address of a variable, then adds 5 to its value.
void changeIntByReference(int *intPointer){
    
    printf("myInt during the function function call is %i\n", *intPointer);
    *intPointer = *intPointer + 2;
    
}