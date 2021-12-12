#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>& grid, int x, int y, int xMax, int yMax) {
	bool valid_x = (0 <= x && x < xMax);
	bool valid_y = (0 <= y && y < yMax);

	if(!valid_x || !valid_y)
		return false;
	
	const int BLOCKED = 0, VISITED = -1;

	bool blocked_grid = (grid[x][y] == BLOCKED);
	bool visited_grid = (grid[x][y] == VISITED);

	if(blocked_grid || visited_grid)
		return false;
	return true;
}

void solveRatInAMaze(vector<vector<int>>& grid, int currX, int currY, string currPath, vector<string>& possiblePaths) {
	int numRows = grid.size(), numCols = grid[0].size();
	int stepX[] = {0, -1, 1, 0}, stepY[] = {1, 0, 0, -1}; // x-axis: vertical, y-axis: horizontal
	char currDir[] = {'R', 'U', 'D', 'L'};
	const int VISITED = -1;

	if((currX == (numRows-1)) && (currY == (numCols - 1))) {
		possiblePaths.emplace_back(currPath);
		return;
	}

	for(int i=0; i<4; i++) {
		int newX = currX + stepX[i];
		int newY = currY + stepY[i];

		if(isSafe(grid, newX, newY, numRows, numCols)) {
			int origGridData = grid[newX][newY];
			grid[newX][newY] = VISITED;
			solveRatInAMaze(grid, newX, newY, currPath + currDir[i], possiblePaths);
			grid[newX][newY] = origGridData;
		}
	}
}

int main() {
	int gridSize;
	cout << "Enter grid size: ";
	cin >> gridSize;

	vector<vector<int>> grid(gridSize, vector<int>(gridSize, 0));

	cout << "Enter grid" << endl;
	for(int i=0; i<gridSize; i++) {
		for(int j=0; j<gridSize; j++) {
			int gridVal;
			cin >> gridVal;
			grid[i][j] = gridVal;
		}
	}
	
	vector<string> possiblePaths;
	solveRatInAMaze(grid, 0, 0, "", possiblePaths);

	cout << boolalpha << "Rat in the maze got cheese: " << bool(possiblePaths.size()) << endl;

	sort(possiblePaths.begin(), possiblePaths.end());
	for(string path : possiblePaths)
		cout << "Path that can be followed by the rat: " << path << endl;

	return 0;
}