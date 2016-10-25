/*
 This program is a basic calculator with add,subtract, multiply, and divide functions. 
 It takes 4 commandline arguments in the form of ./program, x, operation, y,
 where x and y are integers 0-9, and the operation is +, -, ., or /
 Gladstone, Keegan
 Assignment 14
 ICS212
 */

#include <stdio.h>
#include <stdbool.h>
#define INPUT 4
#define SIZE 5

//Fuction prototypes:
bool operationCheck(char);
int addition(int, int);
int subtraction(int, int);
int multiplication(int, int);
int division(int, int);


int main(int argc, char *argv[]) {
    int result = 0; //final result for output
    
    
    
    //ERROR CHECKING:
    //checks for 4 total arguments
    if(argc < INPUT){
        puts("ERROR: You must enter 4 commandline arguments");
    }
    else {
    
        //sets variables x and y to inputed arguments by subtracting character '0'
        int x = (int) (*argv[1] - '0');
        int y = (int) (*argv[3] - '0');
        
        //declare array of pointers to functions
        int (*myArray[SIZE])(int, int) = {addition, NULL, subtraction, multiplication, division};
        
        //ERROR CHECKING:
        //checks that argument 2 is a valid operation symbol
        if(!operationCheck(*argv[2])) {
            puts("ERROR: Argument 2 must be +, -, ., or /");
        }
        //checks that argument 1 is an integers between 0-9.
        else if(x < 0 || x > 9){
            puts("Argument 1 must be an integer between 0-9.");
        
        }
        //checks that argument 3 is an integers between 0-9.
        else if(y < 0 || y > 9){
            puts("Argument 3 must be an integer between 0-9.");
        }
        //error checking passes, program runs here:
        else {
            
            //gets desired function index
            int i = (int)(*argv[2] - '+');
        
            //calls desired function
            result = myArray[i](x, y);
        
            //prints results
            printf("%c %c %c = %i \n", *argv[1], *argv[2], *argv[3], result);
        }
        
    }
    
    
    
    return 0;
}

//checks if the operation command is a valid type
//returns true i
bool operationCheck(char operation) {
    switch(operation) {
        case '+':
            return true;
            break;
        case '-':
            return true;
            break;
        case '.':
            return true;
            break;
        case '/':
            return true;
            break;
        default:
            return false;
    }
}

int addition(int x, int y) {
    int result = x + y;
    
    return result;
}

int subtraction(int x, int y) {
    int result = x - y;
    
    return result;
}

int multiplication(int x, int y) {
    int result = x * y;
    
    return result;
}

int division(int x, int y) {
    int result = x / y;
    
    return result;
}