#include <bits/stdc++.h>
using namespace std;

int getMaxSumIncreasingSubsequence(vector<int> arr) {
	int numElems = arr.size();
	vector<int> maxSumIncSubsequence(numElems, 0);

	maxSumIncSubsequence[0] = arr[0];

	for(int currIdx = 1; currIdx < numElems; currIdx++) {

		for(int prevIdx = currIdx - 1; prevIdx >=0; prevIdx--) {
			if(arr[currIdx] > arr[prevIdx])
				maxSumIncSubsequence[currIdx] = max(maxSumIncSubsequence[prevIdx] + arr[currIdx],
														maxSumIncSubsequence[currIdx]);
		}
	}

	int maxSum = INT_MIN;
	for(int sumValue : maxSumIncSubsequence)
		maxSum = max(sumValue, maxSum);
	
	return maxSum;
}

ostream& operator<<(ostream& outStream, vector<int> data) {
	for(int datum : data)
		outStream << datum << " ";
	return outStream;
}

int main() {
	vector<int> testArr;

	testArr = {3, 20, 4, 6, 7, 30};
	cout << "Input array: " << testArr << endl;
	cout << "Maximum sum of increasing subsequences: " << getMaxSumIncreasingSubsequence(testArr) << endl;
	cout << endl;

	testArr = {5, 10, 20};
	cout << "Input array: " << testArr << endl;
	cout << "Maximum sum of increasing subsequences: " << getMaxSumIncreasingSubsequence(testArr) << endl;
	cout << endl;

	testArr = {20, 10, 5};
	cout << "Input array: " << testArr << endl;
	cout << "Maximum sum of increasing subsequences: " << getMaxSumIncreasingSubsequence(testArr) << endl;
	cout << endl;

	return 0;
}