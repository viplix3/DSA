// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int numBars = height.size(), trappedRainWater = 0;
        vector<int> leftSupport(numBars, 0);
        
        for(int i = 1; i < numBars; i++)
            leftSupport[i] = max(height[i-1], leftSupport[i-1]);
        
        int rightSupport = 0;
        for(int i = numBars-2; i >= 0; i--) {
            rightSupport = max(height[i+1], rightSupport);
            trappedRainWater += max(0, (min(leftSupport[i], rightSupport) - height[i]));
        }
        
        return trappedRainWater;
    }
};