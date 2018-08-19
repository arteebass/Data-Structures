//chaintab.h
/*
  Group: Rueben Tiow, Asa Davidson, Shi Han
  Date: 10/28/2016
  CPSC 2430
  Homework #5
*/
/*
  Team Members: Asa Davidson, Rueben Tiow, Shi Han
  Asa's contribution: Design, Coding, Debugging
  Rueben's contribution: Design, Coding, Debugging
  Shi's contribution: Coding, Debugging
*/

#include <iostream>
#include <vector>
#ifndef _CHAINTAB_H
#define _CHAINTAB_H

using namespace std;

class ChainTab{
 private:
  int elements; //current number of elements in the array
  int size; //current size of the array
  class Node{
   public:
	int data;
	Node* next;
  };
  Node** arr; // Dynamic Array of Node pointers
  //This method increases or decreases the size of the array and recalculates all of the hash function values.
  void Rehash(bool q);
  //This method calculates the index position for a value.
  int HashFunction(int item) const;
 public:
  //This is the constructor.
  ChainTab();
  //This is the destructor.
  ~ChainTab();
  //This method tests if the hash table is empty.
  bool Empty() const;
  //This method tests if a value is in the hash table.
  bool Contains(int val) const;
  //This method adds a value to the hash table.
  void Insert(int val);
  //This method removes a value from the hash table.
  void Remove(int val);
  //This method prints out the hash table.
  void Print(vector<int>& A) const;
};

#endif

