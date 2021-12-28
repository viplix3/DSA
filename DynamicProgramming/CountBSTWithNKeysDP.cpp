#include <bits/stdc++.h>
using namespace std;

int getNumBSTs(int numKeys) {
	vector<int> numBSTs(numKeys + 1, 0);
	
	numBSTs[0] = 1;

	for(int currRoot = 1; currRoot <= numKeys; currRoot++)
		for(int subTreeRoot = 0; subTreeRoot < currRoot; subTreeRoot++)
			numBSTs[currRoot] += numBSTs[subTreeRoot] * numBSTs[currRoot - subTreeRoot - 1];
	
	return numBSTs[numKeys];
}

int main() {
	int numKeys;

	numKeys = 1;
	cout << "Num keys: " << numKeys << endl;
	cout << "Num BST with " << numKeys << " : " << getNumBSTs(numKeys) << endl;
	cout << endl;

	numKeys = 2;
	cout << "Num keys: " << numKeys << endl;
	cout << "Num BST with " << numKeys << " : " << getNumBSTs(numKeys) << endl;
	cout << endl;

	numKeys = 3;
	cout << "Num keys: " << numKeys << endl;
	cout << "Num BST with " << numKeys << " : " << getNumBSTs(numKeys) << endl;
	cout << endl;

	numKeys = 0;
	cout << "Num keys: " << numKeys << endl;
	cout << "Num BST with " << numKeys << " : " << getNumBSTs(numKeys) << endl;
	cout << endl;

	numKeys = 4;
	cout << "Num keys: " << numKeys << endl;
	cout << "Num BST with " << numKeys << " : " << getNumBSTs(numKeys) << endl;
	cout << endl;

	numKeys = 5;
	cout << "Num keys: " << numKeys << endl;
	cout << "Num BST with " << numKeys << " : " << getNumBSTs(numKeys) << endl;
	cout << endl;

	return 0;
}
