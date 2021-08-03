// https://practice.geeksforgeeks.org/problems/get-min-at-pop/1/

//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

stack<int> _push(int arr[],int n);

void _getMinAtPop(stack<int>s);

 // } Driver Code Ends
//User function Template for C++


//Function to push all the elements into the stack.
stack<int> _push(int arr[],int n)
{
    stack<int> minStack;
    minStack.push(arr[0]);
    
    // Only maintaining the current minimum in the stack
    for(int i=1; i<n; i++) {
        if(minStack.top() >= arr[i])
            minStack.push(arr[i]);
        else
            minStack.push(minStack.top());
   }
   
   return minStack;
}

//Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int> minStack)
{
    while(minStack.empty() == false) {
        cout << minStack.top() << " ";
        minStack.pop();
    }
    cout << "\n";
}

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    stack<int>mys=_push(arr,n);
	    _getMinAtPop(mys);
	    
	    
	    
	}
	return 0;
}

  // } Driver Code Ends