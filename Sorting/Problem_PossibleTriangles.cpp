// https://practice.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1/

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        sort(arr, arr+n);
        
        int count = 0;
        
        for(int c = n-1; c >= 2; c--)
        {
            int a = 0, b = c - 1;
            
            while(a < b)
            {
                if(arr[a] + arr[b] > arr[c])
                {
                    count += b - a;
                    
                    b--;
                }
                else
                {
                    a++;
                }
            }
        }
        
        return count;
    }
};


// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}  // } Driver Code Ends