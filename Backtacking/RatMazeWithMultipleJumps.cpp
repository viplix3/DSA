// https://practice.geeksforgeeks.org/problems/rat-maze-with-multiple-jumps-1587115621/1/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

void print(int n, vector<int> sol[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(int n, vector<int> maze[]);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> maze[n];
        for (int i = 0; i < n; i++) {
            maze[i].assign(n, 0);
            for (int j = 0; j < n; j++) cin >> maze[i][j];
        }

        solve(n, maze);
    }
    return 0;
}
// } Driver Code Ends


bool isSafe(int N, int currRowIdx, int currColIdx, vector<int> maze[]) {
	constexpr int BLOCKED = 0, VISITED = -1;

	bool valid_x = (currRowIdx < N);
	bool valid_y = (currColIdx < N);
	
	if(!valid_x || !valid_y)
		return false;

	bool solution_grid = (currRowIdx == (N-1) && currColIdx == (N-1));
	
	if(solution_grid)
		return true;
	
	bool blocked_grid = (maze[currRowIdx][currColIdx] == BLOCKED);
	bool visited_grid = (maze[currRowIdx][currColIdx] == VISITED);

	if(blocked_grid || visited_grid)
		return false;
	
	return true;
}


bool solveRatMazeMultipleJumps(int N, int currX, int currY, vector<int> maze[], vector<int> solutionMatrix[]) {
	if(currX == (N-1) && currY == (N-1))
		return true;

	int stepX[] = {0, 1}, stepY[] = {1, 0}; // {forward, downward}
	constexpr int numSteps = 2, VISITED = 1, FREE = 0;

	// for(int stepSize = maze[currX][currY]; stepSize > 0; stepSize--) { // This would find actual mimimum jumps
	for(int stepSize = 1; stepSize <= maze[currX][currY]; stepSize++) { // This is what the test cases expect
		for(int i = 0; i < numSteps; i++) {
			int newX = currX + (stepSize * stepX[i]);
			int newY = currY + (stepSize * stepY[i]);

			if(isSafe(N, newX, newY, maze)) {
				solutionMatrix[newX][newY] = VISITED;
				if(solveRatMazeMultipleJumps(N, newX, newY, maze, solutionMatrix))
					return true;
				
				solutionMatrix[newX][newY] = FREE;
			}
		}
	}

	return false;
}

//Function to find the minimum number of Hops required for the rat to 
//reach from the source block to the destination block. 
void solve(int N, vector<int> maze[]) 
{
	vector<int> solutionMatrix[N];
	for(int i=0; i<N; i++)
		solutionMatrix[i].assign(N, 0);

	solutionMatrix[0][0] = 1;
	bool solutionExists = solveRatMazeMultipleJumps(N, 0, 0, maze, solutionMatrix);

	if(!solutionExists) {
		cout << "-1" << endl;
		return;
	}
	else
		print(N, solutionMatrix);
}