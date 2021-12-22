#include <bits/stdc++.h>
using namespace std;

int getLISLength(vector<int>& sequence) {
	int numElems = sequence.size();

	vector<int> LISTail;
	LISTail.emplace_back(sequence[0]);
	int currTailElems = 1;

	for(int currIdx = 1; currIdx < numElems; currIdx++) {
		if(sequence[currIdx] > LISTail[currTailElems - 1]) {
			LISTail.emplace_back(sequence[currIdx]);
			currTailElems += 1;
		}
		else {
			auto itr = upper_bound(LISTail.begin(), LISTail.end(), sequence[currIdx]);
			*itr = sequence[currIdx];
		}
	}

	return LISTail.size();
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
