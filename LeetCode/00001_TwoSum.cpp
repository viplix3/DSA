// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int numElems = nums.size();
        unordered_map<int, int> hashmap;
        
        for(int i = 0; i < numElems; i++) {
            auto hashmapItr = hashmap.find(target - nums[i]);
            if(hashmapItr != hashmap.end())
                return {hashmapItr->second, i};
            
            hashmap[nums[i]] = i;
        }
        
        return {};
    }
};