// https://leetcode.com/problems/combination-sum/

class Solution {
private:
    void findAllSumCombinations(vector<vector<int>>& sumCombinations,
                               vector<int>& currCombination, int currSelectionIdx,
                               vector<int>& candidates, int targetSum) {
        if(currSelectionIdx == candidates.size()) {
            if(targetSum == 0)
                sumCombinations.emplace_back(currCombination);
            return;
        }
        
        if(targetSum >= candidates[currSelectionIdx]) {
            // Pick
            currCombination.push_back(candidates[currSelectionIdx]);
            findAllSumCombinations(sumCombinations, currCombination, currSelectionIdx,
                               candidates, targetSum - candidates[currSelectionIdx]);
            currCombination.pop_back();
            
        }
        
        // Don't pick
        findAllSumCombinations(sumCombinations, currCombination, currSelectionIdx+1,
                           candidates, targetSum);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> sumCombinations;
        vector<int> currCombination;
        int currSelectionIdx = 0;
        
        findAllSumCombinations(sumCombinations, currCombination, currSelectionIdx,
                              candidates, target);
        return sumCombinations;
    }
};