// https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency-1587115621/1/

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
    public:
    
    static bool comparator(pair<int, int>& itr_1, pair<int, int>& itr_2){
        if(itr_1.second == itr_2.second)
            return (itr_1.first < itr_2.first);
        
        return (itr_1.second > itr_2.second);
    }
    
    //Complete this function
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n)
    {
        unordered_map<int, int> frequency_map;
        
        for(int i=0; i<n; i++)
            frequency_map[arr[i]] += 1;
            
        vector<pair<int, int>> frequency_vector;
        
        for(auto itr: frequency_map)
            frequency_vector.emplace_back(itr);
        
        sort(frequency_vector.begin(), frequency_vector.end(), comparator);
        
        vector<int> frequency_sorted;
        
        for(auto &itr: frequency_vector){
            while(itr.second != 0){
                frequency_sorted.emplace_back(itr.first);
                itr.second -= 1;
            }
        }
        
        return frequency_sorted;
    }
};

// { Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}

  // } Driver Code Ends