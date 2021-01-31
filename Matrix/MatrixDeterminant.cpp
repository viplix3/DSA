#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:

    void fillCoFactorMatrix(vector<vector<int>> &matrix, vector<vector<int>> &coFactorMatrix, int rowSkipIdx, int colSkipIdx, int matrixDim)
    {
        int i=0, j=0; // For iterating through the co-factor matrix
        for(int rowIdx=0; rowIdx<matrixDim; rowIdx++){
            coFactorMatrix[i].assign(matrixDim, 0);
            for(int colIdx=0; colIdx<matrixDim; colIdx++){
                // When calculating co-factors, the current matrix row and column undersideration are skipped
                // In our implementation, those are being depicted by rowSkipIdx and colSkipIdx
                // Hence, data will be copied into coFactorMatrix for all rows/columns except rowSkipIdx and colSkipIdx
                if((rowIdx != rowSkipIdx) && (colIdx != colSkipIdx)){
                    // Using different row/column index iterators as we will be skipping 1 row/column from the original array
                    coFactorMatrix[i][j] = matrix[rowIdx][colIdx];
                    j += 1;

                    if(j == (matrixDim-1)){ // When all the columns for current row have been populated
                        i += 1; // Next row to be populated next
                        j = 0; // Column index 0 to be populated next
                    }
                }
            }
        }
    }

    int determinantOfMatrix(vector<vector<int>> &matrix, int matrixDim)
    {
        int determinant = 0;
        if(matrixDim == 1){
            // If matrix is having only single dimension, then that value is determinant of matrix
            determinant = matrix[0][0];
            return determinant;
        }

        // If not, we will follow the co-factor method of calculating determinant
        vector<vector<int>> coFactorMatrix(matrixDim); // To hold co-factor matrix at each recursive call
        int sign = 1; // Will keep track of alternating sign when multiplying co-factor and matrix element

        for(int j=0; j<matrixDim; j++){ // Using first row of matrix for determiant calculation
            fillCoFactorMatrix(matrix, coFactorMatrix, 0, j, matrixDim); // Get co-factor
            // Determinant calculation, google 'Co-factor determinant formula' for more details
            determinant += (sign * matrix[0][j] * determinantOfMatrix(coFactorMatrix, matrixDim-1));
            sign = -sign; // Alternating sign for next iternation
        }

        return determinant;
    }
};

int main(){
    int numTestCases;
    scanf("%d", &numTestCases);

    while(numTestCases--){
        int matrixDim;
        scanf("%d", &matrixDim);
        vector<vector<int>> matrix(matrixDim);

        for(int i=0; i<matrixDim; i++){
            matrix[i].assign(matrixDim, 0);
            for(int j=0; j<matrixDim; j++)
                scanf("%d", &matrix[i][j]);
        }

        Solution matrixOps;
        int result = matrixOps.determinantOfMatrix(matrix, matrixDim);
        printf("%d\n", result);
    }
    return 0;
}

/* Sample Input
====================
2
4
1   0   2   -1
3   0   0   5
2   1   4   -3
1   0   5   0

3
1   2   3
4   5   6
7   10  9
====================

Expected Output:
30
12
*/