// https://leetcode.com/problems/find-the-duplicate-number/

// Floyd's algo, O(N), doesn't modify the array
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int numElems = nums.size();
        int slowPtr = nums[0], fastPtr = nums[0];
        
        do {
            slowPtr = nums[slowPtr];
            fastPtr = nums[nums[fastPtr]];
        }
        while(slowPtr != fastPtr);
        
        slowPtr = nums[0];
        while(slowPtr != fastPtr) {
            slowPtr = nums[slowPtr];
            fastPtr = nums[fastPtr];
        }
        
        return fastPtr;
    }
};


// Binary search solution from leetcode tutorial, O(N log(N))
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // lambda function to count occurrences of number
        auto countSmallOrEqual = [&](int currSearchNum) {
            int occurrenceCount = 0;
            
            for(auto &currNum : nums) {
                if(currNum <= currSearchNum)
                    occurrenceCount += 1;
            }
            
            return occurrenceCount;
        };
        
        int searchInit = 1, searchEnd = nums.size();
        int repeatingNum = -1;
        while(searchInit <= searchEnd) {
            int searchNum = searchInit + (searchEnd - searchInit) / 2;
            
            // This number is repeating
            if(countSmallOrEqual(searchNum) > searchNum) {
                repeatingNum = searchNum;
                searchEnd = searchNum - 1; // Try to find a smaller repeating number in next iteration
            }
            else
                searchInit = searchNum + 1; // Couldn't find a repeating number, try different range
        }
        
        return repeatingNum;
    }
};


// Find occurrence count of each element: O(N), modifies the array
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int numElems = nums.size();
        
        for(int i = 0; i < numElems; i++)
            nums[i]--;
        
        for(int i = 0; i < numElems; i++)
            nums[nums[i] % numElems] += numElems;
        
        for(int i = 0; i < numElems; i++)
            nums[i] /= numElems;
        
        for(int i = 0; i < numElems; i++)
            if(nums[i] > 1)
                return i+1;
        
        return -1;
    }
};