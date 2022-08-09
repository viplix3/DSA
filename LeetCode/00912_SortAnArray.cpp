// https://leetcode.com/problems/sort-an-array/

class Solution {
private:
    int lomutoPartition(vector<int>& nums,
                       int beginIdx, int endIdx) {
        // Randomize the pivot index
        int pivotIdx = beginIdx + (rand() % (endIdx - beginIdx));
        int pivot = nums[pivotIdx];
        int pivotPosition = beginIdx - 1;
        
        // Put pivot to the last element
        swap(nums[pivotIdx], nums[endIdx]);
        
        // Loop to put all the elements less than pivot to the beginning of the array
        for(int i = beginIdx; i <= endIdx; i++) {
            if(nums[i] < pivot) {
                pivotPosition++;
                swap(nums[i], nums[pivotPosition]);
            }
        }
        
        // Put the pivot to the correct position such that
        // All elements before pivot are less than pivot and all
        // the elements after are greater
        pivotPosition++;
        swap(nums[endIdx], nums[pivotPosition]);
        
        return pivotPosition;
    }
    
    void quickSortLomutoPartition(vector<int>& nums,
                                  int beginIdx, int endIdx) {
        if(beginIdx < endIdx) {
            // After this pivot index would be in it's correct position
            // of sorted array
            int pivotIdx = lomutoPartition(nums, beginIdx, endIdx);
            
            quickSortLomutoPartition(nums, beginIdx, pivotIdx - 1);
            quickSortLomutoPartition(nums, pivotIdx + 1, endIdx);
        }
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        int numElems = nums.size();
        
        // O(N log(N)) quick sort: 67ms, 28.3MB
        // Comparitively slower than Hoare's parition
        quickSortLomutoPartition(nums, 0, numElems - 1);
        
        return nums;
    }
};