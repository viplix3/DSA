// https://leetcode.com/problems/rearrange-array-elements-by-sign/

// Uses O(N) extra space (IDK why people think this is O(1)) space
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int numElems = nums.size();
        int positiveIdx = 0, negativeIdx = 1;
        vector<int> alternatingArray(numElems);

        for(int i = 0; i < numElems; i++) {
            if(nums[i] > 0) {
                alternatingArray[positiveIdx] = nums[i];
                positiveIdx += 2;
            }
            if(nums[i] < 0) {
                alternatingArray[negativeIdx] = nums[i];
                negativeIdx += 2;
            }
        }
        
        return alternatingArray;
    }
};