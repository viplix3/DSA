// https://leetcode.com/problems/merge-intervals/

// O(N log(N)) time and O(1) space solution
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int numIntervals = intervals.size();
        vector<vector<int>> sortedIntervals;
        
        if(numIntervals == 0)
            return sortedIntervals;
        
        sort(intervals.begin(), intervals.end());
        sortedIntervals.push_back(intervals[0]);
        
        for(int i = 1; i < numIntervals; i++) {
            if(intervals[i][0] <= sortedIntervals.back()[1])
                sortedIntervals.back()[1] = max(intervals[i][1],
                                               sortedIntervals.back()[1]);
            else
                sortedIntervals.push_back(intervals[i]);
        }
        
        return sortedIntervals;
    }
};


// GitHub CoPilot solution
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> res;
		if (intervals.size() == 0) return res;
		sort(intervals.begin(), intervals.end());
		res.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i][0] <= res.back()[1]) {
				res.back()[1] = max(intervals[i][1], res.back()[1]);
			} else {
				res.push_back(intervals[i]);
			}
		}
		return res;
	}
};