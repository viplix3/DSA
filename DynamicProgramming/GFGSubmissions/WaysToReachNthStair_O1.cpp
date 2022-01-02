// https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
private:
    static constexpr int MODULO_VAL = 1000000007;

public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        if(n == 0)
            return 0;
        
        if(n == 1 || n == 2)
            return n;

        int numWays1 = 1, numWays2 = 2;
        int numWaysToTargetFloor;

        for(int currFloor = 3; currFloor <= n; currFloor++) {
            numWaysToTargetFloor = (numWays1 % MODULO_VAL) + (numWays2 % MODULO_VAL);
            numWays1 = numWays2;
            numWays2 = numWaysToTargetFloor;

        }

        return (numWaysToTargetFloor % MODULO_VAL);
    }
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
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
}
  // } Driver Code Ends