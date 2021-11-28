// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    int step_x[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
    int step_y[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

private:
    void DFS(vector<vector<char>>& grid, int grid_x, int grid_y, int xMax, int yMax) {
        if((0 <= grid_x && grid_x < xMax) && (0 <= grid_y && grid_y < yMax)) {
            if(grid[grid_x][grid_y] == '1') {
                grid[grid_x][grid_y] = '2';
                
                for(int i=0; i<8; i++)
                    DFS(grid, grid_x + step_x[i], grid_y + step_y[i], xMax, yMax);
            }
        }
    }

public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int numConnectedComponents = 0;
        int numRows = grid.size(), numCols = grid[0].size();
        
        for(int i=0; i < numRows; i++) {
            for(int j=0; j < numCols; j++) {
                if(grid[i][j] == '1') {
                    DFS(grid, i, j, numRows, numCols);
                    numConnectedComponents += 1;
                }
            }
        }
        
        return numConnectedComponents;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends