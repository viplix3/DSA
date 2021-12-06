// https://practice.geeksforgeeks.org/problems/minimum-cost-path3833/1/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
private:
    int step_x[4] = {-1, 0, 0, 1};
    int step_y[4] = {0, 1, -1, 0};

public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int numRows = grid.size(), numCols = grid[0].size();
        int currX = 0, currY = 0;
        vector<vector<int>> dist(numRows, vector<int>(numCols, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                        greater<pair<int, pair<int, int>>>> minHeap;

        dist[currX][currY] = grid[currX][currY];
        minHeap.push(make_pair(dist[currX][currY], make_pair(currX, currY))); // cost, gridX, gridY
        
        while(minHeap.empty() == false) {
            auto currNode = minHeap.top();
            minHeap.pop();
            
            int currCost = currNode.first;
            currX = currNode.second.first;
            currY = currNode.second.second;
            
            for(int i=0; i<4; i++) {
                int newX = currX + step_x[i];
                int newY = currY + step_y[i];
                
                if((0 <= newX && newX < numRows) && (0 <= newY && newY < numCols)) {
                    int nodeAddCost = currCost + grid[newX][newY];
                    
                    if(nodeAddCost < dist[newX][newY]) {
                        dist[newX][newY] = nodeAddCost;
                        minHeap.push(make_pair(nodeAddCost, make_pair(newX, newY)));
                    }
                }
            }
        }
        
        return dist[numRows-1][numCols-1];
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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends