#include <bits/stdc++.h>
using namespace std;

bool isSafePlacement(int rowIdx, int colIdx, vector<vector<int>>& solutionMatrix) {
	int numRows = solutionMatrix.size(), numCols = solutionMatrix[0].size();
	int BLOCKED = 1;

	// If no other column (occurring before the column being filled) of current row is filled,
	// then we can put the queen in the row
	// No need to check the right side of current col is we are filling cols from left to right so nothing on right
	// side of current col is filled
	for(int currColIdx = 0; currColIdx < colIdx; currColIdx++)
		if(solutionMatrix[rowIdx][currColIdx] == BLOCKED)
			return false;

	// Need to check if any of the entries in the left part of upper and lower diagonal of (rowIdx, colIdx)
	// is filled if yes, current position is not safe
	// No need to check the right side of current col is we are filling cols from left to right so nothing on right
	// side of current col is filled
	for(int currRowIdx = rowIdx, currColIdx = colIdx; currRowIdx >=0 && currColIdx >= 0;
		currRowIdx--, currColIdx--)
		if(solutionMatrix[currRowIdx][currColIdx] == BLOCKED)
			return false;

	for(int currRowIdx = rowIdx, currColIdx = colIdx; currRowIdx < numRows && currColIdx >= 0;
		currRowIdx++, currColIdx--)
		if(solutionMatrix[currRowIdx][currColIdx] == BLOCKED)
			return false;

	return true;
}

bool solveNQueenProblem(int currColIdx, vector<vector<int>>& solutionMatrix) {
	int numRows = solutionMatrix.size(), numCols = solutionMatrix[0].size();
	int BLOCKED = 1, FREE = 0;

	if (currColIdx == numCols) // All the queens have been placed as we are placing from col-0 to col-N
		return true;
	
	for(int currRowIdx=0; currRowIdx < numRows; currRowIdx++)
		if(isSafePlacement(currRowIdx, currColIdx, solutionMatrix))
		{
			solutionMatrix[currRowIdx][currColIdx] = BLOCKED;
			if(solveNQueenProblem(currColIdx+1, solutionMatrix))
				return true;
			solutionMatrix[currRowIdx][currColIdx] = FREE;
		}

	return false;
}

std::ostream& operator<<(std::ostream& outStream, std::vector<std::vector<int>> data) {
	int numRows = data.size(), numCols = data[0].size();

	for(int i=0; i<numRows; i++) {
		for(int j=0; j<numCols; j++)
			outStream << data[i][j] << " ";
		cout << "\n";
	}

	return outStream;
}

int main() {
	int N;
	cout << "Enter N for solving the N-Queen problem: ";
	cin >> N;

	vector<vector<int>> solutionMatrix(N, vector<int>(N, 0));
	bool solvable = solveNQueenProblem(0, solutionMatrix);
	
	if(!solvable)
		cout << "Solution for the given " << N << "-Queen problem doesn't exist" << endl;
	else
		cout << "One of the possible solutions for the given " << N << "-Queen problem\n" << solutionMatrix << endl;
}