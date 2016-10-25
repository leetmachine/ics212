/*
Display the Japanese word for numbers 0-9
Gladstone, Keegan
Assignment 6
01/31/2016
*/

#include <stdio.h>

int main() {
  
  char yourChar = 'z';
  
  puts("This program will display the Japanese word for a number of your choice.");

  printf("Enter a number 0-9: ");
  yourChar = getchar();

  switch(yourChar) {
  case '0':
      puts("rei");
      break;
  case '1':
    puts("ichi");
    break;
  case '2':
    puts("ni");
    break;
 case '3':
    puts("san");
    break;
  case '4':
    puts("yon");
    break; 
 case '5':
    puts("go");
    break;
  case '6':
    puts("roku");
    break; 
 case '7':
    puts("nana");
    break;
  case '8':
    puts("hachi");
    break;
  case '9':
    puts("kyuu");
    break;
  default:
    printf("'%c' is not a digit in the range 0-9\n", yourChar); 
    break;
  }



  return 0;
}
