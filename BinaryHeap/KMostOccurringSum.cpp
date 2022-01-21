// https://practice.geeksforgeeks.org/problems/most-occurring-elements-1587115620/1/

// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
// Function to print the k numbers with most occurrences 

class Solution
{
    public:
    //Function to return the sum of frequencies of k numbers
    //with most occurrences in an array.
    int kMostFrequent(int arr[], int n, int k) 
    {
        unordered_map<int, int> freqMap;
        
        for(int i=0; i<n; i++)
            freqMap[arr[i]] += 1;
        
        priority_queue<int> maxHeap;
        
        for(auto elem_freq : freqMap)
            maxHeap.push(elem_freq.second);
        
        int occCount = 0;
        while(maxHeap.empty() == false && k) {
            occCount += maxHeap.top();
            maxHeap.pop();
            --k;
        }
        
        return occCount;
    } 
};

// { Driver Code Starts.
// Driver program to test above 
int main() 
{
	int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.kMostFrequent(arr, n, k) << endl; 
    }

	return 0; 
} 
  // } Driver Code Ends