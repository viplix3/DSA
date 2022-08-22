// https://practice.geeksforgeeks.org/problems/closer-to-sort-1587115620/1/

// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C

// arr[]: input array
// N: size of array
// x: element to find index
//Function to find index of element x in the array if it is present.
int closer(int arr[], int N, int x) {
    
    int lowIdx = 0, highIdx = N-1;
    
    while(lowIdx <= highIdx){
        int midIdx = lowIdx + (highIdx - lowIdx) / 2;
        
        if(arr[midIdx] == x)
            return midIdx;
        else if ((midIdx != 0) && arr[midIdx-1] == x)
            return midIdx-1;
        else if((midIdx != N) && arr[midIdx+1] == x)
            return midIdx+1;
            
        if(arr[midIdx] < x){
            lowIdx = midIdx+2;
        }
        else
            highIdx = midIdx-2;
    }
    return -1;
}

// { Driver Code Starts.


int main() {

    int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);
		int *arr;
		arr = (int*)malloc(n * sizeof(int));
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		int x;
		scanf("%d", &x);
		printf("%d\n", closer(arr, n, x) );
	}
	return 0;

}  // } Driver Code Ends