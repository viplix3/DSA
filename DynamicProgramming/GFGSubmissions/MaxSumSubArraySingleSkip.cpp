// https://practice.geeksforgeeks.org/problems/max-sum-subarray-by-removing-at-most-one-element/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



class Solution
{
    public:
    //Function to return maximum sum subarray by removing at most one element.
    int maxSumSubarray(int arr[], int n)
    {
		int forwardSubArraySum[n], backwardSubArraySum[n];

		forwardSubArraySum[0] = arr[0];
		backwardSubArraySum[n-1] = arr[n-1];
		int maxSumNoSkip = arr[0];

		for(int i = 1; i < n; i++) {
			int backIdx = (n - (i+1));
			forwardSubArraySum[i] = max(forwardSubArraySum[i-1] + arr[i], arr[i]);
			backwardSubArraySum[backIdx] = max(backwardSubArraySum[backIdx + 1] + arr[backIdx], arr[backIdx]);

			maxSumNoSkip = max(forwardSubArraySum[i], maxSumNoSkip);
		}

		int maxSum = backwardSubArraySum[1]; // subarray sum when 0th element is excluded

		for(int i = 1; i < n; i++) {
			int currIdxExcludedSum = forwardSubArraySum[i - 1] + backwardSubArraySum[i + 1];
			maxSum = max(currIdxExcludedSum, maxSum);
		}

		return max(maxSum, maxSumNoSkip);
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	
	//taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking total elements
		int n;
		cin>>n;
		int a[n];
		
		//inserting elements in the array
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		
		//calling method maxSumSubarray()
		Solution obj;
		cout<<obj.maxSumSubarray(a,n)<<endl;
	}
}

  // } Driver Code Ends