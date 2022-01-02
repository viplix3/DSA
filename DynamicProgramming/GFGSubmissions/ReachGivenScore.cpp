// https://practice.geeksforgeeks.org/problems/reach-a-given-score1418/1/

// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll count(ll n);

int main()
{
    //taking total testcases
	int t;
	cin>>t;
	
	while(t--)
	{
	    //taking the score
		ll n;
		cin>>n;
		
		//calling function count()
		cout << count(n) << "\n";
	}
	return 0;
}// } Driver Code Ends


//User function tempate for C++


//Function to find the number of distinct combinations to reach the given score.
ll count(ll n) 
{
    vector<ll> numCombinations(n + 1, 0);
    numCombinations[0] = 1;
    
    vector<int> scoreChoices = {3, 5, 10};
    
    for(int scoreChoice : scoreChoices)
        for(int currScore = scoreChoice; currScore <= n; currScore++) {
            numCombinations[currScore] += numCombinations[currScore - scoreChoice];
        }
    
    return numCombinations[n];
}
