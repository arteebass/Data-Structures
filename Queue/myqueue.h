/*
    Name: Rueben Tiow
    Date: 10/5/2016
    Program: This is a program that implements a queue named MyQueue using a linked list to store integers.
	
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cassert>
#include <fstream>

#ifndef H_MYQUEUE
#define H_MYQUEUE

using namespace std;

//Do i create a separate class list external from myqueue?

class MyQueue{
    private:
        class Node{
		public:
		  int data; // Inputing intergers to store later
          Node* next; // Node pointer to traverse the list
        };
        int mysize; // Integer store count for items in queue
        typedef Node* NodePointer; // Create an alias named NodePointer for code clarity
        NodePointer head; // Start pointer
        NodePointer tail; // End pointer

    public:
        MyQueue(); // Constructor
        ~MyQueue(); // Destructor
        bool empty() const; // Check if empty
        int size() const; // Size of queue
        int front() const; // returns next element
        int back() const; // returns last element
        void push(int val); // Inserts a new element at end
        void pop(); // Removes next element
};

#endif  // H_MYQUEUE
