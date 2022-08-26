// https://leetcode.com/problems/contiguous-array/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int numElems = nums.size();
        
        for(int i = 0; i < numElems; i++)
            if(nums[i] == 0)
                nums[i] = -1;
        
        int prefixSum = 0, maxSubarrayLen = 0;
        unordered_map<int, int> hashmap; // <prefixSum, startIdx>
        
        for(int i = 0; i < numElems; i++) {
            prefixSum += nums[i];
            
            if(prefixSum == 0)
                maxSubarrayLen = max(i + 1, maxSubarrayLen);
            
            if(hashmap.find(prefixSum) != hashmap.end())
                maxSubarrayLen = max(i - hashmap[prefixSum], maxSubarrayLen);
            else
                hashmap[prefixSum] = i;
        }
        
        return maxSubarrayLen;
    }
};