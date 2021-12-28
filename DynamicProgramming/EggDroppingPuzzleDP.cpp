#include <bits/stdc++.h>
using namespace std;

int solveEggDroppingPuzzle(int numEggs, int numFloors) {
	vector<vector<int>> numTrials(numFloors + 1, vector<int>(numEggs + 1, 0));

	for(int currFloor = 0; currFloor <= numFloors; currFloor++)
		numTrials[currFloor][1] = currFloor; // Base case: only one egg
	
	for(int currEgg = 0; currEgg <= numEggs; currEgg++) {
		numTrials[0][currEgg] = 0; // Base case: no floor
		numTrials[1][currEgg] = 1; // Base case: only one floor
	}

	for(int currFloor = 2; currFloor <= numFloors; currFloor++) {
		for(int currNumEggs = 2; currNumEggs <= numEggs; currNumEggs++) {

			numTrials[currFloor][currNumEggs] = INT_MAX;

			for(int trialFloor = 1; trialFloor <= currFloor; trialFloor++)
				numTrials[currFloor][currNumEggs] = min( 1 + max( numTrials[trialFloor - 1][numEggs - 1], // Egg breaks
																	numTrials[currFloor - trialFloor][numEggs]) // Egg doesn't break
														, numTrials[currFloor][currNumEggs]);
		}
	}

	return numTrials[numFloors][numEggs];
}

int main() {
	int numEggs, numFloors, numTrials;

	numEggs = 1;
	numFloors = 10;
	cout << "Number of provided eggs: " << numEggs << endl;
	cout << "Number of floors: " << numFloors << endl;
	numTrials = solveEggDroppingPuzzle(numEggs, numFloors);
	cout << "Minimum trials required to find threshold floor: " << numTrials << endl;
	cout << endl;

	numEggs = 2;
	numFloors = 10;
	cout << "Number of provided eggs: " << numEggs << endl;
	cout << "Number of floors: " << numFloors << endl;
	numTrials = solveEggDroppingPuzzle(numEggs, numFloors);
	cout << "Minimum trials required to find threshold floor: " << numTrials << endl;
	cout << endl;

	return 0;
}
