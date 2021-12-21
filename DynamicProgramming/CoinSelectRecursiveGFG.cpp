#include <bits/stdc++.h>
using namespace std;

int getChoices(vector<int> coinChoices, int currSumValue, int currSelectionIdx) {
	if(currSumValue == 0)
		return 1;

	if(currSelectionIdx == 0)
		return 0;

	int currNumChoices = getChoices(coinChoices, currSumValue, currSelectionIdx - 1); // Skip current coin

	if(currSumValue >= coinChoices[currSelectionIdx - 1]) // Choose current coin
		currNumChoices += getChoices(coinChoices, currSumValue - coinChoices[currSelectionIdx - 1], currSelectionIdx);

	return currNumChoices;
}

int coinSelect(vector<int> coinChoices, int sumValue) {
	int currSelectionIdx = coinChoices.size();
	int numChoices = getChoices(coinChoices, sumValue, currSelectionIdx);
	return numChoices;
}

ostream& operator<<(ostream& outStream, vector<int> data) {
	for(int datum : data)
		outStream << datum << " ";

	return outStream;
}

int main() {
	int sumValue;
	vector<int> coinChoices;

	coinChoices = {1, 2, 3};
	sumValue = 4;
	cout << "Coin choices: " << coinChoices << endl;
	cout << "Required sum values: " << sumValue << endl;
	cout << "Number of ways to get the sum: " << coinSelect(coinChoices, sumValue) << endl;
	cout << endl;

	coinChoices = {2, 5, 3, 6};
	sumValue = 10;
	cout << "Coin choices: " << coinChoices << endl;
	cout << "Required sum values: " << sumValue << endl;
	cout << "Number of ways to get the sum: " << coinSelect(coinChoices, sumValue) << endl;
	cout << endl;

	// coinChoices = {};
	// sumValue = ;
	// cout << "Coin choices: " << coinChoices << endl;
	// cout << "Required sum values: " << sumValue << endl;
	// cout << "Number of ways to get the sum: " << coinSelect(coinChoices, sumValue, 0) << endl;
	// cout << endl;

	return 0;
}
