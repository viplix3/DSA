// https://leetcode.com/problems/set-matrix-zeroes/

// O(MN) time and O(1) space
/*
We handle cases seperately.

Check the first row and column for pre-existing 0.
	If found we mark that row or column as true
Now we work upon the remaining matrix.
	First we look for the cell that has 0 in it.
	Then proceed with the working i.e. marking the cell as 0.
Now work upon the checked first row and column and update their values.
	Note: Updating before hand gives WA

why do you check the first row and column seperately?
	because we are using first row and column as a marker for remaining matrix
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool RowZero = false;
        bool ColZero = false;
        for (int i = 0; i < matrix[0].size(); i++) //check the first row
        { 
            if (matrix[0][i] == 0) 
            {
                RowZero = true;
                break;
            } 
        }
        for (int i = 0; i < matrix.size(); i++) //check the first column
        { 
            if (matrix[i][0] == 0) 
            {
                ColZero = true;
                break;
            } 
        }
        for (int i = 1; i < matrix.size(); i++) //check except the first row and column
        { 
            for (int j = 1; j < matrix[0].size(); j++) 
            {    
                if (matrix[i][j] == 0) 
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }        
            }
        }
        for (int i = 1; i < matrix.size(); i++) //process except the first row and column 
        {
           for (int j = 1; j < matrix[0].size(); j++)
           {
               if (matrix[i][0] == 0 || matrix[0][j] == 0)
               {
                   matrix[i][j] = 0;
           
               }
           }
        }
        if(RowZero) //handle the first row
        { 
            for (int i = 0; i < matrix[0].size(); i++) 
            {
                matrix[0][i] = 0;
            }
        }
        if (ColZero) //handle the first column
        { 
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};


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