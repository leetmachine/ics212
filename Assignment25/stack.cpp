#include <iostream>
#include <string> //C++ string class
/*
  class interface for class Stack 
  this puts the header file code at the top of this file
*/  
#include "stack.h" 

using namespace std;

/*
  class Stack function definitions 
  class Stack stores a string and a pointer to the next Node
*/

/*
  constructor
  each member function has to have "Class::" before the function name,
  so the compiler knows which class the function belongs to
*/
Stack::Stack(){   
  top = NULL; //if the Stack is empty, top is NULL
}

//destructor
Stack::~Stack(){  
  /*
    we have to loop through the linked list and delete all of the Nodes from the heap. 
    otherwise, our program might fill up the computer's memory
  */
  cout<<endl<<"Deleting Nodes in Stack..."<<endl;
  //pointer "i" loops through the linked list
  Node *i = top;
  //a pointer to the node being deleted
  Node *temp = NULL;
  while(i != NULL){
    //temp has current node's address
    temp = i;
    //"i" has the next node's address   
    i = i->getNext();
    cout<<"delete Node from heap: "<<*temp<<endl;
    //delete Node from heap   
    delete temp;
  }
}

//overload assignment operator
const Stack &Stack::operator=(const Stack &stack2){
  //if 2nd stack is empty
  if(stack2.empty()){
    //then assign NULL to top of new Stack
    top = NULL;
  }
  /*
    stack is NOT empty, 
    so have to loop through all the Nodes 
    and copy them to the new Stack
  */
  else{
    /*
      top points to a new Node, 
      with the data from the top Node of Stack "stack2"
    */
    top = new Node(stack2.top->getData(), NULL);
    //"i" points to the 1st Node in the Stack "stack2"
    Node *i = stack2.top;  
    //Node j points to the 1st Node in new Stack
    Node *j = top;
    //go to the next Node for Stack "stack2"    
    i = i->getNext(); 
    //loop through all the Nodes and copy them to the new Stack
    while(i!=NULL){ 
      //make a temp Node with data from next Node in Stack "stack2"
      Node *temp = new Node(i->getData(), NULL);
      //link the Nodes together for new Stack
      j->setNext(temp);
      //j has Node temp's address 
      j = temp;
      //go to the next Node for Stack "stack2"    
      i=i->getNext();	 	 
    }
  }
  //"this" is a pointer to the current object (the new Stack)
  return *this; 
}


/*
  Tests if the stack is empty
  returns true/false if empty/not empty 
*/
bool Stack::empty() const{
  return (NULL == top);
}

/*
  Looks at the object at the top of the stack 
  without removing it from the stack.
*/
string Stack::peek() const{
  //check to see if stack is empty or not
  if(!empty()){
    //return the data stored in top Node in Stack
    return top->getData();
  }
  //if stack is empty, return blank string
  return ""; 
}

/*
  Removes the object at the top of stack 
  and returns the data of this object
*/
string Stack::pop(){
  //check to see if stack is empty or not
  if(!empty()){ 
    //make pointer to top Node, which will be deleted
    Node *temp = top;
    //get the string from the top Node
    string dataOnTop = top->getData();
    //reset the top Node to the second item in the linked list
    top = top->getNext();
    /*
      delete the old top Node from the heap
      note: if we don't delete the Node from the heap,
      then our program might fill up the computer's memory
    */
    delete temp;
    //return the data on top of the Stack
    return dataOnTop;
  }
  return ""; //return empty string if empty
}

/*
  Pushes string data onto the top of the Stack 
*/
void Stack::push(string data){
  /*
    dynamically create a new Node
    that points to current top Node
  */
  Node *newTop = new Node(data, top);
  //top points to new Node
  top = newTop;  
}


