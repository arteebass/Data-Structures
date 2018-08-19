#include <fstream>
#include <cstdlib>
#include <algorithm>
#include "chaintab.h"
#include "lptab.h"
#include "qptab.h"
using namespace std;
void printVector(const vector<int>& A, ostream& out) {
	for (int i = 0; i < A.size(); i++) {
		if (i)
			out << " ";
		out << A[i];
	}
	out << endl;
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "Format: " << argv[0] << " [input file] [output file]" << endl;
		return 0;
	}
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	int n;
	fin >> n;
	for (int i = 1; i <= n; i++) {
		int m;
		fin >> m;
		ChainTab T1;
		LPTab T2;
		QPTab T3;
		fout << "Case #" << i << ":" << endl;
		vector<int> A(m);
		vector<int> B;
		for (int j = 0; j < m; j++) {
			fin >> A[j];
			T1.Insert(A[j]);
			T2.Insert(A[j]);
			T3.Insert(A[j]);
			if (rand() % 20 < 1) {
				T1.Print(B);
				sort(B.begin()+1, B.end());
				printVector(B, fout);
				T2.Print(B);
                sort(B.begin()+1, B.end());
                printVector(B, fout);
				T3.Print(B);
                sort(B.begin()+1, B.end());
                printVector(B, fout);
			}			
			if (rand() % 10 < 1) {
				int x = rand() % (j+1);
				if (rand() % 10 < 5)
					x = rand() % 1000;
				T1.Remove(x);
			}
		}
		int k = rand() % A.size() + 1;
		for (int i = 0; i < k; i++) {
			T1.Remove(A[i]);
			T2.Remove(A[i]);
			T3.Remove(A[i]);
		}
		T1.Print(B);
        sort(B.begin()+1, B.end());
        printVector(B, fout);
        T2.Print(B);
        sort(B.begin()+1, B.end());
        printVector(B, fout);
        T3.Print(B);
        sort(B.begin()+1, B.end());
        printVector(B, fout);
	}
	fout.close();
	fin.close();
	return 0;
}
