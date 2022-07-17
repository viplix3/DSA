// https://leetcode.com/problems/sudoku-solver/

class Solution {
private:
    bool isSafeToPlaceDigitSingleLoop(int rowIdx, int colIdx, int digit,
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

    bool isSafeToPlaceDigit(int rowIdx, int colIdx, int digit,
                           const vector<vector<char>>& board) {
        const int boardSize = 9;
        
        for(int cellIdx = 0; cellIdx < boardSize; cellIdx++) {
            // Current row check
            if(board[rowIdx][cellIdx] == ('0' + digit))
                return false;
            // Current column check
            if(board[cellIdx][colIdx] == ('0' + digit))
                return false;
        }
        
        // 3x3 block check
        int blockRowInitIdx = rowIdx - (rowIdx % 3);
        int blockColInitIdx = colIdx - (colIdx % 3);
        
        for(int currRowIdx = blockRowInitIdx; currRowIdx < blockRowInitIdx+3; currRowIdx++)
            for(int currColIdx = blockColInitIdx; currColIdx < blockColInitIdx+3; currColIdx++)
                if(board[currRowIdx][currColIdx] == ('0' + digit))
                    return false;
        
        return true;
    }
    
    bool solveSudokuProblem(vector<vector<char>>& board, const int boardSize) {
        int emptyRowIdx = -1, emptyColIdx = -1;
        
        for(int rowIdx = 0; rowIdx < boardSize; rowIdx++)
            for(int colIdx = 0; colIdx < boardSize; colIdx++)
                if(board[rowIdx][colIdx] == '.') {
                    emptyRowIdx = rowIdx;
                    emptyColIdx = colIdx;
                }
        
        if(emptyRowIdx == -1 && emptyColIdx == -1)
            return true;
        
        for(int currDigit = 1; currDigit <= boardSize; currDigit++) {
            if(isSafeToPlaceDigit(emptyRowIdx, emptyColIdx, currDigit, board)) {
                board[emptyRowIdx][emptyColIdx] = '0' + currDigit;
                
                // Try if we can solve the problem using current board config
                if(solveSudokuProblem(board, boardSize) == true)
                    return true;
                
                // If we reach here if means we couldn't solve the sodoku board config with
                // the digit set before calling the funtion
                // Reset the placed digit and something else
                board[emptyRowIdx][emptyColIdx] = '.';
            }
        }
        
        return false;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuProblem(board, 9);
    }
};