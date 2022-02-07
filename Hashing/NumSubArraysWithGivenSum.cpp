// https://practice.geeksforgeeks.org/problems/subarray-range-with-given-sum2804/1/

// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    int subArraySum(int arr[], int arrSize, int sum)
    {
        unordered_map<int, int> hashmap;
        int prefixSum = 0, numSubarrays = 0;
        
        for(int i = 0; i < arrSize; i++) {
            prefixSum += arr[i];

			if(prefixSum == sum)
				numSubarrays += 1;
            
            if(hashmap.find(prefixSum - sum) != hashmap.end())
                numSubarrays += hashmap[prefixSum - sum];
            hashmap[prefixSum] += 1;
        }
        
        return numSubarrays;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,sum=0;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>sum;
	    Solution ob;
	    cout<<ob.subArraySum(arr, n, sum);
	    cout<<'\n';
	}
	return 0;
}  // } Driver Code Ends