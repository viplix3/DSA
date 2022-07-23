// https://leetcode.com/problems/majority-element/

// Moore's voting algo
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int numElems = nums.size();
        int candidateElement = nums[0], voteCount = 1;
        
        int currIdx = 1;
        while(currIdx < numElems) {
            if(nums[currIdx] == candidateElement)
                voteCount++;
            else
                voteCount--;
            
            if(voteCount == 0) {
                candidateElement = nums[currIdx];
                voteCount = 1;
            }
            
            currIdx++;
        }
        
        return candidateElement;
    }
};