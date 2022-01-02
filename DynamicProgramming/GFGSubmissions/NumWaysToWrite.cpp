// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to count the number of different ways in which n can be 
    //written as a sum of two or more positive integers.
    int countWays(int n)
    {
		vector<int> numWays(n + 1, 0);
		numWays[0] = 1; // Base case;

		for(int currChoice = 1; currChoice < n; currChoice++)
			for(int currNum = currChoice; currNum <= n; currNum++) {
				numWays[currNum] += numWays[currNum - currChoice];
		}

		return numWays[n];
    }
};

// { Driver Code Starts.
// Driver program
int main()
{
    //taking number of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.countWays(n)<<endl;
    }
    return 0;
}  // } Driver Code Ends