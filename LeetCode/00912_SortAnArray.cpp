// https://leetcode.com/problems/sort-an-array/

class Solution {
private:
    // Quick Sort
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
    
    int hoarePartition(vector<int>& nums,
                      int beginIdx, int endIdx) {
        // Randomize the pivot index
        int pivotIdx = beginIdx + (rand() % (endIdx - beginIdx));
        int pivot = nums[pivotIdx];
        
        // Put pivot to the beginIdx position
        swap(nums[pivotIdx], nums[beginIdx]);
        
        int lessThanPivotIdx = beginIdx - 1;
        int greaterThanPivotIdx = endIdx + 1;
        
        while(true) {
            do {
                lessThanPivotIdx++;
            }
            while(nums[lessThanPivotIdx] < pivot);
            
            do {
                greaterThanPivotIdx--;
            }
            while(nums[greaterThanPivotIdx] > pivot);
            
            if(lessThanPivotIdx >= greaterThanPivotIdx)
                return greaterThanPivotIdx;
            
            swap(nums[lessThanPivotIdx], nums[greaterThanPivotIdx]);
        }
        
        return -1;
    }
    
    void quickSortLomutoPartition(vector<int>& nums,
                                  int beginIdx, int endIdx) {
        if(beginIdx < endIdx) {
            // This would rearrange the array such that everything less than
            // pivot would be from beginIdx to pivotIdx, pivot would be
            // in it's correct position of sorted array and everything
            // greater than pivotIdx would be from pivotIdx + 1 to endIdx
            int pivotIdx = lomutoPartition(nums, beginIdx, endIdx);
            
            quickSortLomutoPartition(nums, beginIdx, pivotIdx - 1);
            quickSortLomutoPartition(nums, pivotIdx + 1, endIdx);
        }
    }
    
    void quickSortHoarePartition(vector<int>& nums,
                                int beginIdx, int endIdx) {
        if(beginIdx < endIdx) {
            // This would rearrange the array such that everything less than
            // or equal to pivot would be from beginIdx to pivotIdx and everything
            // greater than or equal to pivotIdx would be from pivotIdx + 1 to endIdx
            int pivotIdx = hoarePartition(nums, beginIdx, endIdx);
            
            quickSortHoarePartition(nums, beginIdx, pivotIdx);
            quickSortHoarePartition(nums, pivotIdx + 1, endIdx);
        }
    }
    
    
    // Merge Sort
    void merge(vector<int>& nums,
               int beginIdx, int midIdx, int endIdx) {
        int numElemsLeftArr = midIdx - beginIdx + 1;
        int numElemsRightArr = endIdx - midIdx;
        
        vector<int> leftArr(numElemsLeftArr);
        vector<int> rightArr(numElemsRightArr);
        
        for(int i = 0; i < numElemsLeftArr; i++)
            leftArr[i] = nums[beginIdx + i];
        
        for(int i = 0; i < numElemsRightArr; i++)
            rightArr[i] = nums[midIdx + i + 1];
        
        int leftArrItr = 0, rightArrItr = 0, sortedArrItr = beginIdx;
        
        while(leftArrItr < numElemsLeftArr && rightArrItr < numElemsRightArr) {
            if(leftArr[leftArrItr] <= rightArr[rightArrItr])
                nums[sortedArrItr++] = leftArr[leftArrItr++];
            else
                nums[sortedArrItr++] = rightArr[rightArrItr++];
        }
        
        while(leftArrItr < numElemsLeftArr)
            nums[sortedArrItr++] = leftArr[leftArrItr++];
        
        while(rightArrItr < numElemsRightArr)
            nums[sortedArrItr++] = rightArr[rightArrItr++];
    }
    
    
    void mergeSort(vector<int>& nums,
                  int beginIdx, int endIdx) {
        if(beginIdx < endIdx) {
            int midIdx = beginIdx + (endIdx - beginIdx) / 2;
            
            mergeSort(nums, beginIdx, midIdx);
            mergeSort(nums, midIdx + 1, endIdx);
            
            merge(nums, beginIdx, midIdx, endIdx);
        }
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        int numElems = nums.size();
        
        // O(N^2) but doesn't ususally hit O(N^2) quick sort
        // Average case is thera(N log(N))
        // Quick sort is tail recurive and can benefit from tail call
        // elimination, hence is comparatively faster than merge sort

        // Comparitively slower than Hoare's parition: 67ms, 28.3MB
        quickSortLomutoPartition(nums, 0, numElems - 1);
        
        // Faster than hoare's partition: 71ms, 28.5MB
        quickSortHoarePartition(nums, 0, numElems - 1);

        
        // O(N log(N)) merge sort: 270ms, 96.1MB
        mergeSort(nums, 0, numElems - 1);
        
        return nums;
    }
};