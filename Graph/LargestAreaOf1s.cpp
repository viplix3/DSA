// https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
private:
    int step_x[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
    int step_y[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

private:
    void DFS(vector<vector<int>>& grid, int x, int y, int xMax, int yMax, int& numElems) {
        bool valid_x = (0 <= x && x < xMax);
        bool valid_y = (0 <= y && y < yMax);
        
        if(!valid_x || !valid_y)
            return;
        
        bool blocked_cell = (grid[x][y] == 0);
        bool visited_cell = (grid[x][y] == -1);
        
        if(blocked_cell || visited_cell)
            return;
        
        grid[x][y] = -1;
        numElems += 1;
        for(int i=0; i<8; i++)
            DFS(grid, x + step_x[i], y + step_y[i], xMax, yMax, numElems);
    }
    
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        int maxElems = INT_MIN;
        int numRows = grid.size(), numCols = grid[0].size();
        
        for(int i=0; i<numRows; i++)
            for(int j=0; j<numCols; j++) {
                int currNumElems = 0;
                if(grid[i][j] == 1)
                    DFS(grid, i, j, numRows, numCols, currNumElems);
                maxElems = max(currNumElems, maxElems);
            }
        
        return maxElems;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends