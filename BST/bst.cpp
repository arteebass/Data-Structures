/*
  Name: Rueben Tiow
  Date: 10/27/2016
  Program:This is a program that implements a Binary Search Tree	\
  named BST using linked list to store integers.
*/

#include "bst.h"
BST::BST(){
  root = NULL;
}

BST::~BST(){
  destroy(root);
}

void BST::destroy(Node* ptr){
  if(ptr == NULL)
	return;
  destroy (ptr->left);
  destroy(ptr->right);
  delete ptr;
}

bool BST::Empty() const {
  return (!root? true : false);
}

void BST::Insert(int val){
  Node* parent = NULL;
  Node* current = root;
  bool found = false;
  while(!found && current != NULL){ //Traverse through tree
	parent = current;
	if(val < current->data)
	  current = current->left;
	else if (val > current->data)
	  current = current->right;
	else
	  found = true;
  }
  if(!found){ // Found the actual key
	current = new BST::Node(val); // Create new node
	if(parent == NULL)
	  root = current;
	else if(val < parent->data)
	  parent->left = current;
	else
	  parent->right = current;
  }else
	cout << "The item:" << val << " already exists in the tree\n";
}

int BST::MinElement() const{
  if(!root){
	cout << "Can't find MinElement of empty tree\n";
	return 0;
  }else{
  Node* cur = root;  
  while(cur->left != NULL){ //Traverse to the furthest left sub-tree
	cur = cur->left;
  }
  return cur->data;
  }
}

int BST::MaxElement() const{
  if(!root){
	cout << "Can't find MaxElement of empty tree\n";
	return 0;
  }else{
  Node* cur = root;
  while(cur->right != NULL){ // Traverse to the furthest right sub-tree
	cur = cur->right;
  }
  return cur->data;
  }
}

bool BST:: Search(int val) const{
  Node* cur = root;
  bool found = false;
  while(!found && cur != 0){ // Traverse until key is found
	if( val < cur->data){
	  cur = cur->left;
  	}
	else if(cur->data < val){
	  cur = cur->right;
	}else{
	  found = true;
	}
  }
  return found;
}

bool BST::RecurSearch(int val) const{
  return (RecurSearchAux(root, val));
}

bool BST::RecurSearchAux(Node* ptr, int item)const{
  if(!ptr){
	return false;
  }
  if(item < ptr->data){
	return RecurSearchAux(ptr->left, item);
  }
  else if(ptr->data < item ){
	return RecurSearchAux(ptr->right, item);
  }
  else
	return true;
}


void BST::display(ostream& out)const{
  inorder(out, root);
}

void BST::inorder(ostream& out, Node* ptr)const{
  if(!ptr){
	return;
  }
	inorder(out, ptr->left);
	out << ptr->data << " ";
	inorder(out, ptr->right);
}

void BST::Erase(int val){
  Node* cur = root;
  Node* parent = NULL;
  bool found = false;
  while(!found && cur != NULL){ //Traverse through tree until key is found
    if(val < cur->data){ 
	  parent = cur;
	  cur = cur->left;
	}else if(val > cur->data){
	  parent = cur;
	  cur = cur->right;
	}else
	  found = true;
  }
  
  if (!found){ //Inform user tried to delete non existent item
	cout << "Item not in BST:" << val << endl;
	return;
  }
  else{
	if(cur->left != NULL && cur->right != NULL){
	  Node* mysuc = cur->right; // Successor
	  parent = cur;
	  while(mysuc->left!=NULL){
		parent = mysuc;
		mysuc = mysuc->left;
	  }
	  cur->data = mysuc->data;
	  cur = mysuc;
	}
	Node* mypred = cur->left; //Predecessor
	if(mypred == NULL){
	  mypred = cur->right;
	}
	if(parent == NULL){
	  root = mypred;
	}else if(parent->left == cur){
	  parent->left = mypred;
	}else if(parent->right == cur){
	  parent->right = mypred;
	}
	delete cur;
  }
}
