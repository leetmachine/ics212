/*
  header file for class Node
  header files store the class interface 
  class interface contains the function prototypes and the data members of a class
*/

/*
  prevents multiple inclusions of the code in the header file in the final executable file
  when we have many classes, the same header files are often included at the top of several files
*/
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string> //C++ string class  
using namespace std;

//class Node stores a string and a pointer to the next Node
class Node{
  friend ostream &operator<<(ostream &, const Node &); //output the data stored in each Node
  
 public:
  Node(string, Node *);   //constructor
  string getData() const; //get the data
  void setData(string);   //set the data
  Node *getNext() const;  //get the pointer to the next Node
  void setNext(Node *);   //set the pointer to the next Node
  
 private:
  string data; //string data
  Node *next;  //next Node in list of Nodes
  
}; //end of class Node

/*
  end of if statement 
  to prevent multiple inclusion of the header file in the final executable file
*/
#endif

