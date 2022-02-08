// https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1

// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int arrSize, int k) {
		int kCount = 0, greaterThanK = 0;

		for(int i = 0; i < arrSize; i++)
			if(arr[i] <= k)
				kCount += 1;
		
		// In first window if size K, number of elements > K which needs to be swapped
		for(int i = 0; i < kCount; i++)
			if(arr[i] > k)
				greaterThanK += 1;
		
		int minSwaps = greaterThanK;
		int windowInitIdx = 0, windowEndIdx = kCount;

		while(windowEndIdx < arrSize) { // Will move the window 1 cell in each iteration
			if(arr[windowInitIdx] > k)
				greaterThanK -= 1;

			if(arr[windowEndIdx] > k)
				greaterThanK += 1;

			// If current window is having lower number of elements > k, we will swap these elements out of
			// current window to make required contigous array
			minSwaps = min(greaterThanK, minSwaps);

			windowInitIdx += 1, windowEndIdx += 1;
		}

		return minSwaps;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends