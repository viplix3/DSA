// https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int numElems = nums.size();
        int currConsecutiveOnes = 0, maxConsecutiveOnes = 0;
        
        for(int i = 0; i < numElems; i++) {
            if(nums[i] == 0)
                currConsecutiveOnes = 0;
            else {
                currConsecutiveOnes++;
                maxConsecutiveOnes = max(currConsecutiveOnes, maxConsecutiveOnes);
            }
        }
        
        return maxConsecutiveOnes;
    }
};