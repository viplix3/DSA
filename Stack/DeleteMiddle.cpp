// https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1/

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
	void deleteMid(stack<int>& stackOrig, int sizeOfStack)
    {
        stack<int> stackReversed;
        int midIdx = ceil(sizeOfStack / 2.0) - 1;
        int currIdx = 0;

		while(stackOrig.empty() == false) {
			stackReversed.push(stackOrig.top());
			stackOrig.pop();
		}
        
        while(stackReversed.empty() == false) {
            if(currIdx == midIdx) {
				midIdx = INT_MIN;
				stackReversed.pop();
                continue;
			}
            
            stackOrig.push(stackReversed.top());
            stackReversed.pop();
            currIdx += 1;
        }
    }

};


// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}
  // } Driver Code Ends