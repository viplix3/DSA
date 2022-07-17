// https://leetcode.com/problems/n-queens/

class Solution {
private:
    bool isSafeToPlaceQueen(int rowIdx, int colIdx,
                            const vector<string>& chessBoard,
                            int boardSize) {
        // We are filling chessBoard from top left corner to bottom right
        // Hence, at any point of time we need to check the safe conditions on
        // Upper diagonal
        // Lower diagonal
        // Same row, left columns
        
        // Upper diagonal
        int currRowIdx = rowIdx, currColIdx = colIdx;
        while(currRowIdx >= 0 && currColIdx >= 0) {
            if(chessBoard[currRowIdx][currColIdx] == 'Q')
                return false;
            
            currRowIdx -= 1;
            currColIdx -= 1;
        }
        
        // Lower diagonal
        currRowIdx = rowIdx, currColIdx = colIdx;
        while(currRowIdx < boardSize && currColIdx >= 0) {
            if(chessBoard[currRowIdx][currColIdx] == 'Q')
                return false;
            
            currRowIdx += 1;
            currColIdx -= 1;
        }
        
        // Same row, left columns
        currColIdx = colIdx;
        while(currColIdx >= 0) {
            if(chessBoard[rowIdx][currColIdx] == 'Q')
                return false;
            
            currColIdx -= 1;
        }
        
        return true;
    }

    
    void solveNQueensProblem(int currColIdx, vector<string>& chessBoard,
                           vector<vector<string>>& solutions, int boardSize) {
        if(currColIdx == boardSize) {
            solutions.push_back(chessBoard);
            return;
        }

        for(int currRowIdx = 0; currRowIdx < boardSize; currRowIdx++) {
            if(isSafeToPlaceQueen(currRowIdx, currColIdx, chessBoard, boardSize)) {
                chessBoard[currRowIdx][currColIdx] = 'Q'; // Place the queen
                solveNQueensProblem(currColIdx+1, chessBoard, solutions, boardSize); // Check for solution

                // Remove the queen and try a different solution in next iteration
                chessBoard[currRowIdx][currColIdx] = '.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> chessBoard(n, string(n, '.'));
        int colIdx = 0;
        
        solveNQueensProblem(colIdx, chessBoard, solutions, n);
        return solutions;
    }
};