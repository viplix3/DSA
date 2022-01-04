// https://practice.geeksforgeeks.org/problems/cutted-segments1642/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int length, int x, int y, int z)
    {
		vector<int> numCuts(length + 1, INT_MIN);
		numCuts[0] = 0;

		for(int currLength = 1; currLength <= length; currLength++) {
			if(currLength >= x)
				numCuts[currLength] = max(numCuts[currLength - x], numCuts[currLength]);
			if(currLength >= y)
				numCuts[currLength] = max(numCuts[currLength - y], numCuts[currLength]);
			if(currLength >= z)
				numCuts[currLength] = max(numCuts[currLength - z], numCuts[currLength]);
			
			if(numCuts[currLength] != INT_MIN)
				numCuts[currLength] += 1;
		}

		return (numCuts[length] == INT_MIN) ? 0 : numCuts[length];
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends