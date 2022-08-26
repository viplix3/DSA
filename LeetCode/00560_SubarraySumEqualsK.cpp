// https://leetcode.com/problems/subarray-sum-equals-k/

// PrefixSum + hashmap
class Solution {
public:
    int subarraySum(vector<int>& nums, int targetSum) {
        int numElems = nums.size();
        int prefixSum = 0, numSubarrays = 0;
        unordered_map<int, int> prefixSum_hashMap; // <prefixSum, numOccurrences>
        
        for(int i = 0; i < numElems; i++) {
            prefixSum += nums[i];
            
            if(prefixSum_hashMap.find(prefixSum - targetSum) != prefixSum_hashMap.end())
                numSubarrays += prefixSum_hashMap[prefixSum - targetSum];
            
            if(prefixSum == targetSum)
                numSubarrays++;
            
            prefixSum_hashMap[prefixSum]++;
        }
        
        return numSubarrays;
    }
};