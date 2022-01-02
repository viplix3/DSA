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
        vector<int> numWays(n + 1, 0);

        numWays[0] = 0;
        numWays[1] = 1;
        numWays[2] = 2;

        for(int currFloor = 3; currFloor <= n; currFloor++)
            numWays[currFloor] = (numWays[currFloor - 1] % MODULO_VAL) + (numWays[currFloor - 2] % MODULO_VAL);

        return (numWays[n] % MODULO_VAL);
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
