#include <bits/stdc++.h>
using namespace std;

int getMaxValue(vector<int> coinValues) {
	int numElements = coinValues.size();
	vector<vector<int>> sumValues(numElements, vector<int>(numElements, 0));

	for(int i = 0; i < numElements - 1; i++)
		sumValues[i][i+1] = max(coinValues[i], coinValues[i + 1]); // Base case of recursion

	for(int currGap = 3; currGap < numElements; currGap += 2) {
		for(int initIdx = 0; initIdx + currGap < numElements; initIdx++) {
			int endIdx = initIdx + currGap;
			sumValues[initIdx][endIdx] = max(coinValues[initIdx] + min(sumValues[initIdx + 2][endIdx],
																		sumValues[initIdx + 1][endIdx - 1]),
												coinValues[endIdx] + min(sumValues[initIdx + 1][endIdx - 1],
																			sumValues[initIdx][endIdx - 2]));
		}
	}

	return sumValues[0][numElements - 1];
}

template<typename T>
ostream& operator<<(ostream& outStream, vector<T> data) {
	for(T datum : data)
		outStream << datum << " ";
	return outStream;
}

int main() {
	vector<int> testData;

	testData = {20, 5, 4, 6};
	cout << "Coin values: " << testData << endl;
	cout << "Maximum value that can be picked: " << getMaxValue(testData) << endl;
	cout << endl;

	testData = {2, 3, 15, 7};
	cout << "Coin values: " << testData << endl;
	cout << "Maximum value that can be picked: " << getMaxValue(testData) << endl;
	cout << endl;
}

