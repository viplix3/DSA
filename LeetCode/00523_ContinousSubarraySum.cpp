// https://leetcode.com/problems/continuous-subarray-sum/

// Really neat trick to handle the size of 2
// Add the modulo of previous iteration in current iteration
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int numElems = nums.size();
        
        if(numElems < 2)
            return false;
        
        int prefixSum = 0, previousIterMod = 0;
        unordered_set<int> hashset;
        
        for(int i = 0; i < numElems; i++) {
            prefixSum += nums[i];
            
            int residueForDivisibilityWithK = prefixSum % k;

			// if there was any other subarray with the same residue
			// we can remove that subarray from current subarray making current
			// subarray sum a multiple of k
            if(hashset.find(residueForDivisibilityWithK) != hashset.end())
                return true;

            hashset.insert(previousIterMod);
            previousIterMod = residueForDivisibilityWithK;
        }
        
        return false;
    }
};