/*
  class Node function definitions
  class Node stores a string and a pointer to the next Node
*/

#include <iostream>
#include <string> //C++ string class 
/*
  class interface for class Node
  this puts the header file code at the top of this file
*/ 
#include "node.h" 

using namespace std;


/*
  output the data stored in each Node
  can omit the "friend" qualifier, 
  as it is already in the function prototype in the Node interface
*/
ostream &operator<<(ostream & output, const Node & node){
  output<<node.data;
  return output;
}

/*
  Node constructor to initialize the data members
  each member function has to have "Class::" before the function name,
  so the compiler knows which class the function belongs to
*/
Node::Node(string data2, Node *next2){          
  data = data2; //assign the string
  next = next2; //assign the next pointer
}

//get the data        
string Node::getData() const{ 
  return data;
}

//set the data        
void Node::setData(string data2){   
  data = data2;
}

//get the pointer to the next Node        
Node *Node::getNext() const{  
  return next;
}

//set the pointer to the next Node                
void Node::setNext(Node *next2){   
  next = next2;
}


