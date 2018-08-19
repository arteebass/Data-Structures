#include "poly.h"

const int EVAL = 2;

int main(){
  Poly p1,p2;
  p1.read(cin);
  p2.read(cin);
  
  cout << "The first polynomial is:";
  p1.write(cout);
  cout << endl;
  cout << "The second polynomial is:";
  p2.write(cout);
  cout << endl;
 
  Poly p3 = p2 + p1;
  cout << "The added polynomial are:";
  p3.write(cout);
  cout << endl;

  cout << "The evaluated value after added, evaluated at " << EVAL << " is: " << p3.evaluate(EVAL);
  cout << endl;
  
  Poly p4 = p2 - p1;
  
  cout << "The subtracted polynomials are:";
  p4.write(cout);
  cout << endl;
  
  cout << "The evaluated value after subtracted, evaluated at " << EVAL << " is: " << p4.evaluate(EVAL);
  cout << endl;  
}
