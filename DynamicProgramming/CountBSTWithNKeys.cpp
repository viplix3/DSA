#include <bits/stdc++.h>
using namespace std;

int getNumBSTs(int numKeys) {
	if(numKeys == 0)
		return 1;
	
	int numBSTs = 0;
	for(int currRoot = 1; currRoot <= numKeys; currRoot++) {
		int numKeysRight = numKeys - currRoot;
		int numKeysLeft = numKeys - numKeysRight - 1;

		int numBSTsLeft = getNumBSTs(numKeysLeft);
		int numBSTsRight = getNumBSTs(numKeysRight);
		numBSTs += (numBSTsLeft * numBSTsRight);
	}
	return numBSTs;
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