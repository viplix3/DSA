// https://leetcode.com/problems/contains-duplicate/

// Put everthing in hashtable, check the size: O(N)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        return (nums.size() != numSet.size());
    }
};