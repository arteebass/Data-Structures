#include "bst.h"

int main(){
  BST br;
  cout << "Is this tree empty?:" << br.Empty() << endl;
  cout << "The min is:" << br.MinElement() << endl;
  cout << "The max is:" << br.MaxElement() << endl;
  br.Insert(33);
  br.Insert(25);
  br.Insert(44);
  br.Insert(55);
  br.Insert(66);
  br.Insert(33);
  br.Insert(22);
  br.Insert(30);
  cout << endl;
  cout << "does 33 exist:" << br.Search(33) << endl;
  cout << "does 25 exist:" << br.Search(25) << endl;
  cout << "does 44 exist:" << br.Search(44) << endl;
  br.display(cout);
  cout << endl << endl;
  cout << "The max:" << endl;
  cout << br.MaxElement() << endl;
  cout << "The min:" << endl;
  cout << br.MinElement() << endl;
  cout << "I searched for 44:" << br.RecurSearch(44) << endl;
  cout << "I just erased 33\n";
  br.Erase(33);
  cout << "does 33 exist anymore?:" << br.Search(33) << endl;
  br.Insert(11);
  br.display(cout);
  cout << endl << endl;
  cout << "Inserting massive amount of integers" << endl;
  for(int i = 0; i <= 1000; i++){
	br.Insert(i*i+5);
  }
  cout << "does 2430 exist:" << br.Search(2430) << endl << endl;
  br.display(cout);
  cout << endl << endl;
  cout << "My new max:" << br.MaxElement() << endl;
  cout << "My new min:" << br.MinElement() << endl;
  
}

