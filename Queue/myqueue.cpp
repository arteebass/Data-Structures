/*
  Name: Rueben Tiow
  Date: 10/10/2016
  Program: This is a program that implements the functions from myqueue.h
*/
#include "myqueue.h"
// Constructor
MyQueue::MyQueue(){
    head = NULL;
    tail = NULL;
    mysize = 0;
}

//Destructor
MyQueue::~MyQueue(){
    while (head != NULL){ // Set pointer to run through the linked list
        Node* ptr = head->next;
        delete head;
        head = ptr;
    }
}

bool MyQueue::empty() const{ // Returns true if queue is empty

    return (head == NULL );
}

// Not allowed to do this!! But have the general idea. Build idea with pointers in linked list.
int MyQueue::size() const{ // Size of queue
  return (mysize);
}


int MyQueue::front() const{ // returns next element
  int ptr = head->data;
  return (ptr);
}

int MyQueue::back() const{ // returns last element
  int ptr = tail->data;
  return (ptr);
}

void MyQueue::push(int val){ // Inserts a new element at end
    Node* ptr;
    ptr = new Node;
    ptr->data = val;
    ptr->next = NULL; // This is to initialize back to NULL
    if ((head == NULL)){ // Corner case 1: If pushing when no items in queue
	  head = ptr;
	  tail = ptr;
      tail->next = NULL;
	  mysize++;// Increase increment of initial item
    }
    else { // Otherwise push the item at the end of queue
      tail->next = ptr;
	  tail = tail->next;
	  tail->next = NULL;
      mysize++; // Increase increment of items in queue
    }
}

void MyQueue::pop(){ // Removes next element
    Node* ptr;
    if ((head == NULL)){
	  return;
    } 
    else{ // None empty queue
	  ptr = head;
      head = head->next;
      delete(ptr);
	  mysize--;
    }
}
