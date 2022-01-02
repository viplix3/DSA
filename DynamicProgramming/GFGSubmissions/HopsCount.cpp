// https://practice.geeksforgeeks.org/problems/count-number-of-hops-1587115620/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
private:
	static constexpr int MODULO_VAL = 1000000007;

public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
		if(n < 0)
			return 0;

		if(n == 0)
			return 1;

		if(n == 1 || n == 2)
			return n;

		// Recursive Solution
		/*
		return (
				  (countWays(n - 1) % MODULO_VAL) +
				  (countWays(n - 2) % MODULO_VAL) +
				  (countWays(n - 3) % MODULO_VAL)
				) % MODULO_VAL;
		*/

		// O(N) solution
		/*
		vector<long long> numHops(n + 1, 0);

		// Base case
		numHops[0] = 1, numHops[1] = 1, numHops[2] = 2;

		for(int currHop = 3; currHop <= n; currHop++)
			numHops[currHop] = (numHops[currHop - 1] % MODULO_VAL) + (numHops[currHop - 2] % MODULO_VAL) +
									(numHops[currHop - 3] % MODULO_VAL);
		
		return (numHops[n] % MODULO_VAL);
		*/

		long long numHops1 = 1, numHops2 = 1, numHops3 = 2;
		long long totalHops = 0;

		for(long long currHop = 3; currHop <= n; currHop++) {
			totalHops = (numHops1 % MODULO_VAL) + (numHops2 % MODULO_VAL) + (numHops3 % MODULO_VAL);
			numHops1 = numHops2;
			numHops2 = numHops3;
			numHops3 = totalHops;
		}

		return (totalHops % MODULO_VAL);
    }
};


// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}
  // } Driver Code Ends