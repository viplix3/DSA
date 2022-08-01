// https://leetcode.com/problems/container-with-most-water/

// 2-pointer, O(N)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int beginIdx = 0, endIdx = height.size() - 1;
        int maxTrappedWater = 0;
        
        while(beginIdx <= endIdx) {
            int currTrappedWater = min(height[beginIdx], height[endIdx]) * (endIdx - beginIdx);
            maxTrappedWater = max(currTrappedWater, maxTrappedWater);
            
            if(height[beginIdx] < height[endIdx])
                beginIdx++;
            else
                endIdx--;
        }
        
        return maxTrappedWater;
    }
};