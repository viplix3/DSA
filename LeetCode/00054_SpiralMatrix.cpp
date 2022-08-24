// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int numRows = matrix.size(), numCols = matrix[0].size();
        vector<int> spiralOrderTraversal;
        
        int topIdx = 0, leftIdx = 0,
            bottomIdx = numRows - 1,
            rightIdx = numCols - 1;
        
        int currRowIdx, currColIdx;
        
        while(topIdx <= bottomIdx && leftIdx <= rightIdx) {
            // Top row
            currRowIdx = topIdx;
            for(currColIdx = leftIdx; currColIdx <= rightIdx; currColIdx++)
                spiralOrderTraversal.push_back(matrix[currRowIdx][currColIdx]);
            topIdx++;
            
            // Right column
            currColIdx = rightIdx;
            for(currRowIdx = topIdx; currRowIdx <= bottomIdx; currRowIdx++)
                spiralOrderTraversal.push_back(matrix[currRowIdx][currColIdx]);
            rightIdx--;
            
            // Bottom row
            if(topIdx <= bottomIdx) {
                currRowIdx = bottomIdx;
                for(currColIdx = rightIdx; currColIdx >= leftIdx; currColIdx--)
                    spiralOrderTraversal.push_back(matrix[currRowIdx][currColIdx]);
                bottomIdx--;
            }
            
            // Left column
            if(leftIdx <= rightIdx) {
                currColIdx = leftIdx;
                for(currRowIdx = bottomIdx; currRowIdx >= topIdx; currRowIdx--)
                    spiralOrderTraversal.push_back(matrix[currRowIdx][currColIdx]);
                leftIdx++;
            }
        }
        
        return spiralOrderTraversal;
    }
};