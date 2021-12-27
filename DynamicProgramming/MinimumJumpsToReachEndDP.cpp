#include <bits/stdc++.h>
using namespace std;

int getMinJumps(vector<int> jumpSize, int currIdx) {
	int lastSlotIdx = jumpSize.size();
	vector<int> minJumpsToReach(lastSlotIdx, INT_MAX);

	minJumpsToReach[0] = 0; // We don't need any jumps to reach 0th slot as going from left to right

	for(int destSlot = 1; destSlot < lastSlotIdx; destSlot++) {
		for(int sourceSlot = 0; sourceSlot < destSlot; sourceSlot++) {
			if(sourceSlot + jumpSize[sourceSlot] >= (destSlot)) {
				if(minJumpsToReach[sourceSlot] != INT_MAX) // If source slot is reachable
					minJumpsToReach[destSlot] = min(minJumpsToReach[sourceSlot] + 1, minJumpsToReach[destSlot]);
			}
		}
	}

	return minJumpsToReach[lastSlotIdx - 1];
}

template<typename T>
ostream& operator<<(ostream& outStream, vector<T> data) {
	for(T datum : data)
		outStream << datum << " ";
	return outStream;
}

int main() {
	vector<int> testArray;

	testArray = {3, 4, 2, 1, 2, 1};
	cout << "Allowed jumps from all the indices: " << testArray << endl;
	cout << "Minimum jumps to reach end: " << getMinJumps(testArray, 0) << endl;
	cout << endl;

	testArray = {4, 1, 5, 3, 1, 3, 2, 1, 8};
	cout << "Allowed jumps from all the indices: " << testArray << endl;
	cout << "Minimum jumps to reach end: " << getMinJumps(testArray, 0) << endl;
	cout << endl;

	return 0;
}
