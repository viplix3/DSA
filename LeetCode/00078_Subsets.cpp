// https://leetcode.com/problems/subsets/

class Solution {
private:
    void findPowerSet(vector<vector<int>>& powerSet, vector<int>& currSubset,
                     int currIdx, vector<int>& nums) {
        if(currIdx == nums.size()) {
            powerSet.emplace_back(currSubset);
            return;
        }
        
        // Pick current element
        currSubset.push_back(nums[currIdx]);
        findPowerSet(powerSet, currSubset, currIdx+1, nums);
        
        // Don't pick current element
        currSubset.pop_back();
        findPowerSet(powerSet, currSubset, currIdx+1, nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerSet;
        vector<int> currSubset;
        int currIdx = 0;
        
        findPowerSet(powerSet, currSubset, currIdx, nums);
        
        return powerSet;
    }
};