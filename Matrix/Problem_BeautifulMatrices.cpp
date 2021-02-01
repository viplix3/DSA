// https://practice.geeksforgeeks.org/problems/make-matrix-beautiful-1587115620/1
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinOperation(vector<vector<int>> matrix, int n)
    {
        int totalSum = 0, maxSum = INT_MIN;

        for(int i=0; i<n; i++){
            int rowSum = 0, colSum = 0;
            for(int j=0; j<n; j++){
                rowSum += matrix[i][j];
                colSum += matrix[j][i];
            }
            // Getting maximum row/column sum in the matrix
            maxSum = max(maxSum, rowSum);
            maxSum = max(maxSum, colSum);

            totalSum += rowSum; // Total sum of all the elements of the matrix
        }

        // As we are only allowed to do increment the values, to make the sum of all the rows and columns same
        // we will have to make the sum of each row and column equal to the maximum sum. On doing so, the total
        // sum of the matrix would be (current_maximum_sum * number_of_row_or_columns)
        // If we subtract the current total sum of the matrix from the above, we will get all the value increments to get the desired results
        // and that will be out cost
        int cost = (maxSum * n) - totalSum;
        return cost;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> matrix(n, vector<int>(n));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>matrix[i][j];
        Solution beautifulMatrices;
        cout<<beautifulMatrices.findMinOperation(matrix, n)<<endl;
    }
    return 0;
}