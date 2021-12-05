// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
private:
	int stepX[8] = {-2, -2, -1, -1,  2, 2,  1,  1};
	int stepY[8] = {-1,  1, -2,  2, -1, 1, -2, 2};

private:
	bool validPosition(int xPos, int yPos, int numBlocks) {
		bool valid_x = (0 < xPos && xPos <= numBlocks);
		bool valid_y = (0 < yPos && yPos <= numBlocks);

		return (valid_x && valid_y);
	}

public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
		vector<vector<bool>> visited(N+1);
		queue<pair<int, pair<int, int>>> boardPos;

		fill(visited.begin(), visited.end(), vector<bool>(N+1, false));
		
		boardPos.push(make_pair(0, make_pair(KnightPos[0], KnightPos[1]))); // 0-dist, 0-index KnightPos
		visited[KnightPos[0]][KnightPos[1]] = true;

		while(boardPos.empty() == false) {
			auto currPos = boardPos.front();
			boardPos.pop();

			int currDist = currPos.first;
			int currX = currPos.second.first, currY = currPos.second.second;

			if(currX == TargetPos[0] && currY == TargetPos[1])
				return currDist;
			
			for(int i=0; i<8; i++) {
				int newDist = currDist+1;
				int newX = currX + stepX[i];
				int newY = currY + stepY[i];

				if(validPosition(newX, newY, N) && visited[newX][newY] == false) {
					boardPos.push(make_pair(newDist, make_pair(newX, newY)));
					visited[newX][newY] = true;
				}
			}
		}
		return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends