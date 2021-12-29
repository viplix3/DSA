#include <bits/stdc++.h>
using namespace std;

int MatrixChainMultiplications(vector<int> matrices, int endIdx) {
	vector<vector<int>> numMultiplications(endIdx, vector<int>(endIdx, 0));

	for(int currGap = 2; currGap < endIdx; currGap++) {
		for(int i = 0; i + currGap < endIdx; i++) {
			int j = i + currGap;
			numMultiplications[i][j] = INT_MAX;

			for(int k = i + 1; k < j; k++) {
				numMultiplications[i][j] = min (numMultiplications[i][j], 
												numMultiplications[i][k] +
												numMultiplications[k][j] + 
												matrices[i] * matrices[k] * matrices[j]
											);
			}
		}
	}

	return numMultiplications[0][endIdx-1];

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
	cout << "Minimum number of multiplication: " << MatrixChainMultiplications(testArray, testArray.size()) << endl;
	cout << endl;

	testArray = {2, 1, 3};
	cout << "Input data: " << testArray << endl;
	cout << "Minimum number of multiplication: " << MatrixChainMultiplications(testArray, testArray.size()) << endl;
	cout << endl;

	testArray = {40, 20, 30, 10, 30};
	cout << "Input data: " << testArray << endl;
	cout << "Minimum number of multiplication: " << MatrixChainMultiplications(testArray, testArray.size()) << endl;
	cout << endl;

	return 0;
}
