//driver program for class Node 

#include <iostream>
#include <string> //C++ string class  
/*
  class interface (list of function prototypes) for class Node
  this puts the header file code at the top of this file
*/
#include "node.h" 
using namespace std;

//driver function to test Node class
int main(){
  
  //test constructor
  cout<<"test constructor:"<<endl;
  /*
    make a pointer to a Node object
    the Node object is stored "dynamically" (on the heap) during runtime
    syntax: Class *variable = new Class(parameters)
  */
  Node *node1 = new Node("apple", NULL);
  cout<<"node1's address on runtime stack = "<<&node1<<endl;
  cout<<"address to heap stored in node1  = "<<node1<<endl;
  cout<<"node1's data                     = "<<node1->getData()<<endl;
  cout<<"node1's next                     = "<<node1->getNext()<<endl;
  cout<<"display node1 using operator<<() = "<<*node1<<endl;
  
  //link two nodes together  
  cout<<endl<<"link two nodes together:"<<endl;
  Node *node2 = new Node("banana", NULL);
  /*
    for pointers, use this syntax to call a function: 
    pointer->function();
    or
    (*pointer).function();
    alternative code: (*node1).setNext(node2);
  */
  node1->setNext(node2);
  cout<<"node1's next                     = "<<node1->getNext()<<endl;
  cout<<"address to heap stored in node2  = "<<node2<<endl;

  //display address and data of linked node2 
  cout<<endl<<"display addess and data of linked node2:"<<endl;
  cout<<"node2's address on runtime stack = "<<&node2<<endl;
  cout<<"address to heap stored in node2  = "<<node2<<endl;
  cout<<"node2's data                     = "<<node2->getData()<<endl;
  cout<<"node2's next                     = "<<node2->getNext()<<endl;

  //use node1 and pointer to access node2
  cout<<endl<<"use node1 and pointer to access node2"<<endl;
  Node *pointer = node1;
  cout<<"*pointer                         = "<<*pointer<<endl;
  cout<<"&pointer (runtime stack address) = "<<&pointer<<endl;
  cout<<"pointer  (heap address)          = "<<pointer<<endl;
  cout<<"pointer->getData()               = "<<pointer->getData()<<endl;
  cout<<"pointer->getNext()               = "<<pointer->getNext()<<endl;
  pointer = pointer->getNext();
  cout<<"*pointer                         = "<<*pointer<<endl;
  cout<<"&pointer (runtime stack address) = "<<&pointer<<endl;
  cout<<"pointer  (heap address)          = "<<pointer<<endl;
  cout<<"pointer->getData()               = "<<pointer->getData()<<endl;
  cout<<"pointer->getNext()               = "<<pointer->getNext()<<endl;

  //link five nodes together and loop through them
  cout<<endl<<"link five nodes together and loop through them:"<<endl;
  Node *node5 = new Node("eggplant", NULL);
  Node *node3 = new Node("carrot", NULL);
  Node *node4 = new Node("durian", node5);
  node2->setNext(node3);
  node3->setNext(node4);
  
  //Print out the linked nodes with a loop
  Node *i=NULL;
  for(i=node1;i!=NULL;i=i->getNext()){
    cout<<*i<<endl;
  }

  return 0;
}

/*
test constructor:
node1's address on runtime stack = 0xffbffa34
address to heap stored in node1  = 0x23798
node1's data                     = apple
node1's next                     = 0
display node1 using operator<<() = apple

link two nodes together:
node1's next                     = 0x237a8
address to heap stored in node2  = 0x237a8

display addess and data of linked node2:
node2's address on runtime stack = 0xffbffa1c
address to heap stored in node2  = 0x237a8
node2's data                     = banana
node2's next                     = 0

use node1 and pointer to access node2
*pointer                         = apple
&pointer (runtime stack address) = 0xffbffa18
pointer  (heap address)          = 0x23798
pointer->getData()               = apple
pointer->getNext()               = 0x237a8
*pointer                         = banana
&pointer (runtime stack address) = 0xffbffa18
pointer  (heap address)          = 0x237a8
pointer->getData()               = banana
pointer->getNext()               = 0

link five nodes together and loop through them:
apple
banana
carrot
durian
eggplant
*/

