/*
  Example of using function getdouble() for double input.
  Also shows double output using "%f" format specifier for floats
*/
#include <stdio.h>
/*
  DON'T FORGET TO ADD THIS HEADER FILE!
  or function getdouble() will not return a correct value 
*/
#include "getdouble.h"

int main(){
  /*declare and initialize variable*/
  double number = 0.0;
  
  /*ask user to enter a double, get the double, and display*/
  printf("Enter a number: ");
  number = getdouble();
  /*%f is the format specifier for floats*/
  printf("The number is: %f\n", number);
  
  return 0;
}

/*
  Enter a number: 123.456
  The number is: 123.456000 
*/

