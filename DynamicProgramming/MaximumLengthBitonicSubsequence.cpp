#include <bits/stdc++.h>
using namespace std;

int getMaxBitonicSubsequence(vector<int> arr) {
	int numElems = arr.size();
	vector<int> lisArr(numElems, 1);
	vector<int> ldsArr(numElems, 1);

	for(int currIdx = 1; currIdx < numElems; currIdx++) {
		for(int prevIdx = currIdx - 1; prevIdx >=0; prevIdx--)
			if(arr[currIdx] > arr[prevIdx])
				lisArr[currIdx] = max(lisArr[prevIdx] + 1, lisArr[currIdx]);
	}

	for(int currIdx = numElems - 2; currIdx >=0; currIdx--) {
		for(int prevIdx = currIdx + 1; prevIdx < numElems; prevIdx++)
			if(arr[currIdx] > arr[prevIdx])
				ldsArr[currIdx] = max(ldsArr[prevIdx] + 1, ldsArr[currIdx]);
	}

	int maxLength = INT_MIN;
	for(int i = 0; i < numElems; i++)
		maxLength = max((lisArr[i] + ldsArr[i] - 1), maxLength);

	return maxLength;
}

ostream& operator<<(ostream& outStream, vector<int> data) {
	for(int datum : data)
		outStream << datum << " ";
	return outStream;
}

int main() {
	vector<int> testArr;

	testArr = {1, 11, 2, 10, 4, 5, 2, 1};
	cout << "Input array: " << testArr << endl;
	cout << "Maximum length of bitonic subsequence: " << getMaxBitonicSubsequence(testArr) << endl;
	cout << endl;

	testArr = {12, 11, 40, 5, 3, 1};
	cout << "Input array: " << testArr << endl;
	cout << "Maximum length of bitonic subsequence: " << getMaxBitonicSubsequence(testArr) << endl;
	cout << endl;

	testArr = {30, 20, 10};
	cout << "Input array: " << testArr << endl;
	cout << "Maximum length of bitonic subsequence: " << getMaxBitonicSubsequence(testArr) << endl;
	cout << endl;

	return 0;
}
