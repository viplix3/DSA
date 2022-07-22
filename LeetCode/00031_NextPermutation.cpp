class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int dscIdx = -1;
        int numElems = nums.size();
        
        // Find the index of where the first
		// descreasing subsequence ends from the end of array
        for(int i = numElems - 1; i > 0; i--)
            if(nums[i] > nums[i-1]) {
                dscIdx = i;
                break;
            }
        
        // If the whole array is a descreasing subsequence, it is reverse sorted
        // and no next permutaion exists, reverse and return sorted array
        if(dscIdx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Find a element in the descreasing subsequence
        // that is greater than the element present before the ending
        // of longest descreasing subsequence
        int swapIdx = numElems - 1;
        for(; swapIdx > dscIdx; swapIdx--)
            if(nums[swapIdx] > nums[dscIdx - 1])
                break;
        
        swap(nums[dscIdx - 1], nums[swapIdx]);
        reverse(nums.begin() + dscIdx, nums.end());
    }
};