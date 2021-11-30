// https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
private:
    int step_x[4] = {-1, 0, 0, 1};
    int step_y[4] = {0, -1, 1, 0};
    
private:
    bool DFS(vector<vector<int>>& grid, int x, int y, int xMax, int yMax) {
        bool valid_x = (0 <= x && x < xMax);
        bool valid_y = (0 <= y && y < yMax);
        
        if(!valid_x || !valid_y)
            return false;
        
        bool blocked_grid = (grid[x][y] == 0);
        bool visited_grid = (grid[x][y] == -1);
        
        if(blocked_grid || visited_grid)
            return false;
        
        if(grid[x][y] == 2) // Destination grid found
            return true;
        else
            grid[x][y] = -1; // Mark current grid cell as visited
            
        for(int i=0; i<4; i++) {
            if(DFS(grid, x + step_x[i], y + step_y[i], xMax, yMax))
                return true;
        }
        
        return false;
    }
    
public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int numRows = grid.size(), numCols = grid[0].size();
        
        for(int i=0; i < numRows; i++)
            for(int j=0; j < numCols; j++)
                if(grid[i][j] == 1 && DFS(grid, i, j, numRows, numCols))
                    return true;
        
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends