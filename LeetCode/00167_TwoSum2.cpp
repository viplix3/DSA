// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

// Simple 2-pointer for sorted array sum
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int numElems = numbers.size();
        int beginIdx = 0, endIdx = numElems - 1;
        
        vector<int> resultIndices;
        
        while(beginIdx < endIdx) {
            int currSum = numbers[beginIdx] + numbers[endIdx];
            
            if(currSum == target) {
                resultIndices.push_back(beginIdx + 1);
                resultIndices.push_back(endIdx + 1);
                break;
            }
            
            if(currSum < target)
                beginIdx++;
            else
                endIdx--;
        }
        
        return resultIndices;
    }
};