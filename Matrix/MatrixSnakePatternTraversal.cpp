// https://practice.geeksforgeeks.org/problems/print-matrix-in-snake-pattern-1587115621/1/
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



class Solution
{   
public:
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        vector<int> snakePatternTraversal;
        int rowIter = 0;
        
        while(rowIter < matrix.size()){
            
            if(rowIter%2 == 0){
                for(int j=0; j<matrix[rowIter].size(); j++)
                    snakePatternTraversal.push_back(matrix[rowIter][j]);
                rowIter += 1;
            }
            
            else if(rowIter %2 != 0){
                for(int j=matrix[rowIter].size()-1; j>=0; j--)
                    snakePatternTraversal.push_back(matrix[rowIter][j]);
                rowIter += 1;
            }
        }
        
        return snakePatternTraversal;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.snakePattern(matrix);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends