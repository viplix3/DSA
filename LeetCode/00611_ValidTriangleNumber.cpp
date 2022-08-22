// https://leetcode.com/problems/valid-triangle-number/

// Sorting + 2 pointers solution
// O(N^2) time and O(1) space solution
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int numSides = nums.size();
        
        if(numSides < 3)
            return 0;
        
        sort(nums.begin(), nums.end());
        int totalPossibleTriangles = 0;
        
        for(int thirdSideIdx = numSides - 1; thirdSideIdx >= 2; thirdSideIdx--) {
            int firstSideIdx = 0, secondSideIdx = thirdSideIdx - 1;
            
            while(firstSideIdx < secondSideIdx) {
                if(nums[firstSideIdx] + nums[secondSideIdx] > nums[thirdSideIdx]) {
                    totalPossibleTriangles += secondSideIdx - firstSideIdx;
                    secondSideIdx--;
                }
                else
                    firstSideIdx++;
            }
        }
        
        return totalPossibleTriangles;
    }
};