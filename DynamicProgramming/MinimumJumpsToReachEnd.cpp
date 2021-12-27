#include <bits/stdc++.h>
using namespace std;

int getMinJumps(vector<int> jumpSize, int currIdx) {
	if(currIdx == 1)
		return 0;

	int totalSlots = jumpSize.size();
	int totalJumps = INT_MAX;

	for(int currSlot = 0; currSlot < currIdx - 1; currSlot++)
		if(currSlot + jumpSize[currSlot] >= (currIdx - 1)) { // We can reach the current cell
			int jumpsToReachCurrSlot = getMinJumps(jumpSize, currSlot + 1);

			if(jumpsToReachCurrSlot != INT_MAX)
				totalJumps = min(jumpsToReachCurrSlot + 1, totalJumps);
		}

	return totalJumps;
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
	cout << "Minimum jumps to reach end: " << getMinJumps(testArray, testArray.size()) << endl;
	cout << endl;

	testArray = {4, 1, 5, 3, 1, 3, 2, 1, 8};
	cout << "Allowed jumps from all the indices: " << testArray << endl;
	cout << "Minimum jumps to reach end: " << getMinJumps(testArray, testArray.size()) << endl;
	cout << endl;

	return 0;
}