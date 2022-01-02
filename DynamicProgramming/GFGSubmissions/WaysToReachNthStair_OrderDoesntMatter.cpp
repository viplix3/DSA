// https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int m)
    {
		vector<int> numWays(m+1, 0);

		// Base cases
		numWays[0] = 1, numWays[1] = 1;

		for(int stepSize = 1; stepSize <= 2; stepSize++)
			for(int currStair = 2; currStair <= m; currStair++) {
				numWays[currStair] += numWays[currStair - stepSize];
		}
		
		return numWays[m];
    }
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}  // } Driver Code Ends