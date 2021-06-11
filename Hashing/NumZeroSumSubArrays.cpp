// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1/

//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        unordered_map<ll, ll> prefixSum_frequency_map;
        ll prefix_sum = 0;
        int num_sub_arrays = 0; 
        
        for(int i=0; i<n; i++){
            prefix_sum += arr[i];
            
            if(prefix_sum == 0)
                num_sub_arrays += 1;
                
            if(prefixSum_frequency_map.find(prefix_sum) != prefixSum_frequency_map.end())
                num_sub_arrays += prefixSum_frequency_map[prefix_sum];

            prefixSum_frequency_map[prefix_sum] += 1;
        }
	return num_sub_arrays;
    }
};

/*
I/P
2
6
0 0 5 5 0 0
10
6 -1 -3 4 -2 2 4 6 -12 -7

O/P
6
4
*/

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends