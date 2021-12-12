// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1/

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
private:
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
    
public:
    vector<string> findPath(vector<vector<int>> &grid, int n) {
        vector<string> possiblePaths;
        int numRows = grid.size(), numCols = grid[0].size();
        
        if(grid[0][0] == 0 || grid[numRows-1][numCols-1] == 0) {
            possiblePaths.push_back("-1");
            return possiblePaths;
        }
        
        
        grid[0][0] = -1;
        solveRatInAMaze(grid, 0, 0, "", possiblePaths);
        
        if(possiblePaths.size() == 0)
            possiblePaths.push_back("-1");
        
        sort(possiblePaths.begin(), possiblePaths.end());
        return possiblePaths;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends