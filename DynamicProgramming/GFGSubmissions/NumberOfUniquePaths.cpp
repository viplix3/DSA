// https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1/

// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
public:
    //Function to find total number of unique paths.
    int NumberOfPath(int numRows, int numCols)
    {
		vector<vector<int>> matrix(numRows, vector<int>(numCols, 0));

		for(int rowIdx = 0; rowIdx < numRows; rowIdx++) {
			for(int colIdx = 0; colIdx < numCols; colIdx++) {
					if(rowIdx == 0 || colIdx == 0)
						// We can always reach all the cells in 0th row and 0th col
						matrix[rowIdx][colIdx] = 1;
					else
						// We could have reached current cell only from two possible cells as limited movement is allowed
						//		1. 1 row above, same column
						//		2. same row, 1 coloumn left
						matrix[rowIdx][colIdx] = matrix[rowIdx - 1][colIdx] + matrix[rowIdx][colIdx - 1];
			}
		}

		return matrix[numRows - 1][numCols - 1];
    }
};


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends