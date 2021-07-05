// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1/

#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends

class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int itr_1 = n-1, itr_2 = 0;
            
            while(itr_1 >= 0 &&  itr_2 < m){
                if(arr1[itr_1] >= arr2[itr_2]){
                    swap(arr1[itr_1], arr2[itr_2]);
                    itr_1--;
                    itr_2++;
                }
                else
                    itr_2++;
            }
            sort(arr1, arr1+n);
            sort(arr2, arr2+m);
        } 
};

// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends