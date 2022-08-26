// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int numelems = nums.size();
        unordered_set<int> hashset(nums.begin(), nums.end());
        int lcslen = 0;
        
        for(int i = 0; i < numelems; i++) {
            if(hashset.find(nums[i] - 1) == hashset.end()) {
                int currelem = nums[i];
                int currlcslen = 1;
                
                while(hashset.find(currelem + 1) != hashset.end())
                    currelem++, currlcslen++;
                
                lcslen = max(currlcslen, lcslen);
            }
        }
        
        return lcslen;
    }
};