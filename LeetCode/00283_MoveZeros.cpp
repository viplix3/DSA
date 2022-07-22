// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int nonZeroIdx = 0, numElems = arr.size();
        
        for(int i = 0; i < numElems; i++) {
            if(arr[i] != 0) {
                swap(arr[i], arr[nonZeroIdx]);
                nonZeroIdx++;
            }
        }
    }
};