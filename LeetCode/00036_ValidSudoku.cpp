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