// https://practice.geeksforgeeks.org/problems/coin-change-number-of-ways/1/

// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to find out the number of ways to use the coins to
    //sum up to a certain required value.
    long long numberOfWays(int coins[],int numberOfCoins,int value)
    {
		vector<long long> numChoices(value + 1, 0);

		// Base case, if(value == 0), we always have 1 choice, don't choose anything
		numChoices[0] = 1;

		for(int coinChoiceIdx = 0; coinChoiceIdx < numberOfCoins; coinChoiceIdx++) {
			for(int currSumValue = coins[coinChoiceIdx]; currSumValue <= value; currSumValue++) {
				if(currSumValue >= coins[coinChoiceIdx]) // Choose current coin
					numChoices[currSumValue] += numChoices[currSumValue - coins[coinChoiceIdx]];
			}
		}
		
		return numChoices[value];
    }
};


// { Driver Code Starts.


int main() {
    
    //taking total count of testcases
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    //taking value
	    int value;
	    cin>>value;
	    
	    //taking number of coins
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    //inserting coins to the array
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    Solution obj;
	    //calling function numberOfWays
	    cout<<obj.numberOfWays(coins,numberOfCoins,value)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends