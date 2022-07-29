// https://leetcode.com/problems/search-in-rotated-sorted-array/

// O(N Log(N)) binary search, each condition cuts the search space by 2
class Solution {
public:
    int search(vector<int>& arr, int target) {
        int beginIdx = 0, endIdx = arr.size() - 1;
        
        while(beginIdx <= endIdx) {
            int midIdx = beginIdx + (endIdx - beginIdx) / 2;
            
            // Either first half [arr[beginIdx], arr[midIdx])
            // or second half [arr[midIdx], arr[endIdx]] would be sorted
            // We will apply binary search only for the sorted part
            
            if(arr[midIdx] == target)
                return midIdx;
            
            // First of array is sorted
            if(arr[beginIdx] <= arr[midIdx]) {
                // If search target is a part of the current sorted range
                // We don't need to search in the other half
                if(arr[beginIdx] <= target && target < arr[midIdx])
                    endIdx = midIdx - 1;
                else
                    // If search target is not inside the current sorted range
                    // We will check in the other half of the array
                    beginIdx = midIdx + 1;
            }
            // Second half of the array is sorted
            else {
                if(arr[midIdx] < target && target <= arr[endIdx])
                    beginIdx = midIdx + 1;
                else
                    endIdx = midIdx - 1;
            }
        }
        
        return -1;
    }
};