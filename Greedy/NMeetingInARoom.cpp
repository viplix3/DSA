// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
private:
    static bool sortingComparator(pair<int, int> meeting1, pair<int, int> meeting2) {
        if(meeting1.second == meeting2.second)
            return (meeting1.first < meeting2.first);
            
        return (meeting1.second < meeting2.second);
    }

public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> meetingTimes;
        
        for(int i=0; i<n; i++)
            meetingTimes.emplace_back(make_pair(start[i], end[i]));
        sort(meetingTimes.begin(), meetingTimes.end(), sortingComparator);
        
        int lastMeetingIdx = 0;
        int numPossibleMeetings = 1;
        
        for(int currMeetingIdx = 1; currMeetingIdx < n; currMeetingIdx++)
            if(meetingTimes[currMeetingIdx].first > meetingTimes[lastMeetingIdx].second) {
                numPossibleMeetings += 1;
                lastMeetingIdx = currMeetingIdx;
            }
        
        return numPossibleMeetings;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends