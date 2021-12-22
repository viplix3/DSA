#include <bits/stdc++.h>
using namespace std;

int getLISLength(vector<int>& sequence) {
	int numElems = sequence.size();

	vector<int> LISLengths(numElems, 0);
	LISLengths[0] = 1;

	for(int currIdx = 1; currIdx < numElems; currIdx++) {
		int currLIS = 1;

		for(int prevIdx = currIdx - 1; prevIdx >= 0; prevIdx--) {
			if(sequence[prevIdx] < sequence[currIdx])
				currLIS = max(LISLengths[prevIdx] + 1, currLIS);
		}

		LISLengths[currIdx] = currLIS;
	}

	int maxLISLength = INT_MIN;
	for(int LIS : LISLengths)
		maxLISLength = max(LIS, maxLISLength);
	
	return maxLISLength;
}

ostream& operator<<(ostream& outStream, vector<int> data) {
	for(int datum : data)
		outStream << datum << " ";
	return outStream;
}

int main() {
	vector<int> testData;

	testData = {3, 4, 2, 8, 10};
	cout << "Input sequence: " << testData << endl;
	cout << "Length of longest increasing subSequence: " << getLISLength(testData) << endl;
	cout << endl;

	testData = {4, 10, 6, 5, 8, 11, 2, 20};
	cout << "Input sequence: " << testData << endl;
	cout << "Length of longest increasing subSequence: " << getLISLength(testData) << endl;
	cout << endl;

	testData = {10, 20, 30};
	cout << "Input sequence: " << testData << endl;
	cout << "Length of longest increasing subSequence: " << getLISLength(testData) << endl;
	cout << endl;

	testData = {30, 20, 10};
	cout << "Input sequence: " << testData << endl;
	cout << "Length of longest increasing subSequence: " << getLISLength(testData) << endl;
	cout << endl;

	return 0;
}