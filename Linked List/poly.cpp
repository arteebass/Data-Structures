#include "poly.h"


Poly::Poly(){ // Initialize data members
  power = 0;
  coeff = 0;
  
}


void Poly::read(istream& in){
  cout << "Please enter a power followed by coefficients: ";
  in >> power;
  if (power > 0 && power < 6){
	power = power + 1; // Increase counter by 1 because of +C value of polynomial.
	for (int i= 0; i < power; i++){
	  in >> coeff;
	  myarray[i] = coeff; // Store in array at location i with integer coeff
	}
  }
  else{ // Not in range of my array size
	cout << "You are out of scope!! ";
  }
}


void Poly::write(ostream& out) const{
  if (power == 1){ // Given single value
	if (myarray[0] > 0 || myarray[0] < 0){
	  cout << myarray[0];
	}
	else{
	  cout << "";
	}
  }

  else if (power == 2){ // Given 2 values
	if (myarray[0] > 0 && myarray[1] > 0){ // Both conditions are positive
	  cout << myarray[0] << "+" << myarray[1] << "x";
	}
	else if (myarray[0] < 0 && myarray[1] < 0){// Both conditions are negative
	  cout << myarray[0] << "+" << myarray[1] << "x";
	}
	else if (myarray[0] == 0 && (myarray[1] < 0 || myarray[1] > 0)){ // One condition that is 0
	  cout<< myarray[1] << "x";
	}

	else if((myarray[0] > 0 || myarray[0] < 0) && myarray[1] == 0){// Another condition that is 0
	  cout << myarray[0];
	}
	else{ //both must be 0
	  cout << "";
	}
  }
  else{
	for (int i = 0; i < power; i++){ // Loop within array
  	  if(i == 0){ // Display C value of polynomial
		if (myarray[i] > 0 || myarray[i] < 0){
		  cout << myarray[i] << "+";
		}
		else{
		  cout << "";
		}
	  } 

	  else if (i == 1){ // Display First polynomial (power to one)
		if (myarray[i] > 0 || myarray[i] < 0){
		  cout << myarray[i] << "x+";
		}
		else{
		  cout << "";
		}
  	  }

	  else if (i == power-1){ // Display the final polynomial
		if (myarray[i] > 0 || myarray[i] < 0 ){
		  cout << myarray[i] << "x^" << i;
		}
		else{
		  cout << "";
		}
	  }
	  
	  else{ // Display polynomial that have  power more than one 
		if (myarray[i] > 0 || myarray[i] <0 ){
		  cout << myarray[i] << "x^" << i  << "+";
		}
		else{
		  cout << "";
		}
	  }
    }
  }
}

Poly Poly::operator+(const Poly& p){  
  for (int i = 0; i < this->power; i++){
	this->myarray[i] = this->myarray[i] + p.myarray[i];
  }
  return *this;
}


Poly Poly::operator-(const Poly& p){
  for (int i = 0; i< this->power; i++){
	this->myarray[i] =  p.myarray[i] -  this->myarray[i];
  }
  return *this;
}


int Poly::evaluate (int v){
  int val = v; // The evaluated value
  int expo;
  int total = 0;
  for (int i = 0; i < 4; i++){

	if (i == 0){// First polynomial store
	  myarray[i] = myarray[i];
	}
	else if (i  == 1){ // Second polynomial store multiply 
	  myarray[i] = myarray[i]*val;
	}
	else if (i > 1){// 
	  expo  = pow(val,i);
	  myarray[i] = myarray[i]*expo ;
	}
  }
 
  for (int i = 0; i <  power ; i++){// Sum of the evaluation
	total = total +  myarray[i];
  }
  return total;
}


ostream& operator<<(ostream& out, const Poly& p){ // Output operator overloading
  p.write(out);
  return out;
}

istream& operator>>(istream& in,  Poly& p){ // Input operator overloading
  p.read(in);
  return in;
}
