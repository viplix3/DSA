#include <bits/stdc++.h>
using namespace std;

bool isSafe(int rowIdx, int colIdx, int key, vector<vector<int>>& grid) {
	int numRows = grid.size();

	for(int i = 0; i < numRows; i++) {
		if(grid[i][colIdx] == key || grid[rowIdx][i] == key)
			return false;
	}

	int subGridSize = static_cast<int>(sqrt(numRows));
	int subGridRowBase = rowIdx - (rowIdx % subGridSize), subGridColBase = colIdx - (colIdx % subGridSize);

	for(int i = subGridRowBase; i < subGridRowBase + subGridSize; i++)
		for(int j = subGridColBase; j < subGridColBase + subGridSize; j++) {
			if(grid[i][j] == key)
				return false;
		}
	
	return true;
}

bool solveSudoku(vector<vector<int>>& grid) {
	int numRows = grid.size(), numCols = grid[0].size();
	constexpr int FREE = 0;
	const int numValues = numRows+1;
	int rowIdx = -1, colIdx = -1;

	bool emptySlot = false;
	for(int currRowIdx = 0; currRowIdx < numRows; currRowIdx++)
		for(int currColIdx = 0; currColIdx < numCols; currColIdx++)
			if(grid[currRowIdx][currColIdx] == FREE) {
				rowIdx = currRowIdx;
				colIdx = currColIdx;
				emptySlot = true;
				break;
			}
	
	if(emptySlot == false)
		return true;

	for(int currInsertValue = 1; currInsertValue < numValues; currInsertValue++) {
		if(isSafe(rowIdx, colIdx, currInsertValue, grid)) {
			grid[rowIdx][colIdx] = currInsertValue;

			if(solveSudoku(grid) == true)
				return true;
			else
				grid[rowIdx][colIdx] = FREE;
		}
	}

	return false;
}

std::ostream& operator<<(std::ostream& outStream, vector<vector<int>> data) {
	int numRows = data.size(), numCols = data[0].size();

	for(int i=0; i<numRows; i++) {
		for(int j=0; j<numCols; j++)
			outStream << data[i][j] << " ";
		outStream << endl;
	}

	return outStream;
}

int main() {
	constexpr int FREEGRID = 0;
	int numCells;
	cout << "Enter number of cells in sudoku to be solved: ";
	cin >> numCells;

	vector<vector<int>> sudokuGrid(numCells, vector<int>(numCells, FREEGRID));

	cout << "\nEnter the partially filled sudoku grid (0 for empty grid)" << endl;
	
	for(int i=0; i<numCells; i++)
		for(int j=0; j<numCells; j++) {
			int value;
			cin >> value;
			sudokuGrid[i][j] = value;
		}
	
	bool isSolvable = solveSudoku(sudokuGrid);
	if(!isSolvable)
		cout << "\nGiven sudoku grid is not solvable" << endl;
	else
		cout << "\nOne of the possible solutions of the given sudoku grid \n" << sudokuGrid << endl;
	
	return 0;
}