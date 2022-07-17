// https://leetcode.com/problems/valid-sudoku/

class Solution {
private:
    bool isSafe(int rowIdx, int colIdx, int digit,
                           const vector<vector<char>>& board) {
        const int boardSize = 9;
        int blockRowInitIdx = rowIdx - (rowIdx % 3);
        int blockColInitIdx = colIdx - (colIdx % 3);
        
        for(int cellIdx = 0; cellIdx < boardSize; cellIdx++) {
            // Current row check
            if(board[rowIdx][cellIdx] == ('0' + digit))
                return false;
            // Current column check
            if(board[cellIdx][colIdx] == ('0' + digit))
                return false;
            // 3x3 block check
            if(board[blockRowInitIdx + (cellIdx / 3)][blockColInitIdx + (cellIdx % 3)] == ('0' + digit))
                return false;
        }
        
        return true;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int boardSize = 9;
        
        for(int rowIdx = 0; rowIdx < boardSize; rowIdx++) {
            for(int colIdx = 0; colIdx < boardSize; colIdx++) {
                if(board[rowIdx][colIdx] != '.') {
                    int currDigit = board[rowIdx][colIdx] - '0';
                    
                    board[rowIdx][colIdx] = '.';
                    if(!isSafe(rowIdx, colIdx, currDigit, board))
                        return false;
                    board[rowIdx][colIdx] = '0' + currDigit;
                }
            }
        }
        
        return true;
    }
};

// Optimized O(N^2) solution from discussion
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int boardSize = 9;
        int rowMask[9][9] = {0}, colMask[9][9] = {0}, gridMask[9][9] = {0};
        
        
        for(int rowIdx = 0; rowIdx < boardSize; rowIdx++) {
            for(int colIdx = 0; colIdx < boardSize; colIdx++) {
                if(board[rowIdx][colIdx] != '.') {
                    int currDigit = board[rowIdx][colIdx] - '0';
                    
                    // currDigit appeared in current row already
                    if(rowMask[rowIdx][currDigit-1] == 1)
                        return false;
                    
                    // currDigit appeared in current col already
                    if(colMask[colIdx][currDigit-1] == 1)
                        return false;
                    
                    // currDigit appeared in current 3x3 grid already
                    // 1 whole 3x3 grid would be addressed by a single index (initial index of the grid)
                    // We can check for occurence of 9 numbers in the gird index
                    int flattennedGridIdx = (3 * (rowIdx / 3)) + (colIdx / 3);
                    if(gridMask[flattennedGridIdx][currDigit-1] == 1)
                        return false;
                    
                    // Digit didn't appear before, populate in the mask to mark occurrence
                    rowMask[rowIdx][currDigit-1] = colMask[colIdx][currDigit-1] = 
                        gridMask[flattennedGridIdx][currDigit-1] = 1;
                }
            }
        }
        
        return true;
    }
};