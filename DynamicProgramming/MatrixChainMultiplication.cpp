#include <bits/stdc++.h>
using namespace std;

int MatrixChainMultiplications(vector<int> matrices, int initIdx, int endIdx) {
	if(initIdx == endIdx)
		return 0; // Only single matrix available

	int numMultiplications, minMultiplication = INT_MAX;

	for(int partitionIdx = initIdx; partitionIdx < endIdx; partitionIdx++) {
		numMultiplications = MatrixChainMultiplications(matrices, initIdx, partitionIdx) + // Multiply first k matrices
								MatrixChainMultiplications(matrices, partitionIdx + 1, endIdx) + // Multiply last k matrices
								matrices[initIdx - 1] * matrices[partitionIdx] * matrices[endIdx];
		minMultiplication = min(numMultiplications, minMultiplication);
	}

	return minMultiplication;
}

ostream& operator<<(ostream& outStream, vector<int> data) {
	for(int datum : data)
		outStream << datum << " ";
	return outStream;
}

int main() {
	vector<int> testArray;

	testArray = {2, 1, 3, 4};
	cout << "Input data: " << testArray << endl;
	cout << "Minimum number of multiplication: " << MatrixChainMultiplications(testArray, 1, testArray.size() - 1) << endl;
	cout << endl;

	testArray = {2, 1, 3};
	cout << "Input data: " << testArray << endl;
	cout << "Minimum number of multiplication: " << MatrixChainMultiplications(testArray, 1, testArray.size() - 1) << endl;
	cout << endl;

	testArray = {40, 20, 30, 10, 30};
	cout << "Input data: " << testArray << endl;
	cout << "Minimum number of multiplication: " << MatrixChainMultiplications(testArray, 1, testArray.size() - 1) << endl;
	cout << endl;

	return 0;
}