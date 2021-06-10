// https://practice.geeksforgeeks.org/problems/positive-negative-pair5209/1/

// Initial function template for C++

#include <bits/stdc++.h>
#include <unordered_map>
#include <math.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    //Function to return list containing all the pairs having both
    //negative and positive values of a number in the array.
    vector <int> findPairs(int arr[], int n) 
    {
        unordered_set<int> arr_hash;
        vector<int> pos_neg_pairs;
        
        for(int i=0; i<n; i++){
            if(arr_hash.find(abs(arr[i])) != arr_hash.end()){
                pos_neg_pairs.emplace_back(-abs(arr[i]));
                pos_neg_pairs.emplace_back(abs(arr[i]));
            }
            else
                arr_hash.insert(abs(arr[i]));
        }
        if(pos_neg_pairs.size() == 0)
            pos_neg_pairs.emplace_back(0);
        return pos_neg_pairs;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        vector <int> res = obj.findPairs(arr, n);
    	if(res.size()!=0)
    	{
    		for (int i : res) 
            	cout << i << " ";
        	cout << endl;	
    	}
    	else
    		cout<<0<<endl;
    }

    return 0;
}  // } Driver Code Ends