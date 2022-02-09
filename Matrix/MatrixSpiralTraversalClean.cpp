// https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int numRows, int numCols) 
    {
        int topIdx = 0, leftIdx = 0, bottomIdx = (numRows - 1), rightIdx = (numCols - 1);
        vector<int> spiralTraversal;
        
        while(topIdx <= bottomIdx && leftIdx <= rightIdx) {
            int rowIdx, colIdx;
            
            // Parsing top row
            rowIdx = topIdx;
            for(colIdx = leftIdx; colIdx <= rightIdx; colIdx++)
                spiralTraversal.push_back(matrix[rowIdx][colIdx]);
            topIdx += 1;
                
            // Parsing right column
            colIdx = rightIdx;
            for(rowIdx = topIdx; rowIdx <= bottomIdx; rowIdx++)
                spiralTraversal.push_back(matrix[rowIdx][colIdx]);
            rightIdx -= 1;
            
            // Parsing bottom row
            if(topIdx <= bottomIdx) {
                rowIdx = bottomIdx;
                for(colIdx = rightIdx; colIdx >= leftIdx; colIdx--)
                    spiralTraversal.push_back(matrix[rowIdx][colIdx]);
                bottomIdx -= 1;
            }
            
            // Parsing left column
            if(leftIdx <= rightIdx) {
                colIdx = leftIdx;
                for(rowIdx = bottomIdx; rowIdx >= topIdx; rowIdx--)
                    spiralTraversal.push_back(matrix[rowIdx][colIdx]);
                leftIdx += 1;
            }
        }
        
        return spiralTraversal;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends