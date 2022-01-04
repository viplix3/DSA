// https://practice.geeksforgeeks.org/problems/subset-sum-problem2643/1/

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template in C++


class Solution
{
private:
	int getArraySum(int arr[], int numElems)
	{
		int arrSum = 0;

		for(int i = 0; i < numElems; i++)
			arrSum += arr[i];
		
		return arrSum;
	}

public: //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.
    bool findPartition(int arr[], int n)
    {
		int arrSum = getArraySum(arr, n);

		if(arrSum % 2) // Odd sum cannot be divided into two equal parts
			return false;

		int partitionSum = arrSum / 2;
		vector<vector<bool>> possiblePartition(n + 1, vector<bool>(partitionSum + 1));

		for(int arrIdx = 1; arrIdx <= n; arrIdx++) {
			for(int currSum = 0; currSum <= partitionSum; currSum++) {
				if(currSum == 0 || currSum < arr[arrIdx - 1])
					possiblePartition[arrIdx][currSum] = false;
				else {
						// We can create a subset with given sum without including the current element at all
					if( possiblePartition[arrIdx - 1][currSum] == true ||
						// We have a subset on which we can add the current array element to get the required sum
						possiblePartition[arrIdx - 1][currSum - arr[arrIdx - 1]] == true ||
						// Current element of array is the same as required sum
						currSum == arr[arrIdx - 1]
					  )
					  	possiblePartition[arrIdx][currSum] = true;
					else
						possiblePartition[arrIdx][currSum] = false;
				}
			}
		}

		return possiblePartition[n][partitionSum];
    }
};

// { Driver Code Starts.
int main() {
    
    //taking total testcases
    int tc;
    cin >> tc;
    while (tc--) {
        
        //taking size of array
        int n, i;
        cin >> n;
        int a[n];
        
        //inserting elements in the array
        for (i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        //calling findPartition() function and
        //printing "YES", if it returns true
        //else "NO"
        if (ob.findPartition(a, n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
  // } Driver Code Ends