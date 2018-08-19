/*
  Name: Rueben Tiow
  Date: 10/27/2016
  Program: This is the header file of a Binary Search Tree   named BST using linked list to store integers.
*/
//bst.h
#ifndef _BST_H_
#define _BST_H_

#include <iostream>
using namespace std;
class BST {
 private:
  class Node {
  public:
	int data;
	Node* left;
	Node* right;
    Node():left(0),right(0){};
    Node(int item):data(item),left(0),right(0){};
  };
  Node* root; //root node pointer
  void destroy(Node* ptr); // Helper Destructor
  void inorder(ostream& out, Node* ptr)const; // Helper print
  bool RecurSearchAux(Node* ptr, int item)const; // Helper Search
 public:
  BST(); //constructor
  ~BST(); //destructor
  bool Empty() const;
  void Insert(int val);
  int MinElement() const;
  int MaxElement() const;
  bool Search(int val) const;
  bool RecurSearch(int val) const;
  void Erase(int val);
  void display(ostream& out)const;
};
#endif
