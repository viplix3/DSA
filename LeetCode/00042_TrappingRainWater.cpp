// https://leetcode.com/problems/trapping-rain-water/

// O(N) time, O(1) space
class Solution {
public:
    int trap(vector<int>& height) {
        int numBars = height.size(), trappedRainWater = 0;
        
        if(numBars <= 2)
            return trappedRainWater;
        
        int leftSupportIdx = 1, leftSupportValue = height[0];
        int rightSupportIdx = numBars - 2, rightSupportValue = height[numBars - 1];
        
        while(leftSupportIdx <= rightSupportIdx) {
            // In each iteration we will move from lower support to higher support
            // Doint so can potentially give land us on heights having water on top of them
            if(leftSupportValue < rightSupportValue) {
                // Current height is greater than previous left support, hence cannot hold any water on top of it
                if(height[leftSupportIdx] > leftSupportValue)
                    leftSupportValue = height[leftSupportIdx];
                else
                    // Left support is greater than current current height, add the trapped water
                    trappedRainWater += leftSupportValue - height[leftSupportIdx];
                leftSupportIdx++;
            }
            else { // Do same for right
                if(height[rightSupportIdx] > rightSupportValue)
                    rightSupportValue = height[rightSupportIdx];
                else
                    trappedRainWater += rightSupportValue - height[rightSupportIdx];
                rightSupportIdx--;
            }
        }
        
        return trappedRainWater;
    }
};

// O(N) time, O(N) space
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