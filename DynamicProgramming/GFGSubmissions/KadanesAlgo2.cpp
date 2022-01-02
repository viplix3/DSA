// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-ii/1/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to return the maximum sum without adding adjacent elements.
    long long maximumSum(int arr[], int sizeOfArray)
    {
        vector<int> localMax(sizeOfArray, INT_MIN);
        
        localMax[0] = arr[0];
        int maxSum = arr[0];
        
        for(int i = 1; i < sizeOfArray; i++) {
			if(i >= 2)
				localMax[i] = max({localMax[i-2] + arr[i], localMax[i-1], arr[i]});
			else
				localMax[i] = max(localMax[i-1], arr[i]);
            maxSum = max(localMax[i], maxSum);
        }
        
        return maxSum;
    }
};

// { Driver Code Starts.


int main() {
    
    //taking total testcases
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    //taking size of array
	    int sizeOfArray;
	    cin>>sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    //inserting elements in the array
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    Solution ob;
	    //calling function maximumSum()
	    cout<<ob.maximumSum(arr,sizeOfArray)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends