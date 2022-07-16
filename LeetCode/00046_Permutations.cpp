// https://leetcode.com/problems/permutations/

class Solution {
private:
    void findAllPermutations(vector<vector<int>>& allPermutations,
                            int currSelectionIdx, vector<int>& nums) {
        if(currSelectionIdx == nums.size()) {
            allPermutations.push_back(nums);
            return;
        }
        
        for(int i = currSelectionIdx; i < nums.size(); i++) {
            swap(nums[i], nums[currSelectionIdx]);
            findAllPermutations(allPermutations, currSelectionIdx+1, nums);
            swap(nums[i], nums[currSelectionIdx]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> allPermutations;
        int currSelectionIdx = 0;
        
        findAllPermutations(allPermutations, currSelectionIdx, nums);
        return allPermutations;
    }
};