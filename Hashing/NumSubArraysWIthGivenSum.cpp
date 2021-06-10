// https://practice.geeksforgeeks.org/problems/subarray-range-with-given-sum0128/1/

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    //Function to count the number of subarrays which adds to the given sum.
    int subArraySum(int arr[], int n, int sum)
    {
        int num_valid_sub_arrays = 0;
        unordered_map<int, int> num_subarrays_with_prefix_sum;
        int prefix_sum = 0;
        
        for(int i=0; i<n; i++){
            prefix_sum += arr[i];
            
            if(prefix_sum == sum)
                num_valid_sub_arrays += 1; // Found a sub-array with prefix_sum = required_sum
            
	    /* Core logic
	    	required_sum + remaining_sum = prefix_sum
		remaining_sum = prefix_sum - required_sum
			Where prefix_sum is the sum for sub-array from 0-index to current index.

		So, for the sub-array from 0-index to current index we make an assumption that a smaller sub-array
		with required_sum is part of this bigger one.
		Hence, if our assumption is true, when we take out required_sum from prefix_sum the remaining_sum (sub-array other than the required one)
		would have already been encountered by us and would be present in out hash-map.
		We will count all the sub-arrays having the remaining_sum towards the correct sub-array.
	    */
            if(num_subarrays_with_prefix_sum.find(prefix_sum - sum) != num_subarrays_with_prefix_sum.end()){
                num_valid_sub_arrays += num_subarrays_with_prefix_sum[prefix_sum - sum];
            }
            num_subarrays_with_prefix_sum[prefix_sum] += 1; // Caching the prefix_sum of the sub-array into hash-map
        }
        return num_valid_sub_arrays;
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
	    Solution obj;
	    cout<<obj.subArraySum(arr, n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends