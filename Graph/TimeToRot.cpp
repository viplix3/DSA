// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
private:
    int step_x[4] = {-1, 1, 0, 0};
    int step_y[4] = {0, 0, -1, 1};
    
public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int totalTimeToRot = 0;
        int numRows = grid.size(), numCols = grid[0].size();
		queue<pair<int, int>> rottenNodes;
		
		for(int i=0; i<numRows; i++)
			for(int j=0; j<numCols; j++)
				if(grid[i][j] == 2)
					rottenNodes.push(make_pair(i, j));
		
		rottenNodes.push(make_pair(-1, -1)); // If we reach this, one unit time has passed

		while(rottenNodes.empty() == false) {
			pair<int, int> curr = rottenNodes.front();
			rottenNodes.pop();

			if(curr.first == -1 && curr.second == -1) {
				if(rottenNodes.empty() == true)
					continue;

				totalTimeToRot += 1;
				rottenNodes.push(make_pair(-1, -1));
				continue;
			}

			for(int i=0; i<4; i++) {
				int newX = curr.first + step_x[i];
				int newY = curr.second + step_y[i];

				if((0 <= newX && newX < numRows) && (0 <= newY && newY < numCols))
					if(grid[newX][newY] == 1) {
						grid[newX][newY] = 2;
						rottenNodes.push(make_pair(newX, newY));
					}
			}
		}

		for(int i=0; i<numRows; i++)
			for(int j=0; j<numCols; j++)
				if(grid[i][j] == 1)
					return -1;
		
		return totalTimeToRot;

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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends