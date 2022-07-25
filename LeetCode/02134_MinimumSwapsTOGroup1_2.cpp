// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

// A very smart sliding window approach
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int numElems = nums.size();
        int numOnes = 0;
        
        // Count number of zeros in the array
        for(int i = 0; i < numElems; i++)
            if(nums[i])
                numOnes++;
        
        // Now, we will create a window of size numOnes
        // We will place the window at all the possible locations in array
        //  In each location we will count number of zeros present in the window
        //      The number of zeros would tell us number of swaps required to get all ones
        //      together if we consider current position of window
        //  The window position with minimum number of zeros will give is minimum number of swaps
        
        int windowInitIdx = 0;
        int currWindowSwaps = 0, minWindowSwaps;
        
        for(int i = 0; i < numOnes; i++)
            if(!nums[i])
                currWindowSwaps++;
        minWindowSwaps = currWindowSwaps;
        
        while(windowInitIdx < numElems) {
            
            // After placing the window at new position if the element being removed is 0
            // we need 1 less swap
            if(nums[windowInitIdx] == 0)
                currWindowSwaps--;
            
            // After placing the window at new position if the element being added is 0
            // we need 1 more swap
            if(nums[(windowInitIdx + numOnes) % numElems] == 0)
                currWindowSwaps++;
            
            minWindowSwaps = min(currWindowSwaps, minWindowSwaps);
            windowInitIdx++;
        }
        
        return minWindowSwaps;
    }
};