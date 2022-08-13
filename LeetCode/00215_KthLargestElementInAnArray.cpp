// https://leetcode.com/problems/kth-largest-element-in-an-array/

// QuickSort partition based solution: O(N) in average case but O(N^2) in worst cast
// Best solution would be using priority queue
class Solution {
private:
    int lomutoPartition(vector<int>& nums, int beginIdx, int endIdx) {
        int pivotIdx = beginIdx + (rand() % (endIdx - beginIdx));
        
        int pivot = nums[pivotIdx];
        swap(nums[pivotIdx], nums[endIdx]);
        pivotIdx = beginIdx - 1;
        
        for(int i = beginIdx; i < endIdx; i++) {
            if(nums[i] < pivot) {
                pivotIdx++;
                swap(nums[i], nums[pivotIdx]);
            }
        }
        
        pivotIdx++;
        swap(nums[endIdx], nums[pivotIdx]);
        return pivotIdx;
    }
    
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        int numElems = nums.size() - 1;
        int beginIdx = 0, endIdx = nums.size() - 1;
        
        while(beginIdx < endIdx) {
            int partitionIdx = lomutoPartition(nums, beginIdx, endIdx);
            
            if(partitionIdx == (numElems - k + 1)) 
                return nums[partitionIdx];
            
            if(partitionIdx < (numElems - k + 1))
                beginIdx = partitionIdx + 1;
            else
                endIdx = partitionIdx - 1;
        }
        
        return nums[beginIdx];
    }
};