/*
  Group: Rueben Tiow, Asa Davidson, Shi Han
  Date: 10/28/2016
  CPSC 2430
  Homework #5
*/

#include "chaintab.h"

//This is the constructor.
ChainTab::ChainTab(){
  elements = 0;
  size = 8;
  arr = new Node*[size];
}

//This is the destructor.
ChainTab::~ChainTab(){
  //For each linked list, each node is deleted. Then the array is deleted.
  for(int i = 0; i < size ; i++){
	if(arr[i] != NULL){
	  Node* ptr = arr[i];
	  Node* prev = NULL;
		while(ptr != NULL){
		  prev = ptr;
		  ptr = ptr->next;
		  delete prev;
		}
	}
  }
  delete[] arr;
}

//This method returns if the hash table is empty.
bool ChainTab::Empty() const{
  return elements == 0;
}

//This method tests if a value is in the hash table.
bool ChainTab::Contains(int val) const{
  int bucket = HashFunction(val);
  Node* ptr = arr[bucket]; //This is like Node* ptr = head
  while(ptr != NULL){
	if(ptr->data == val){
	  return true;
	}
	ptr = ptr->next;
  }
  return false;
}

//This method returns the array index result of the hash function.
int ChainTab::HashFunction(int item) const{
  return (((2 * item) + 5) % size);
}

//This method adds a value to the hash table if the value is not already present.
void ChainTab::Insert(int val){
  if(!Contains(val)){
	//If the array is more than half full it is doubled in size and the hash function results are recalculated.
	double load = double(elements) / size;
	if(load >=  0.5){
	  Rehash(true);
	}												
	int bucket = HashFunction(val);
	//A new node is made and put in the front of the list.
	Node* nn = new Node;
	nn->data = val;
	if(arr[bucket] != NULL){
	  nn->next = arr[bucket]->next;
	}
	arr[bucket] = nn;
	elements++;
  }
}

//This method rehashes the table values if the array is too large or too small.
void ChainTab::Rehash(bool q){
  //The bool variable q is used here to indicate if the size of the array should be doubled or cut in half.
  if(q){
	//The values are stored in a temporary array.
	Node** oldarr = new Node*[size];
	for(int i = 0; i < size; i++){
	  Node* ptr = arr[i];
	  while(ptr != NULL){
		Node* x = new Node;  //Matching nodes are created
		x->data = ptr->data; //The data is copied over
		if(oldarr[i] != NULL){
		  x->next = oldarr[i]->next;
		}
		oldarr[i] = x;
		ptr = ptr->next;
	  }
	}
	//The size is doubled and the values are added back into the array
	int s = size;// oldarr size
	size = size * 2;
	arr = new Node*[size];
	elements = 0; //elements must be reset to 0 because insert is used to add the values back into the array
	for(int i = 0; i < s; i++){
	  Node* ptr2 = oldarr[i];
	  while(ptr2 != NULL){
		Insert(ptr2->data);
		ptr2 = ptr2 -> next;
	  }
	}
  }else{
	//The procedure is basically the same for reducing the size of the array.
	//The only difference is a check to make sure that the size of the array does not fall below 8.
	if(size == 8){
	  return;
	}else{
	  Node** oldarr = new Node*[size];
	  for(int i = 0; i < size; i++){
		Node* ptr = arr[i];
		while(ptr != NULL){
		  Node* x = new Node;
		  x->data = ptr->data;
		  if(oldarr[i] != NULL){
			x->next = oldarr[i]->next;
		  }
		  oldarr[i] = x;
		  ptr = ptr->next;
		}
	  }
	  int s = size;
	  size = size / 2;
	  arr = new Node*[size];
	  elements = 0;
	  for(int i = 0; i < s; i++){
		Node* ptr2 = oldarr[i];
		while(ptr2 != NULL){
		  Insert(ptr2->data);
		  ptr2 = ptr2->next;
		}
	  }
	}
  }
}

//This method deletes a value from the hash table.
void ChainTab::Remove(int val){
  if(Contains(val)){
	//If the array is less than a quarter full, the size is cut in half and the values are rehashed.
	double load = double(elements) / size;
	if(load <= 0.25){
	  Rehash(false);
	}
	int bucket = HashFunction(val);
	Node* current = arr[bucket];
	Node* prev = NULL;
	while(current->data != val){ //Current is set to the value to be deleted.
	  prev = current;
	  current = current->next;
	}
	if(prev == NULL){ //This tests if the head needs to be updated.
	  arr[bucket] = current->next;
	}else{
	  prev->next = current->next;
	}
	delete current;
	elements--;
  }
}
	
//This method prints out the hash table.
void ChainTab::Print(vector<int>& arr) const{
  arr.clear(); // clear old values on the vector
  arr.push_back(size);
  for(int k = 0; k < size; k++){
	//Don't fully understand what is going on here, so this is a bt of a guess.
	if(arr[k])
	  arr.push_back(arr[k]);
  }
}
