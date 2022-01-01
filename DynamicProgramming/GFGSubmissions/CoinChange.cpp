// https://practice.geeksforgeeks.org/problems/coin-change-minimum-number-of-coins/1/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//Complete this function

class Solution
{
    public:
    //Function to find the minimum number of coins to make the change 
    //for value using the coins of given denominations.
    long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value)
    {
        vector<long long> numCoins(value + 1, INT_MAX);
        
        numCoins[0] = 0; // Base-case
        
        for(int currValue = 1; currValue <= value; currValue++) {
            for(int coinIdx = 0; coinIdx < numberOfCoins; coinIdx++) {
                if(currValue >= coins[coinIdx]) // Select current coin
                    numCoins[currValue] = min( numCoins[currValue - coins[coinIdx]] + 1, numCoins[currValue]);
            }
        }
        
        return (numCoins[value] == INT_MAX) ? -1 : numCoins[value];
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
	    
	    //taking value of each coin
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    Solution obj;
	    //calling function minimumNumberOfCoins()
	    int answer=obj.minimumNumberOfCoins(coins,numberOfCoins,value);
	    
	    //printing "Not Possible" if answer is -1
	    //else printing answer
	    if(answer==-1)
	    cout<<"Not Possible"<<endl;
	    else
	    cout<<answer<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends