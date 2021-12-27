#include <bits/stdc++.h>
using namespace std;

int getMaxValue(vector<int> coinValues, int initIdx, int endIdx) {
	if(endIdx == initIdx + 1) // Last 2 elements
		return max(coinValues[initIdx], coinValues[endIdx]);

			// Choose either first or last coin, the one which would give us max sum
	return max( // We will choose in such a way that we can maximum in current iteration
				// In next iteration, opponent will choose in such a way which would maximize his output
				// This would result in giving us minimum output in next iteration
				coinValues[initIdx] + min(getMaxValue(coinValues, initIdx + 2, endIdx), // Current and opponet, both choose 1st
											getMaxValue(coinValues, initIdx + 1, endIdx - 1)), // Current choost 1st, opponent choose last
				coinValues[endIdx] + min(getMaxValue(coinValues, initIdx + 1, endIdx - 1), // Cuurent choost last, opponent choose 1st
											getMaxValue(coinValues, initIdx, endIdx - 2)) // Current and opoonent, both choose last
			);
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
	cout << "Maximum value that can be picked: " << getMaxValue(testData, 0, testData.size() - 1) << endl;
	cout << endl;

	testData = {2, 3, 15, 7};
	cout << "Coin values: " << testData << endl;
	cout << "Maximum value that can be picked: " << getMaxValue(testData, 0, testData.size() - 1) << endl;
	cout << endl;
}
