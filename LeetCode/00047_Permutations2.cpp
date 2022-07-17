// https://leetcode.com/problems/permutations-ii/

// Solution 1
class Solution {
private:
    void findAllPermutations(vector<vector<int>>& allPermutations,
                            int currSelectionIdx, vector<int> nums) {
        if(currSelectionIdx == nums.size()) {
            allPermutations.push_back(nums);
            return;
        }
        
        for(int i = currSelectionIdx; i < nums.size(); i++) {
            // Don't use any other entry of array having the same value 
            // as the nums[currSelectionIdx], swapping nums[i] with a some other index
			// having the same value as nums[currSelectionIdx] would produce the same permutation
            if(i != currSelectionIdx && nums[i] == nums[currSelectionIdx])
                continue;
            
            // nums is passed by value so swapping inside of other recursive calls won't matter
            swap(nums[i], nums[currSelectionIdx]);
            findAllPermutations(allPermutations, currSelectionIdx+1, nums);
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> allPermutations;
        int currSelectionIdx = 0;
        
        sort(nums.begin(), nums.end());
        findAllPermutations(allPermutations, currSelectionIdx, nums);
        return allPermutations;
    }
};

// Solution 2: Faster, less memory usage but would be inefficient if the range of nums is large

class Solution {
private:
    void findAllPermutations(vector<vector<int>>& allPermutations,
                             vector<int>& currPermutation,  vector<int>& frequencyMap,
                             vector<int>& nums) {
        if(currPermutation.size() == nums.size()) {
            allPermutations.push_back(currPermutation);
            return;
        }
        
        for(int i = 0; i < frequencyMap.size(); i++) {
            if(frequencyMap[i] != 0) {
                frequencyMap[i] -= 1; // Using the number to count is reduced by 1
                
                int currNumSelection = i - 10;
                currPermutation.push_back(currNumSelection);
                
                // Find the permutation with remaining values in the frequency map
                findAllPermutations(allPermutations, currPermutation, frequencyMap, nums);
                
                // Cleanup after using currNumSelection
                currPermutation.pop_back();
                frequencyMap[i] += 1;
            }
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> allPermutations;
        vector<int> currPermutation;
        
        // Create a frequency map
        vector<int> frequencyMap(20);
        for(int i = 0; i < nums.size(); i++)
            frequencyMap[nums[i] + 10] += 1;
        
        findAllPermutations(allPermutations, currPermutation, frequencyMap, nums);
        return allPermutations;
    }
};