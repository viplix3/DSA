// https://practice.geeksforgeeks.org/problems/word-wrap1646/1

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
private:
    int getMinCost(const vector<int>& wordLengths, int lineLength, int selectIdx, vector<int>& cost) {
        int numWords = wordLengths.size();
        int currLineChars = 0, totalCost = INT_MAX;

		if(cost[selectIdx] != -1)
			return cost[selectIdx];
        
        for(int currIdx = selectIdx; currIdx < numWords; currIdx++) {
            currLineChars += wordLengths[currIdx]; // Number of characters included in current line
            
            // Number of extra words inserted in current line (each line will have atleast 1 word)
            int numSelectedWords = currIdx - selectIdx;
            
            if((currLineChars + numSelectedWords) <= lineLength) {
                
                if(currIdx == numWords - 1) { // No cost is incurred for last line
                    totalCost = 0;
                    break;
                }
                
                // Number of space characters after linebreak as they will add to the final cost
                // The space between 2 words in a single line doesn't add any extra cost
                int currEOLSpaces = lineLength - (currLineChars + numSelectedWords);
                
                int currCost = currEOLSpaces * currEOLSpaces;
                // Get cost of printing if only the current word is selected for the current line
                // In next iteration, we will try and select more words and minimum of these costs
                // (i.e. selecting only single words or adding more word for current line) will be considered
                totalCost = min(getMinCost(wordLengths, lineLength, currIdx + 1, cost) + currCost, totalCost);
            }
            
            else break;
        }
        
		cost[selectIdx] = totalCost;
        return cost[selectIdx];
    }

public:
    int solveWordWrap(vector<int>nums, int k) 
    {
		int totalWords = nums.size();

		vector<int> cost(totalWords, -1);

        return getMinCost(nums, k, 0, cost);
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends