// https://leetcode.com/problems/subsets-ii/

class Solution {
private:
    void findPowerSet(vector<vector<int>>& powerSet,
                      vector<int>& currSubSet, int currSelectionIdx,
                      vector<int>& nums) {
        
        powerSet.push_back(currSubSet);
        for(int i = currSelectionIdx; i < nums.size(); i++) {
            if(i > currSelectionIdx && nums[i] == nums[i-1])
                continue; // Skip duplicates
            
            currSubSet.push_back(nums[i]);
            findPowerSet(powerSet, currSubSet, i+1, nums);
            currSubSet.pop_back();
        }
    }
        
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> powerSet;
        vector<int> currSubSet;
        int currSelectionIdx = 0;
        
        sort(nums.begin(), nums.end());
        findPowerSet(powerSet, currSubSet, currSelectionIdx, nums);
        return powerSet;
    }
};