// https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1
// O(N) extra space solutuion -> Super easy
// O(1) extra space solution -> Super easy, I cheated.
// 1. https://www.geeksforgeeks.org/rearrange-array-maximum-minimum-form-set-2-o1-extra-space/ and 
// 2. https://www.youtube.com/watch?v=ZRoVWxBngX0&feature=emb_logo). 

// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// This function wants you to modify the given input
// array and no need to return anything
// arr: input array
// n: size of array
void rearrange(long long *arr, int n) 
{ 
	
    int max_idx = n - 1, min_idx = 0;
    
    // store maximum element of array
    int max_elem = arr[n - 1]+1;
    
    // traverse array elements
    for (int i = 0; i < n; i++) {
        // at even index : we have to put
        // maximum element
        if (i % 2 == 0) {
        arr[i] += (arr[max_idx] % max_elem) * max_elem;
        max_idx--;
        }
    
        // at odd index : we have to put minimum element
        else {
            arr[i] += (arr[min_idx] % max_elem) * max_elem;
            min_idx++;
        }
    }
    
    // array elements back to it's original form
    for (int i = 0; i < n; i++)
        arr[i] = arr[i] / max_elem;
	 
}

// { Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        //calling rearrange() function
        rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 
  // } Driver Code Ends