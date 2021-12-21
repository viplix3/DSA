#include <bits/stdc++.h>
using namespace std;

int coinSelect(vector<int> coins, int requiredSumValue) {
	int totalCoinChoices = coins.size();

	// rowIdx depics currSum, colIdx depicts currCoinChoice
	vector<vector<int>> choices(requiredSumValue + 1, vector<int>(totalCoinChoices + 1, 0));

	for(int currCoinChoice = 0; currCoinChoice <= totalCoinChoices; currCoinChoice++)
		choices[0][currCoinChoice] = 1; // Base-case, when sum is 0, we alaways have 1 choice
	
	for(int currSumValue = 1; currSumValue <= requiredSumValue; currSumValue++)
		choices[currSumValue][0] = 0; // Invalid-case, no choices of coin but sum > 0
	
	for(int currSumValue = 1; currSumValue <= requiredSumValue; currSumValue++) {
		for(int currCoinChoice = 1; currCoinChoice <= totalCoinChoices; currCoinChoice++) {
			// Skipping the current coin, if current coin is skipped, #choices will be same as that for last coin
			choices[currSumValue][currCoinChoice] = choices[currSumValue][currCoinChoice-1];

			// Choosing current coin
			if(coins[currCoinChoice - 1] <= currSumValue)
				choices[currSumValue][currCoinChoice] += choices[currSumValue - coins[currCoinChoice - 1]][currCoinChoice];
		}
	}

	return choices[requiredSumValue][totalCoinChoices];
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
