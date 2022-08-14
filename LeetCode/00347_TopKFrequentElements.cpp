// https://leetcode.com/problems/top-k-frequent-elements/

// O(NK) solution: better when K is small
// Based on modified moore voting algorithm
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int numElems = nums.size();
        vector<int> topKElems;
        unordered_map<int, int> frequencyMap;
        
        if(nums.size() == 0)
            return topKElems;
        
        for(int i = 0; i < numElems; i++) {
            if(frequencyMap.find(nums[i]) != frequencyMap.end()) {
                frequencyMap[nums[i]] += 1;
            }
            else {
                for(auto itr : frequencyMap) {
                    itr.second--;
                    if(itr.second == 0)
                        frequencyMap.erase(itr.first);
                }
            }
            
            if(frequencyMap.size() < k)
                frequencyMap[nums[i]] += 1;
        }
        
        for(auto itr : frequencyMap)
            topKElems.push_back(itr.first);
        
        return topKElems;
    }
};