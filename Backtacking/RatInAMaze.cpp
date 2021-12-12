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

bool solveRatInAMaze(vector<vector<int>>& grid, int currX, int currY, string& pathFollowed) {
	int numRows = grid.size(), numCols = grid[0].size();
	int stepX[] = {0, -1, 1, 0}, stepY[] = {1, 0, 0, -1}; // x-axis: vertical, y-axis: horizontal
	char currDir[] = {'R', 'U', 'D', 'L'};
	const int VISITED = -1;

	for(int i=0; i<4; i++) {
		int newX = currX + stepX[i];
		int newY = currY + stepY[i];

		if(isSafe(grid, newX, newY, numRows, numCols)) {
			grid[newX][newY] = VISITED;
			if((newX == (numRows-1)) && (newY == (numCols - 1)) || solveRatInAMaze(grid, newX, newY, pathFollowed)) {
				pathFollowed += currDir[i];
				return true;
			}
		}
	}

	return false;
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
	
	string pathFollowed = "";
	cout << boolalpha << "Rat in the maze got cheese: " << solveRatInAMaze(grid, 0, 0, pathFollowed) << endl;
	reverse(pathFollowed.begin(), pathFollowed.end());
	cout << "Path followed by the rat: " << pathFollowed << endl;

	return 0;
}