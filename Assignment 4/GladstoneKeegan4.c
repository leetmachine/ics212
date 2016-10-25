
/*
Ask user for 2 letters,then  2 doubles 
Gladstone, Keegan
ICS 212 Assignment 4
01/22/16
*/

#include <stdio.h>
#include "getdouble.h"


int main(){
  
  char myFirstChar = 'a';
  double myDouble = 0.0;

  printf("Please enter a letter:  ");
  myFirstChar =  getchar();
  getchar();

  printf("The 1st letter is: '%c'\n", myFirstChar);

  printf("Please enter another letter: ");
  myFirstChar = getchar();
  getchar();

  printf("The 2nd letter is: '%c'\n", myFirstChar);

  printf("Please enter a number: ");
  myDouble = getdouble();
   
  printf("The 1st number is: %f\n", myDouble);

  printf("Please enter another number: ");
  myDouble = getdouble();

  printf("The 2nd number is: %f\n", myDouble);

return 0;
}


