// https://practice.geeksforgeeks.org/problems/sort-by-absolute-difference-1587115621/1/

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    // A[]: input array
    // N: size of array
    //Function to sort the array according to difference with given number.
    
    void absDiffMerge(int arr[], int lowIdx, int midIdx, int highIdx, int key)
    {
        int numLeft = midIdx - lowIdx + 1;
        int numRight = highIdx - midIdx;
        
        int leftArr[numLeft];
        int rightArr[numRight];
        
        for(int i=0; i<numLeft; i++)
            leftArr[i] = arr[i + lowIdx];
        
        for(int i=0; i<numRight; i++)
            rightArr[i] = arr[i + midIdx + 1];
            
        int leftItr = 0, rightItr = 0, arrItr = lowIdx;
        
        while(leftItr < numLeft && rightItr < numRight){
            if(abs(leftArr[leftItr] - key) <= abs(rightArr[rightItr] - key)){
                arr[arrItr] = leftArr[leftItr];
                leftItr++;
            }
            else{
                arr[arrItr] = rightArr[rightItr];
                rightItr++;
            }
            arrItr++;
        }
        while(leftItr < numLeft){
            arr[arrItr] = leftArr[leftItr];
            leftItr++;
            arrItr++;
        }
        while(rightItr < numRight){
            arr[arrItr] = rightArr[rightItr];
            rightItr++;
            arrItr++;
        }
    }
    
    void modifiedMergeSort(int arr[], int lowIdx, int highIdx, int key)
    {
        if(highIdx > lowIdx){
            int midIdx = lowIdx + (highIdx - lowIdx) / 2;
            modifiedMergeSort(arr, lowIdx, midIdx, key);
            modifiedMergeSort(arr, midIdx+1, highIdx, key);
            absDiffMerge(arr, lowIdx, midIdx, highIdx, key);
        }
    }
    
    void sortABS(int A[],int N, int K)
    {
       modifiedMergeSort(A, 0, N-1, K);
    }

};

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    
	    int N, diff;
	    cin>>N>>diff;
	    int A[N];
	    
	    for(int i = 0; i<N; i++)
	        cin>>A[i];
	   
	    Solution ob;
	   
	    ob.sortABS(A, N, diff);
	    
	    for(int & val : A)
	        cout<<val<<" ";
	    cout<<endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends