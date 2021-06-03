// https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1/

#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

 // } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        sort(arr, arr+n);
        
        if(arr[0] > 0)
            return false;
        
        for(int i=0; i<n; i++){
            int left = i+1, right = n-1;
            while(left < right){
                if((arr[left] + arr[right] + arr[i]) == 0)
                    return true;
                if((arr[left] + arr[right] + arr[i]) < 0)
                    left++;
                else
                    right--;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}  // } Driver Code Ends