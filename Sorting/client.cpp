#include "mysort.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <sys/time.h>
using namespace std;

int main(){
  int size[] = {10 , 100, 1000, 5000, 10000, 50000, 100000};
  for (int i = 0; i < 7; i++){
	int* A = new int[size[i]];
	for (int j = 0; j < size[i]; j++){
	  A[j] = rand() % 1000000;
    }
	struct timeval start, finish;
	gettimeofday(&start, NULL);
    InsertionSort(A, size[i]);
	gettimeofday(&finish, NULL);
    double t = (1000000.0*(finish.tv_sec - start.tv_sec) + (finish.tv_usec - start.tv_usec)) / 1000.0;
    cout << "For input size " << size[i] << ": " << t << " milliseconds" << endl;
    delete[] A;
  }
  
  for (int i = 0; i < 7; i++){
	int* A = new int[size[i]];
	for (int j = 0; j < size[i]; j++){
	  A[j] = rand() % 1000000;
	}
	struct timeval start, finish;
	gettimeofday(&start, NULL);
	MergeSort(A, size[i]);
	gettimeofday(&finish, NULL);
	double t = (1000000.0*(finish.tv_sec - start.tv_sec) + (finish.tv_usec - start.tv_usec)) / 1000.0;
	cout << "For input size " << size[i] << ": " << t << " milliseconds" << endl;
	delete[] A;
  }
  
  for (int i = 0; i < 7; i++){
	int* A = new int[size[i]];
	for (int j = 0; j < size[i]; j++){
	  A[j] = rand() % 1000000;
	}
	struct timeval start, finish;
	gettimeofday(&start, NULL);
	QuickSort(A, size[i]);
	gettimeofday(&finish, NULL);
	double t = (1000000.0*(finish.tv_sec - start.tv_sec) + (finish.tv_usec - start.tv_usec)) / 1000.0;
	cout << "For input size " << size[i] << ": " << t << " milliseconds" << endl;
	delete[] A;
  }
  
  return 0;
}
