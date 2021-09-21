// https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
private:
	int segragate(int arr[], int n) {
		int currNegIdx = 0;

		for(int i=0; i<n; i++) {
			if(arr[i] <= 0) {
				swap(arr[i], arr[currNegIdx]);
				currNegIdx += 1;
			}
		}

		return currNegIdx;
	}

	int findMissingPosNum(int arr[], int arrSize) {
		for(int i=0; i < arrSize; i++) {
			if((abs(arr[i]) - 1 < arrSize) && (arr[abs(arr[i]) - 1] > 0))
				arr[abs(arr[i]) - 1] *= -1;
		}

		for(int i=0; i < arrSize; i++)
			if(arr[i] > 0)
				return i+1;
		
		return arrSize+1;
	}


public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
		// Move all the negatives to the beginning of the array
		int posIdx = segragate(arr, n);
		return findMissingPosNum(arr + posIdx, n - posIdx);
    } 
};

// { Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
}   // } Driver Code Ends