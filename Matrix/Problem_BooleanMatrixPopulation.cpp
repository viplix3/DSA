// https://practice.geeksforgeeks.org/problems/boolean-matrix-problem-1587115620/1
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends


class Solution
{   
public:
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        int numRows = matrix.size(), numCols = matrix[0].size();
        
        vector<int> rowPopulationIndices;
        vector<int> colPopulationIndices;
        
        rowPopulationIndices.assign(numRows, 0);
        colPopulationIndices.assign(numCols, 0);
        
        
        for(int i=0; i<numRows; i++)
            for(int j=0; j<numCols; j++)
                if(matrix[i][j]){
                    rowPopulationIndices[i] = 1;
                    colPopulationIndices[j] = 1;
                }
        
        for(int i=0; i<numRows; i++){
            for(int j=0; j<numCols; j++){
                if(rowPopulationIndices[i] || colPopulationIndices[j])
                    matrix[i][j] = 1;
            }
        }

    }
};

/*

[(0, 0)]

[(0, 0), (1, 0), (2, 0)]

*/

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}


  // } Driver Code Ends