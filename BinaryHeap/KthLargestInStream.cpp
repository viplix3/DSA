// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream-1587115620/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to print kth largest element for each element in the stream.
    void kthLargest(int arr[], int n, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int i=0; i<k; i++) {
            minHeap.push(arr[i]);
            
            if(i < (k-1))
                cout << "-1 ";
            else
                cout << minHeap.top() << " ";
        }
        
        for(int i=k; i<n; i++) {
            if(arr[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(arr[i]);
            }
            
            cout << minHeap.top() << " ";
        }
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k, n;
		cin>>k>>n;
	    
	    int arr[n];
	    for(int i = 0; i<n ; ++i)
	        cin>>arr[i];
        Solution ob;
	    ob.kthLargest(arr, n, k);
	    cout<<endl;
	    
	    
	}
	return 0;
}
  // } Driver Code Ends