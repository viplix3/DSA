#include <bits/stdc++.h>
using namespace std;

int getMinCoins(vector<int> coins, int currIdx, int value) {
	if(value == 0)
		return 0;

	int numCoins = INT_MAX;

	for(int i = 0; i < currIdx; i++) {
		if(coins[i] <= value) {
			int currNumCoins = getMinCoins(coins, currIdx, value - coins[i]);
			if(currNumCoins != INT_MAX)
				numCoins = min(currNumCoins + 1, numCoins);
		}
	}

	return numCoins;
}

ostream& operator<<(ostream& outStream, vector<int> data) {
	for(int datum : data)
		outStream << datum << " ";
	return outStream;
}

int main() {
	vector<int> testData;
	int value;

	testData = {25, 10, 5};
	value = 30;
	cout << "Available coin denominations: " << testData << endl;
	cout << "Sum value: " << value << endl;
	cout << "Minimum coins required to make the sum: " << getMinCoins(testData, testData.size(), value) << endl;
	cout << endl;

	testData = {9, 6, 5, 1};
	value = 11;
	cout << "Available coin denominations: " << testData << endl;
	cout << "Sum value: " << value << endl;
	cout << "Minimum coins required to make the sum: " << getMinCoins(testData, testData.size(), value) << endl;
	cout << endl;

	return 0;
}