//qptab.h
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
#ifndef _QPTAB_H
#define _QPTAB_H

using namespace std;

class QPTab{
 private:
  int size; //Current size
  int* arr; //Dynamic array for LPTab and QPTab
  char* arr2; //Mirrored array for flags
  //e stands for empty which means that the spot has no value stored in it and no marker.
  //d stands for deleted which means that the spot has no value but does have a marker from a previous value.
  //o stands for occupied which means that the spot is taken by a value.
  int elements; //Current number of elements
  //This method increases or decreases the size of the array and recalculates all of the hash function values.
  void Rehash(bool q);
  //This method calculates the index position for a value.
  int HashFunction(int item) const;
 public:
  //This is the constructor.
  QPTab();
  //This is the destructor.
  ~QPTab();
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
