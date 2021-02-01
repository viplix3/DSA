#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int rowIter = 0, colIter = 0;
        
        vector<int> spiralTraversal;
        
        while((rowIter <= r) || (colIter <= c)){
            
            for(int colIdx=colIter; colIdx<(c-colIter); colIdx++)
                spiralTraversal.push_back(matrix[rowIter][colIdx]);

            if(spiralTraversal.size() == (r*c))
                break;

            for(int rowIdx=rowIter+1; rowIdx<(r-rowIter); rowIdx++)
                spiralTraversal.push_back(matrix[rowIdx][c-(colIter+1)]);
            
            for(int colIdx=c-(colIter+2); colIdx>=colIter; colIdx--)
                spiralTraversal.push_back(matrix[r-(rowIter+1)][colIdx]);

            if(spiralTraversal.size() == (r*c))
                break;
                
            for(int rowIdx=r-(rowIter+2); rowIdx>rowIter; rowIdx--)
                spiralTraversal.push_back(matrix[rowIdx][colIter]);
            
            rowIter += 1;
            colIter += 1;
        }
        return spiralTraversal;
    }
};

int main(){
    int numTestCases;
    cin>>numTestCases;

    while(numTestCases--){
        int r,c;
        cin>>r>>c;
        vector<vector<int>> matrix(r);
        
        for(int i=0; i<r; i++){
            matrix[i].assign(c, 0);
            for(int j=0; j<c; j++){
                cin>>matrix[i][j];
            }
        }

        Solution spiralTraveral;
        vector<int> result = spiralTraveral.spirallyTraverse(matrix, r, c);
        for(int i=0; i<result.size(); ++i)
            cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}