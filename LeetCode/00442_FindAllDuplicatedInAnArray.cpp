// https://leetcode.com/problems/find-all-duplicates-in-an-array/

// Use array element as indices and add count: O(N)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int numElems = nums.size();
        
        // Reduce all the array elements to [0, n]
        for(int i = 0; i < numElems; i++)
            nums[i]--;
        
        // Use array elements as array indices
        // For all the occurrences of elements, add numElems
        // If 1 is occurring twice in array, we wil update it to 1 + 2 * numElems
        for(int i = 0; i < numElems; i++)
            nums[nums[i] % numElems] += numElems;
        
        // Divide each array element by numElems
        // We added numElems twice to 1 (as it was occurring twice)
        // Diving it by numElems would now give is 2, i.e. number of occurrences
        for(int i = 0; i < numElems; i++)
            nums[i] /= numElems;
        
        vector<int> repeatingNums;
        for(int i = 0; i < numElems; i++)
            if(nums[i] > 1)
                repeatingNums.push_back(i+1);
        
        return repeatingNums;
    }
};