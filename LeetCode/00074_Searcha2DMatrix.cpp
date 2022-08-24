// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numRows = matrix.size(), numCols = matrix[0].size();
        int rowIdx = 0, colIdx = numCols - 1;
        
        while(rowIdx < numRows && colIdx >= 0) {
            if(matrix[rowIdx][colIdx] == target)
                return true;
            else if(matrix[rowIdx][colIdx] < target)
                rowIdx++;
            else
                colIdx--;
        }
        
        return false;
    }
};