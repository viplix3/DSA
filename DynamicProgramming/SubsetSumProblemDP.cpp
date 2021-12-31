#include <bits/stdc++.h>
using namespace std;

int getNumSubsets(vector<int> testArray, int requiredSum) {
	int numElements = testArray.size();
	vector<vector<int>> numSubsets(numElements + 1, vector<int>(requiredSum + 1, 0));

	for(int currElementIdx = 0; currElementIdx <= numElements; currElementIdx++)
		numSubsets[currElementIdx][0] = 1; // Base case: 0 sum sub-set
	
	for(int currElementIdx = 1; currElementIdx <= numElements; currElementIdx++) {
		for(int currSum = 0; currSum <= requiredSum; currSum++) {
			numSubsets[currElementIdx][currSum] = numSubsets[currElementIdx-1][currSum]; // Skip current element

			if(currSum >= testArray[currElementIdx - 1])
				numSubsets[currElementIdx][currSum] += numSubsets[currElementIdx][currSum - testArray[currElementIdx - 1]];
		}
	}

	return numSubsets[numElements][requiredSum];
}


ostream& operator<<(ostream& outStream, vector<int> data) {
	for(int datum : data)
		outStream << datum << " ";
	return outStream;
}

int main() {
	vector<int> testArray;
	int sum;

	testArray = {10, 5, 2, 3, 6};
	sum = 8;
	cout << "Test array: " << testArray << endl;
	cout << "Required sum: " << sum << endl;
	cout << "Num subsets having sum " << sum << ": " << getNumSubsets(testArray, sum) << endl;
	cout << endl;

	testArray = {1, 2, 4};
	sum = 4;
	cout << "Test array: " << testArray << endl;
	cout << "Required sum: " << sum << endl;
	cout << "Num subsets having sum " << sum << ": " << getNumSubsets(testArray, sum) << endl;
	cout << endl;

	testArray = {10, 20, 15};
	sum = 37;
	cout << "Test array: " << testArray << endl;
	cout << "Required sum: " << sum << endl;
	cout << "Num subsets having sum " << sum << ": " << getNumSubsets(testArray, sum) << endl;
	cout << endl;

	testArray = {10, 20, 15};
	sum = 0;
	cout << "Test array: " << testArray << endl;
	cout << "Required sum: " << sum << endl;
	cout << "Num subsets having sum " << sum << ": " << getNumSubsets(testArray, sum) << endl;
	cout << endl;

	testArray = {0, 10, 20, 15};
	sum = 0;
	cout << "Test array: " << testArray << endl;
	cout << "Required sum: " << sum << endl;
	cout << "Num subsets having sum " << sum << ": " << getNumSubsets(testArray, sum) << endl;
	cout << endl;

	testArray = {10, 20, 15};
	sum = 25;
	cout << "Test array: " << testArray << endl;
	cout << "Required sum: " << sum << endl;
	cout << "Num subsets having sum " << sum << ": " << getNumSubsets(testArray, sum) << endl;
	cout << endl;

	return 0;
}
