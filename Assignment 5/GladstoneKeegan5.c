/*
Find users age in days
Gladstone, Keegan
ICS 212 Assignment 5
01/31/2016
*/

#include <stdio.h>
#include "getdouble.h"

#define DAYSINYEAR 365.25
#define DAYSINMONTH  356.25/12
#define TODAYSAGE 736359.4


int main() {
  
  double myMonth = 0.0;
  double myDay = 0.0;
  double myYear = 0.0;
  int myAge = 0;
   
  puts("This program will calculate your age in days.");
  
  printf("Enter the month you were born: ");
  myMonth = getdouble();

  printf("Enter the day you were born: ");
  myDay = getdouble();

  printf("Enter the year you were born: ");
  myYear = getdouble();

  printf("Today's date is: 01/31/2016\n");

  myAge = (int)TODAYSAGE - (DAYSINYEAR*myYear + (myMonth - 1)*DAYSINMONTH + myDay);
  


  printf("Your age in days is: %i,%03i\n", myAge/1000, myAge%1000); 




 return 0;
}
