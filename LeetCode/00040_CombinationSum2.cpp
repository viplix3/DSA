// https://leetcode.com/problems/combination-sum-ii/

class Solution {
private:
    void findAllSumCombinations(vector<vector<int>>& allCombinations,
                               vector<int>& currCombination, int currSelectionIdx,
                               vector<int>& candidates, int targetSum) {
        if(targetSum == 0) {
            allCombinations.emplace_back(currCombination);
            return;
        }
        
        for(int i = currSelectionIdx; i < candidates.size(); i++) {
            if(i > currSelectionIdx && candidates[i] == candidates[i-1])
                continue;
            if(targetSum < candidates[i])
                break;
            
            currCombination.push_back(candidates[i]);
            findAllSumCombinations(allCombinations, currCombination, i+1,
                               candidates, targetSum - candidates[i]);
            currCombination.pop_back();
        } 
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> allCombinations;
        vector<int> currCombination;
        int currSelectionIdx = 0;
        
        sort(candidates.begin(), candidates.end());
        findAllSumCombinations(allCombinations, currCombination, currSelectionIdx,
                              candidates, target);
        return allCombinations;
    }
};