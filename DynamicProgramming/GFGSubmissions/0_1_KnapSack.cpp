// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int knapSackCapacity, int wt[], int val[], int totalItems) 
    {
		vector<vector<int>> knapSackProfit(totalItems + 1, vector<int>(knapSackCapacity + 1, 0));

		for(int currItem = 1; currItem <= totalItems; currItem++) {
			for(int currWt = 1; currWt <= knapSackCapacity; currWt++) {
				if(currWt < wt[currItem - 1]) // Cannot fit in knapsack
					knapSackProfit[currItem][currWt] = knapSackProfit[currItem - 1][currWt];
				else
					knapSackProfit[currItem][currWt] = max( val[currItem - 1] + 
																knapSackProfit[currItem - 1][currWt - wt[currItem - 1]],
															knapSackProfit[currItem - 1][currWt]
														);
			}
		}

		return knapSackProfit[totalItems][knapSackCapacity];
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends