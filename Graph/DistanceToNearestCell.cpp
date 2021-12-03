// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
private:
	int step_x[4] = {-1, 0, 0, 1};
	int step_y[4] = {0, -1, 1, 0};

public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
		int numRows = grid.size(), numCols = grid[0].size();
	    vector<vector<int>> dist(numRows);
	    fill(dist.begin(), dist.end(), vector<int>(numCols, INT_MAX));

		queue<pair<int, int>> gnodes;

		for(int i=0; i<numRows; i++)
			for(int j=0; j<numCols; j++)
				if(grid[i][j] == 1) {
					dist[i][j] = 0;
					gnodes.push(make_pair(i, j));
				}
		
		while(gnodes.empty() == false) {
			pair<int, int> curr = gnodes.front();
			gnodes.pop();

			int currX = curr.first;
			int currY = curr.second;

			for(int i=0; i<4; i++) {
				int newX = currX + step_x[i];
				int newY = currY + step_y[i];

				if((0 <= newX && newX < numRows) && (0 <= newY && newY < numCols))
					if(dist[currX][currY]+1 < dist[newX][newY]) {
						dist[newX][newY] = min(dist[currX][currY]+1, dist[newX][newY]);
						gnodes.push(make_pair(newX, newY));
					}
			}
		}
		
		return dist;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends