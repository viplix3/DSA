// https://practice.geeksforgeeks.org/problems/x-total-shapes3617/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
private:
    int step_x[4] = {-1, 0, 0, 1};
    int step_y[4] = {0, -1, 1, 0};
    char visited = '-';

private:
    void DFS(vector<vector<char>>& grid, int x, int y, int xMax, int yMax) {
        bool valid_x = (0 <= x && x < xMax);
        bool valid_y = (0 <= y && y < yMax);
        
        if(!valid_x || !valid_y)
            return;
        
        bool invalid_grid = (grid[x][y] == 'O');
        bool visited_grid = (grid[x][y] == visited);
        
        if(invalid_grid || visited_grid)
            return;
            
        grid[x][y] = visited; // Mark current grid as visited
        
        for(int i=0; i<4; i++) // Traverse connected slots
            DFS(grid, x + step_x[i], y + step_y[i], xMax, yMax);
    }

public:
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        int numXGroups = 0;
        int numRows = grid.size(), numCols = grid[0].size();
        
        for(int i=0; i<numRows; i++)
            for(int j=0; j<numCols; j++)
                if(grid[i][j] == 'X') {
                    DFS(grid, i, j, numRows, numCols);
                    numXGroups += 1;
                }
        
        return numXGroups;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends