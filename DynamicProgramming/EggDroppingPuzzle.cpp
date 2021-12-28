#include <bits/stdc++.h>
using namespace std;

int solveEggDroppingPuzzle(int numEggs, int numFloors) {
	if(numEggs == 1)
		return numFloors;
	if(numFloors == 1)
		return 1;
	if(numFloors == 0)
		return 0;
	
	int numTrials = INT_MAX;

	for(int currFloor = 1; currFloor <= numFloors; currFloor++) {
		numTrials = min(
						// Egg breaks from curr floor
						max(solveEggDroppingPuzzle(numEggs - 1, currFloor - 1), // If egg breaks from curr floor, we will try a lower floor
							solveEggDroppingPuzzle(numEggs, numFloors - currFloor)) // Egg doesn't break from curr floor
						, numTrials); // One of the cases would be tried to adding 1
	}

	return (numTrials + 1);
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