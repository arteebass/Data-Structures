/*
 *File: client.cpp
 *Author: Yingwu Zhu
 *Warning: do not change this file and use it as is.
 *Last Modififcation: 10/21/2016
 */
#include <set>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include "bst.h"
using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Format: " << argv[0] << " [data file]" << endl;
		return 0;
	}
	ifstream fin(argv[1]);
	int cases;
	fin >> cases;
	int passed = 0;
	for (int i = 1; i <= cases; i++) {
		cout << "Checking test case #" << i << " ... ";
		BST T;
		set<int> S;
		int n, x;
		fin >> n;
		bool ok = true;
		vector<int> tmp;
		int rem = 0;
		for (int j = 0; j < n; j++) {
			fin >> x;
			T.Insert(x);
			S.insert(x);
			ok &= (T.Search(x) && T.RecurSearch(x));
			if (tmp.empty()) 
				tmp.push_back(x);
			if (rand()%10 < 3) {
				T.Erase(tmp[0]);
				S.erase(tmp[0]);
				ok &= (T.Search(tmp[0]) == false);
				tmp.pop_back();
				rem++;
			}
		}
		if (rem <n)	
			ok &= (T.MaxElement() == *S.rbegin());
		while (!S.empty() && !T.Empty()) {
			int x = T.MinElement();
			ok &= (x == *S.begin());
			T.Erase(x);
			S.erase(S.begin());
		}
		cout << (ok ? "Passed!" : "Failed") << endl;
		passed += ok;
	}
	cout << passed << " of " << cases << " test cases have passed!\n";
 	if (passed == cases)
		cout << endl << "Congratulations! Good to Submit Your Code\n";
	else if ((double)passed/cases >= 0.95)
		cout << endl << "You are almost there, but need to fix some bugs.\n";
	else
		cout << endl << "Your code needs a lot of fixes for submission\n";	
	return 0;
}
