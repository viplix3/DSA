// https://leetcode.com/problems/set-matrix-zeroes/

// O(MN) time O(N) space solution
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int numRows = matrix.size(), numCols = matrix[0].size();
        vector<bool> zeroRows(numRows, false), zeroCols(numCols, false);
        vector<int> zeroVectorForCols(numCols, 0);
        
        
        for(int rowIdx = 0; rowIdx < numRows; rowIdx++)
            for(int colIdx = 0; colIdx < numCols; colIdx++)
                if(matrix[rowIdx][colIdx] == 0) {
                    zeroRows[rowIdx] = true;
                    zeroCols[colIdx] = true;
                }
        
        for(int rowIdx = 0; rowIdx < numRows; rowIdx++)
            for(int colIdx = 0; colIdx < numCols; colIdx++)
                if(zeroRows[rowIdx] || zeroCols[colIdx])
                    matrix[rowIdx][colIdx] = 0;
    }
};