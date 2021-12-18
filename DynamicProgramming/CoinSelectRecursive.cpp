#include <bits/stdc++.h>
using namespace std;

int getChoices(vector<int> coinChoices, int currSumValue, int currSelectionIdx) {
	int totalChoices = coinChoices.size();

	if(currSelectionIdx >= totalChoices || currSumValue < 0)
		return 0;
	
	if(currSumValue == 0) {
		return 1;
	}

	if(currSumValue >= coinChoices[currSelectionIdx]) {
		return getChoices(coinChoices, currSumValue - coinChoices[currSelectionIdx], currSelectionIdx) + 
				getChoices(coinChoices, currSumValue, currSelectionIdx + 1);
	}
}

int coinSelect(vector<int> coinChoices, int sumValue) {
	sort(coinChoices.begin(), coinChoices.end());
	int selectionIdx = 0;

	int numChoices = getChoices(coinChoices, sumValue, selectionIdx);

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