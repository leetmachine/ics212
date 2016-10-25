/*A derived class DisplayStack from class Stack with overloaded << operator
 *Gladstone, Keegan
 *Assignment 25
 *04/22/2016
 */

#include <iostream>
#include <string> //C++ has a string class
#include "node.h" //class interface for class Node (this puts the header file code at the top of this file)
#include "stack.h" //class interface for class Stack (this puts the header file code at the top of this file)

using namespace std;

//class DisplayStack
class DisplayStack : public Stack {
   
    
    
    /*overloads cout<<
     * s.top is a pointer to the top most node in the stack
     *each node has a string variable 'data' and Node * 'next'
     *
     *This method assigns a pointer *current to the top node,
     *then uses getData to print out its string.
     *it then assigns *current to the next node in the list using getNext()
     *
     *This while loop terminates when getNext() is NULL, indicating the bottom of the stack
     */
    friend ostream & operator<<(ostream & output, const DisplayStack & s){
        Node *current = s.top;
        
        //print first item, top of stack
        output<<s.top->getData()<<", ";
        
        while(current->getNext() != NULL) {
            //get next item in stack
            current = current->getNext();
            //output data
            output<<current->getData()<<", ";
        }
        
        return output;
    }
    
    
    
};


int main(){
    cout<<"test overloaded operator<< (cout):"<<endl;
    DisplayStack stack1;
    stack1.push("apple");
    stack1.push("banana");
    stack1.push("carrot");
    stack1.push("durian");
    stack1.push("eggplant");
    cout<<"stack1 = "<<stack1<<endl;
    
    DisplayStack stack2;
    stack2.push("aji");
    stack2.push("budai");
    stack2.push("chochouo");
    stack2.push("ebi");
    stack2.push("fugu");
    stack2.push("koi");
    cout<<"stack2 = "<<stack2<<endl;
    
    return 0;
}

/*
 output:
 
 test overloaded operator<< (cout):
 stack1 = eggplant, durian, carrot, banana, apple,
 stack2 = koi, fugu, ebi, chochouo, budai, aji,
 
 Deleting Nodes in Stack...
 delete Node from heap: koi
 delete Node from heap: fugu
 delete Node from heap: ebi
 delete Node from heap: chochouo
 delete Node from heap: budai
 delete Node from heap: aji
 
 Deleting Nodes in Stack...
 delete Node from heap: eggplant
 delete Node from heap: durian
 delete Node from heap: carrot
 delete Node from heap: banana
 delete Node from heap: apple
 */
