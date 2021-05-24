// https://practice.geeksforgeeks.org/problems/maximum-water-between-two-buildings/1/

//Initial Template for C++


// C++ implementation of the approach 
#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to return the maximum water that can be stored.
    int maxWater(int height[], int n) 
    { 
        int startIdx = 0, endIdx = n-1;
        int maxTrappedWater = 0;
        
        while(startIdx <= endIdx){
            int currTrappedWater = min(height[startIdx], height[endIdx]) * (endIdx - startIdx - 1);
            maxTrappedWater = max(maxTrappedWater, currTrappedWater);
            
            if(height[startIdx] < height[endIdx])
                startIdx += 1;
            else
                endIdx -= 1;
        }
        return maxTrappedWater;
        
    } 
};



// { Driver Code Starts.

// Driver code 
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int height[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>height[i];
        }
        Solution ob;
        cout<<(ob.maxWater(height, n))<<endl;
    }

	 
} 

  // } Driver Code Ends