#include <bits/stdc++.h>
using namespace std;

int getMinCoins(vector<int> coins, int currIdx, int value) {
	int numCoins = coins.size();
	vector<int> requiredCoins(value + 1, INT_MAX);

	requiredCoins[0] = 0; // To make a value of 0 we need 0 coins

	for(int currValue = 1; currValue <= value; currValue++)
		for(int coinChoice : coins)
			if(coinChoice <= currValue) {
				requiredCoins[currValue] = min(requiredCoins[currValue - coinChoice] + 1,
												requiredCoins[currValue]);
			}
	
	return requiredCoins[value];
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

	testData = {3, 4, 1};
	value = 5;
	cout << "Available coin denominations: " << testData << endl;
	cout << "Sum value: " << value << endl;
	cout << "Minimum coins required to make the sum: " << getMinCoins(testData, testData.size(), value) << endl;
	cout << endl;
	return 0;
}
