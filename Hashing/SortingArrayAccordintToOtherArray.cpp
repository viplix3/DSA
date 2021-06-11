// https://practice.geeksforgeeks.org/problems/relative-sorting4323/1/

//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


 // } Driver Code Ends
//User function template in C++


class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        map<int, int> frequency_map;
        
        for(auto itr: A1)
            frequency_map[itr] += 1;
        
        vector<int> A1_sorted_A2;
        
        for(int i=0; i<A2.size(); i++){
            if(frequency_map.find(A2[i]) != frequency_map.end()){
                while(frequency_map[A2[i]] != 0){
                    A1_sorted_A2.emplace_back(A2[i]);
                    frequency_map[A2[i]] -= 1;
                }
            }
        }
        
        for(auto &itr: frequency_map){
            while(itr.second != 0){
                A1_sorted_A2.emplace_back(itr.first);
                itr.second -= 1;
            }
        }
        
        return A1_sorted_A2;
    } 
};

// { Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 
  // } Driver Code Ends