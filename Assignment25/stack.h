/*
  header file for class Stack
  header files store the class interface 
  class interface contains the function prototypes and the data members of a class
*/

/*
  prevents multiple inclusions of the code in the header file in the final executable file
  when we have many classes, 
  the same header files are often included at the top of several files
*/
#ifndef STACK_H
#define STACK_H

#include <string> //C++ string class  
#include "node.h" //interface (function prototypes) for Node class
using namespace std;

//class Stack stores a string and a pointer to the next Node
class Stack{
  
 public:
  //constructor
  Stack();
  
  //destructor
  ~Stack();
  
  /*
    equals (=) operator makes a new copy of the stack
    NOT another pointer to the same stack
  */
  const Stack& operator=(const Stack&);
  
  /*
    Tests if the stack is empty
    returns true/false if empty/not empty 
    "bool" is a true/false data type
  */
  bool empty() const;
  
  /*
    Looks at the object at the top of the stack 
    without removing it from the stack.
  */
  string peek() const;
  
  /*
    Removes the object at the top of stack 
    and returns the data of this object
  */
  string pop();	 
  
  /*
    Pushes an item onto the top of this stack 
  */
  void push(string);
  
 protected:
  Node *top; //pointer to the first Node on the Stack
  
}; //end of class Stack

/*
  end of if statement 
  to prevent multiple inclusion of the header file in the final executable file
*/
#endif


