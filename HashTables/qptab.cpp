/*
  Group: Rueben Tiow, Asa Davidson, Shi Han
  Date: 10/28/2016
  CPSC 2430
  Homework #5
*/

#include "qptab.h"

//This is the constructor.
QPTab::QPTab(){
  size = 8;
  elements = 0;
  //This is the actual array for the data.
  arr = new int[size];
  //This is an extra array to keep track of the state of each position on the actual array.
  arr2 = new char[size];
  for(int i=0; i<size; i++){
	arr2[i] = 'e';
  }
}

//This is the destructor.
QPTab::~QPTab(){
  delete[] arr;
  delete[] arr2;
}

//This method returns if the hash table is empty.
bool QPTab::Empty() const{
  return elements == 0;
}

//This method tests if a value is in the hash table.
bool QPTab::Contains(int val) const{
  int bucket = HashFunction(val);
  int i = bucket;
  int j = 1;
  while(arr2[i] != 'e'){
	if(arr[i] == val && arr2[i] == 'o'){
	  return true;
	}
	i = (bucket+(j*j)) % size;
	j++;
  }
  return false;
}

//This method returns the array index result of the hash function.
int QPTab::HashFunction(int item) const {
  return (((2 * item) + 5) % size);
}

//This method adds a value to the hash table if the value is not already present.
void QPTab::Insert(int val){
  if(!Contains(val)){
	int bucket = HashFunction(val);
	//If the array is more than half full it is doubled in size and the hash function results are recalculated.
	double load = double(elements)/size;
	if(load >= .5){
      Rehash(true);
	}
	if(arr2[bucket] ==  'e' || arr2[bucket] == 'd'){ //e and d indicate that the index position is available.
	  arr[bucket] = val;
	  arr2[bucket] = 'o';
	}else{
	  //If the calculated position is not available the value will be put in the next available slot.
	  int i = bucket;
	  int j = 1;
	  while(arr2[i] == 'o'){
		i = (bucket+(j*j)) % size;
		j++;
	  }
	  arr[i] = val;
	  arr2[i] = 'o';
	}
	elements++;
  }else{
	cout << val << " Is already in the table" << endl;
  }
}

//This method rehashes the table values if the array is too large or too small.
void QPTab::Rehash(bool q){
  //The bool variable q is used here to indicate if the size of the array should be doubled or cut in half.
  if(q){
	//The values are stored in a temporary array...
	int* oldarr = new int[size];
	for(int i=0; i<size; i++){
	  oldarr[i] = arr[i];
	}
	//then the size is doubled and the values are added back into the array.
	int s = size;
	size = size * 2;
	arr = new int[size];
	//The flag array and the number of elements must be reset because insert() is used to put the values back into the array.
	arr2 = new char[size];
	elements = 0;
	for(int i=0; i<size; i++){
	  arr2[i] = 'e';
	}
	for(int i=0; i< s; i++){
	  Insert(oldarr[i]);
	}
  }else{
	//The procedure is basically the same for reducing the size of the array.
	//The only difference is a check to make sure that the size of the array does not fall below 8.
	if(size == 8){
	  return;
	}
	int* oldarr = new int[size];
	for(int i=0; i<size; i++){
	  oldarr[i] = arr[i];
	}
	int s = size;
	size = size / 2;
	arr = new int[size];
    arr2 = new char[size];
	elements = 0;
	for(int i=0; i< size; i++){
	  arr2[i] = 'e';
	}
	for(int i=0; i< s; i++){
	  Insert(oldarr[i]);
	}
  }
}

//This method deletes a value from the hash table.
void QPTab::Remove(int val){
  if(Contains(val)){
	int bucket = HashFunction(val);
	if(arr[bucket] == val){
	  arr2[bucket] = 'd';
	  elements--;
	}else{
	  int i = bucket;
	  int j = 1;
	  while(arr[i] != val){
		i = (bucket+(j*j)) % size;
		j++;
	  }
	  arr2[i] = 'd';
	  elements--;
	}
	//The search procedure is the same as in insert, the only difference is that when a value is removed it only needs to be marked as deleted.
	//Once it is marked as deleted it cannot be found by contains and the int value can be overriden when the position is needed by a new value.
	//If the array is less than a quarter full, the size is cut in half and the values are rehashed. 
	double load = double(elements)/size;
	if(load <= .25){
	  Rehash(0);
	}
  }
}

//This method prints out the hash table.
void QPTab::Print(vector<int>& arr) const{
  arr.clear(); // clear old values on the vector
  arr.push_back(size);
  for(int k = 0; k < size; k++){
	//Don't fully understand what is going on here, so this is a bt of a guess.
	if(arr[k])
	  arr.push_back(arr[k]);
  }
}

