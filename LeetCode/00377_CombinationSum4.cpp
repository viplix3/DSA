// https://leetcode.com/problems/combination-sum-iv/

// Recursive solution: Gives TLE
class Solution {
private:
    int findNumberOfCombinations(vector<int>& nums, int currIdx, int targetSum) {
        if(currIdx >= nums.size())
            return 0;
        
        if(targetSum == 0)
            return 1;
        
        int pickCombinations = 0, dontPickCombinations = 0;
        
        // Pick and start from 0 index as (1, 1, 2) and (2, 1, 1) are counted as
        // 2 separate combinations
        if(nums[currIdx] <= targetSum)
            pickCombinations = findNumberOfCombinations(nums, 0, targetSum - nums[currIdx]);
        
        //Don't pick
        dontPickCombinations = findNumberOfCombinations(nums, currIdx + 1, targetSum);
        
        return pickCombinations + dontPickCombinations;
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        int startingIdx = 0;
        
        return findNumberOfCombinations(nums, startingIdx, target);
    }
};


// Memoization
class Solution {
private:
    int findNumberOfCombinations(vector<int>& nums, int currIdx, int targetSum,
                                vector<int>& cache) {
        if(currIdx >= nums.size())
            return 0;
        
        if(targetSum == 0)
            return 1;
        
        if(cache[targetSum] != -1)
            return cache[targetSum];
        
        int pickCombinations = 0, dontPickCombinations = 0;
        
        // Pick and start from 0 index as (1, 1, 2) and (2, 1, 1) are counted as
        // 2 separate combinations
        if(nums[currIdx] <= targetSum)
            pickCombinations = findNumberOfCombinations(nums, 0,targetSum - nums[currIdx],
                                                       cache);
        
        //Don't pick
        dontPickCombinations = findNumberOfCombinations(nums, currIdx + 1, targetSum,
                                                        cache);
        
        return cache[targetSum] = pickCombinations + dontPickCombinations;
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        int startingIdx = 0;
        vector<int> cache(target + 1, -1);
        
        return findNumberOfCombinations(nums, startingIdx, target, cache);
    }
};


// Tabulation
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int numElems = nums.size();
        vector<double> sumCombinations(target + 1); // Using double to avoid interger overflow
        sumCombinations[0] = 1;
        
        for(int currSum = 1; currSum <= target; currSum++)
            for(int i = 0; i < numElems; i++) {
                if(nums[i] <= currSum)
                    sumCombinations[currSum] += sumCombinations[currSum - nums[i]];
            }
        
        return sumCombinations[target];
    }
};