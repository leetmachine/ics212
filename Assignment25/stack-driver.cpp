//driver program for class Stack

#include <iostream>
#include <string> //C++ string class
/*
  class interface for class Stack 
  this puts the header file code at the top of this file
*/
#include "stack.h" 

using namespace std;

//driver function to test Stack class
int main(){
  
  //test constructor
  cout<<"test constructor:"<<endl;
  //instantiate(create) a Stack object
  Stack stack1;
  /*
    "boolalpha" displays true or false for bool (Boolean) data type, instead of 1 or 0
    "noboolalpha" sets it back to display 1 or 0
  */
  cout<<"check for empty stack: "<<boolalpha<<stack1.empty()<<endl;
  
  //push several strings to Stack  
  cout<<endl<<"push several strings to Stack:"<<endl;
  stack1.push("apple");
  stack1.push("banana");
  stack1.push("carrot");
  stack1.push("durian");
  stack1.push("eggplant");
  cout<<"check for empty stack: "<<stack1.empty()<<endl;
  cout<<"stack1.peek() = "<<stack1.peek()<<endl;
  cout<<"stack1.pop() = "<<stack1.pop()<<endl;
  cout<<"stack1.peek() = "<<stack1.peek()<<endl;
  
  //test the assignment operator  
  cout<<endl<<"test the assignment operator:"<<endl;
  Stack stack2, stack3;
  stack2.push("aji");
  stack2.push("budai");
  stack2.push("chochouo");
  stack2.push("ebi");
  stack3=stack2;
  stack2.push("fugu");
  stack2.push("koi");
  int i=0;
  cout<<"stack2 = ";
  while(false==stack2.empty()){
    cout<<stack2.pop()<<", ";
  }
  cout<<endl; 
  cout<<"stack3 = ";
  while(false==stack3.empty()){
    cout<<stack3.pop()<<", ";
  }
  cout<<endl;
  
  return 0;
}

/*
test constructor:
check for empty stack: true

push several strings to Stack:
check for empty stack: false
stack1.peek() = eggplant
stack1.pop() = eggplant
stack1.peek() = durian

test the assignment operator:
stack2 = koi, fugu, ebi, chochouo, budai, aji, 
stack3 = ebi, chochouo, budai, aji, 

Deleting Nodes in Stack...

Deleting Nodes in Stack...

Deleting Nodes in Stack...
delete Node from heap: durian
delete Node from heap: carrot
delete Node from heap: banana
delete Node from heap: apple
*/

