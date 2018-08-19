#include "mysort.h"
void InsertionSort(int A[], int n){
  for (int i = 1; i < n; i++){
	int temp = A[i];
	int j;
	for(j = i-1; j >= 0 && A[j] > temp; j--){
	  A[j+1] = A[j];
	}
	A[j+1] = temp;
  }
}

	  

void MergeSort(int A[], int n){
  int i = 0;
  int j = n-1;
  MergeSortHelper(A, i, j);
}

void MergeSortHelper(int A[], int i, int j){
  if (i < j){
	int mid = i+(j-i)/2;
	MergeSortHelper(A, i, mid);
	MergeSortHelper(A, mid+1, j);
	Merge(A, i, mid, j);
  }
}

void Merge(int A[], int low, int mid, int high){
  int* temp = new int[high-low+1]; // temporary storage
  int left = low, right = mid+1, k = 0;
  while (left <= mid && right <= high){
	if(A[left] <= A[right])
	  temp[k++] = A[left++];
	else
	  temp[k++] = A[right++];
  }
  while (left<= mid)
	temp[k++] = A[left++];
  while (right <= high)
	temp[k++] = A[right++];
  for (int p = 0; p < high-low+1; p++)
	A[low+p] = temp[p];
  delete[] temp;
}


void QuickSort(int A[], int n){
  int i = 0;
  int j = n-1;
  QuickSortHelper(A, i, j);
}

void QuickSortHelper(int A[], int i, int j){
  if (i < j){
	int pivot = Split(A, i, j);
	QuickSortHelper(A, i, pivot-1);
	QuickSortHelper(A, pivot+1, j);
  }
  //else list has 0 or 1 element and requires no sorting
}

int Split(int A[], int first ,int last){
  int p = first + (rand()%(last-first+1));
  swap(A[first],A[p]);
  int piv = A[first];
  int pos = first;
  for (int k = (first+1); k <= last; k++){
	if (A[k] <= piv){
	  pos++;
	  swap(A[k],A[pos]);
	}
  }
  swap(A[first],A[pos]);
  return pos; // pos is the pivot's final position
}

