// https://leetcode.com/problems/intersection-of-multiple-arrays/

// O(NM) time O(1) space solution
// Count the occurrences of elements, if count is same as the number of rows, then the element is common to all rows
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int numRows = nums.size(), numCols = nums[0].size();
        vector<int> frequencyCount(1001);
        vector<int> intersectionElements;
        
        for(auto &arr : nums)
            for(int ele : arr)
                frequencyCount[ele]++;
        
        for(int i = 1; i < 1001; i++)
            if(frequencyCount[i] == numRows) // Element occurred in each row
                intersectionElements.push_back(i);
        
        return intersectionElements;
    }
};