#include <bits/stdc++.h>
using namespace std;

int getMaxSum(vector<int> arr, int endIdx) {
	if(endIdx == 1)
		return arr[0];
	
	if(endIdx == 2)
		return max(arr[0], arr[1]);

	vector<int> currSum(endIdx + 1, 0);

	currSum[1] = arr[0];
	currSum[2] = max(arr[0], arr[1]);

	for(int i = 3; i <= endIdx; i++) {
		currSum[i] = max( currSum[i - 1], currSum[i - 2] + arr[i - 1]);
	}

	return currSum[endIdx];
}

template<typename T>
ostream& operator<<(ostream& outStream, vector<T> data) {
	for(T datum : data)
		outStream << datum << " ";
	return outStream;
}

int main() {
	vector<int> testArray;

	testArray = {1, 10, 2};
	cout << "Input array: " << testArray << endl;
	cout << "Maximum sum with no consevutives: " << getMaxSum(testArray, testArray.size()) << endl;
	cout << endl;

	testArray = {8, 7, 6, 10};
	cout << "Input array: " << testArray << endl;
	cout << "Maximum sum with no consevutives: " << getMaxSum(testArray, testArray.size()) << endl;
	cout << endl;

	testArray = {10, 5, 15, 20, 2, 30};
	cout << "Input array: " << testArray << endl;
	cout << "Maximum sum with no consevutives: " << getMaxSum(testArray, testArray.size()) << endl;
	cout << endl;

	return 0;
}
