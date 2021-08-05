// https://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int arrSize)
    {
        vector<int> nextMinIdx, prevMinIdx;
        stack<int> nextMinStack, prevMinStack;

        // Prev min of fist element is always nothing
        prevMinIdx.emplace_back(-1);
        prevMinStack.push(arr[0]);
        
        // Next min of last element is always nothing
        nextMinIdx.emplace_back(arrSize);
        nextMinStack.push(arr[arrSize-1]);
        
        // Calculating prevMinIdx and nextMinIdx for each idx as they will give as the
        // minimum element of various window sizes at all the array indices
        for(int i=1; i<arrSize; i++) {
            // Prev min calculations
            while(prevMinStack.empty() == false && \
                    arr[prevMinStack.top()] >= arr[i])
                prevMinStack.pop();
                
            int prevMinForCurr = prevMinStack.empty() ? -1 : prevMinStack.top();
            prevMinIdx.emplace_back(prevMinForCurr);
            prevMinStack.push(i);
            
            // Next min calculation
            while(nextMinStack.empty() == false && \
                    arr[nexMinStack.top()] >= arr[arrSize - (i+1)])
                nextMinStack.pop();
            int nextMinForCurr = nextMinStack.empty() ? arrSize : nextMinStack.top();
            nextMinIdx.emplace_back(nextMinForCurr);
            nextMinStack.push(arrSize - (i+1));
        }
        
        
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends