#include <bits/stdc++.h>
using namespace std;

int coinSelect(vector<int> coinChoices, int sumValue) {
	int totalCoinChoices = coinChoices.size();

	vector<vector<int>> choices(sumValue + 1, vector<int>(totalCoinChoices + 1, 0));

	for(int i = 0; i < sumValue; i++)
		choices[0][i] = 1; // Base-case, when sum is 0, we alaways have 1 choice
	
	for(int i = 1; i < totalCoinChoices; i++)
		choices[i][0] = 0; // Invalid-case, no choices of coin but sum > 0
	
	for(int i = 1; i <= sumValue; i++) { // i signifies current sum value
		for(int j = 1; j <= totalCoinChoices; j++) { // j signifies current coin choice index
			choices[i][j] = choices[i][j-1];
			if(coinChoices[j-1] <= i)
				choices[i][j] += choices[i-coinChoices[j-1]][j];
		}
	}

	return choices[sumValue][totalCoinChoices];
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
