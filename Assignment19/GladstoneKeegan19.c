/*
This program generates 25 to 75 random integers and performs the function sum() and count() on the linked list
Gladstone, Keegan
Assignment 19
03/25/16
*/

#include <stdio.h>
#include <time.h> //time functions
#include <stdlib.h> //random number generator functions


//number is the digit, next is a pointer to the next node
struct node {
    int number;
    struct node *next;
    
};

//type definition for "new" data types
typedef struct node Node;
typedef struct node* NodePointer;


//function definitions
void insertIntoLinkedList(int randomNumber, NodePointer *);
void displayLinkedList(NodePointer);
void sum(NodePointer);
void count(NodePointer);

//global variables
int addition = 0;
int items = 0;

int main(int argc,char *argv[]) {
    int i = 0;
    int randomNumber = 0;
    float average = 0.0;
    
    NodePointer head = NULL;
    
   //get random int between 25 and 75, to be length of linked list
    srand(time(NULL));
    int listLength = 0;
    listLength = 1 + rand() % 50; //random number above 25 below 75.
    listLength += 25; //plus lower bound
    
    //generate random numbers between 0 and 100, add to linked list.
    for(i = 0; i < listLength; i++) {
        randomNumber = 1 + rand() % 100;
        insertIntoLinkedList(randomNumber, &head);
    }
    
    displayLinkedList(head);
    sum(head);
    printf("sum = %i\n", addition);
    count(head);
    printf("count = %i\n", items);
    
    if(0 != items) {
        average = (float)addition/items;
        printf("average = %.2f\n\n", average);
    }
    
    return 0;
}

void insertIntoLinkedList(int randomNumber, NodePointer *head2) {
    //set up pointers
    NodePointer newNode = NULL;
    NodePointer previous = NULL;
    NodePointer current = *head2;
    
    //create node on the heap
    newNode = malloc(sizeof(Node));
    
    //check to see if space is available, if not malloc return NULL
    if(NULL != newNode) {
        //add number to the node
        newNode->number = randomNumber;
        
        /*determine where to place node. While current is not NULL there is a next node.
          current is NULL for the last node in the list.
          once randomNumber is > current->number, we place newNode in between previous and current.
        */
        while(NULL != current && current->number < randomNumber) {
            previous = current;
            current = current->next;
        }
        //insert at beginning of list
        if(NULL == previous) {
            newNode->next = current;
            *head2 = newNode;
        }
        //else find last item and add newNode
        else {
            //the previous node's next pointer points to the new node
            //the newNode's next pointer points to current, which is NULL because it is now the last node
            previous->next = newNode;
            newNode->next = current;
        }
    }
}

void displayLinkedList(NodePointer current) {
    //check for empty list
    if(NULL == current){
        printf("the linked list is empty!\n");
        
    } else {
        printf("The list is: ");
        while(NULL != current) {
            printf("%i, ", current->number);
            current = current->next;
        }
        printf("\n");
    }
}

//sums all numbers in the linked list
void sum(NodePointer current){
    
    while(NULL != current) {
        addition += current->number;
        current = current->next;
    }
}

//counts elements in the linked list
void count(NodePointer current){
    
    while(NULL != current) {
        items++;
        current = current->next;
    }
}
