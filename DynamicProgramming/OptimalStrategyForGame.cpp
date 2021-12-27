#include <bits/stdc++.h>
using namespace std;

int optimalStrategyToGetMax(vector<int> coinValues, int initIdx, int endIdx, int arrSum) {
	if(endIdx == initIdx + 1) // Last 2 elements
		return max(coinValues[initIdx], coinValues[endIdx]);

	return max(arrSum - optimalStrategyToGetMax(coinValues, initIdx + 1, endIdx, arrSum - coinValues[initIdx]),
				arrSum - optimalStrategyToGetMax(coinValues, initIdx, endIdx - 1, arrSum - coinValues[endIdx]));
}

int getMaxValue(vector<int> coinValues, int initIdx, int endIdx) {
	int arrSum = 0;

	for(int value : coinValues)
		arrSum += value;
	
	return optimalStrategyToGetMax(coinValues, initIdx, endIdx - 1, arrSum);
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
	cout << "Maximum value that can be picked: " << getMaxValue(testData, 0, testData.size()) << endl;
	cout << endl;

	testData = {2, 3, 15, 7};
	cout << "Coin values: " << testData << endl;
	cout << "Maximum value that can be picked: " << getMaxValue(testData, 0, testData.size()) << endl;
	cout << endl;
}