#include <bits/stdc++.h>
using namespace std;

int getMaxSum(vector<int> arr, int endIdx) {
	if(endIdx == 1)
		return arr[endIdx - 1];
	
	else if(endIdx == 2)
		return max(arr[endIdx - 1], arr[endIdx - 2]);

	return max( getMaxSum(arr, endIdx - 1), // Don't include the last element in the sum
				getMaxSum(arr, endIdx - 2) + arr[endIdx - 1]); // Include the last element in the sum
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