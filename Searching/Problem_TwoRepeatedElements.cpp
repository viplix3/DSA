// https://practice.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1/
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find two repeated elements.
    pair<int,int> twoRepeated (vector<int> &arr, int N)
    {
        pair<int, int> repeatingElements;
        
        for(int i=0; i<N+2; i++){
            if(arr[abs(arr[i])] > 0)
                arr[abs(arr[i])] *= -1;
            else{
                if(repeatingElements.first == 0)
                    repeatingElements.first = abs(arr[i]);
                else
                    repeatingElements.second = abs(arr[i]);
            }
        }
        return repeatingElements;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        vector<int> a;
        
        for(int i=0;i<n+2;i++){
            int temp;
            cin>>temp;
            a.push_back(temp);
        }
        
        Solution obj;
        pair<int , int>res;
        res = obj.twoRepeated(a, n);
        cout<<res.first<<" "<<res.second<<endl;
    }
    return 0;
}
  // } Driver Code Ends