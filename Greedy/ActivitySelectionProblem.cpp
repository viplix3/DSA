// https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
private:
    static bool endTimeSortFunc(pair<int, int> p1, pair<int, int> p2) {
        return (p1.second < p2.second);
    }
public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int, int>> activityTimes;
        
        for(int i=0; i<n; i++)
            activityTimes.emplace_back(make_pair(start[i], end[i]));
        
        sort(activityTimes.begin(), activityTimes.end(), endTimeSortFunc);
        
        int lastSelected = 0;
        int numSelectedActivities = 1;
        
        for(int curr=1; curr<n; curr++)
            if(activityTimes[curr].first > activityTimes[lastSelected].second) {
                numSelectedActivities += 1;
                lastSelected = curr;
            }
            
        return numSelectedActivities;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends