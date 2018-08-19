#include <cmath>
#include <iostream>
#ifndef _POLY_H
#define _POLY_H

using namespace std;

class Poly
{
 private:
  int myarray[5];
  int power;
  int coeff;
 public:
  Poly();
  void read(istream& in);
  void write(ostream& out) const;
  Poly operator+(const Poly& p);
  Poly operator-(const Poly& p);
  int evaluate (int v);
};

ostream& operator<<(ostream out, const Poly& p);
istream& operator>>(istream& in, Poly& p);

#endif // _POLY_H
