// https://leetcode.com/problems/find-pivot-index/

// prefix-suffix sum
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int numElems = nums.size(), suffixSum = 0;
        
        for(int i = 0; i < numElems; i++)
            suffixSum += nums[i];
        
        int prefixSum = 0;
        for(int pivotIdx = 0; pivotIdx < numElems; pivotIdx++) {
            // prefixSum = Array sum strictly to the right of pivotIdx (exclusive of pivotIdx)
            suffixSum -= nums[pivotIdx];
            
            
            // Uncomment for logic understanding
            // cout << pivotIdx << ": " << "{" << prefixSum << ", " << suffixSum << "}\n";
            
            if(prefixSum == suffixSum)
                return pivotIdx;
            
            // prefixSum = Array sum strictly to the left of pivotIdx (exclusive of pivotIdx)
            prefixSum += nums[pivotIdx];
        }
        
        return -1;
    }
};