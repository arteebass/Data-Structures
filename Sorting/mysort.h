/*
  Name: Rueben Tiow
  Last Modification: 11/18/16
  Program: This program implements three sorting algorithms and measure their time efficiencies
  for various input sizes.
                              Time Efficiency for various input sizes in milliseconds
______________________________________________________________________________________________
Sort Alg.     |   10   |   100   |   1000   |   5000   |   10000   |   50000   |   1000000   |
______________________________________________________________________________________________
InsertionSort |  0.001 |  0.009  |  0.867   |  21.27   |  84.693   |  2121.41  |   8550.47   |
______________________________________________________________________________________________
MergeSort     |  0.002 |  0.016  |  0.173   |  1.01    |  2.071    |  11.634   |   24.364    |
______________________________________________________________________________________________
QuickSort     |  0.001 |  0.009  |  0.135   |  0.883   |  1.656    |  9.48     |   20.518    |
______________________________________________________________________________________________
*/

#ifndef _MY_SORT_H_
#define _MY_SORT_H_
#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <sys/time.h>
using namespace std;

void InsertionSort(int A[], int n);
void MergeSort(int A[], int n);
void QuickSort(int A[], int n);
void MergeSortHelper(int A[], int i, int j);
void Merge(int A[], int low, int high, int mid);
void QuickSortHelper(int A[], int i, int j);
int Split(int A[], int i, int j);
#endif
