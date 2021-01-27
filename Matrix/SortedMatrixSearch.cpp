#include<bits/stdc++.h>
using namespace std;

void searchSortedMatrix(vector<vector<int>> sortedMatrix, int element)
{
    // Starting searching from top-right position (go left to find smaller elements and down to find bigger)
    int row_iter = 0, column_iter = sortedMatrix[0].size()-1;

    while((row_iter<sortedMatrix.size()) && (column_iter > 0)){
        if(element == sortedMatrix[row_iter][column_iter]){
            printf("Element %d found at position (%d, %d)\n", element, row_iter, column_iter);
            return;
        }
        
        if(element < sortedMatrix[row_iter][column_iter])
            column_iter--;
        else
            row_iter++;
    }

    printf("Element %d not found in the given matrix\n", element);
}

void print2DArray(vector<vector<int>> &arr)
{
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

int main(){

    int elementToSearch;
    vector<vector<int>> testArray1 = {{1,   2,  3,  4},
                                      {5,   6,  7,  8},
                                      {9,   10, 11, 12},
                                      {13,  14, 15, 16}};

    vector<vector <int>> testArray2 = {{10,  20, 30, 40},
                                      {15,  25, 35, 45},
                                      {27,  29, 37, 48},
                                      {32,  33, 39, 50}};


    printf("\nContents of the original array\n");
    elementToSearch = 11;
    print2DArray(testArray1);
    searchSortedMatrix(testArray1, elementToSearch);

    printf("\nContents of the original array\n");
    elementToSearch = 29;
    print2DArray(testArray2);
    searchSortedMatrix(testArray2, elementToSearch);

    printf("\nContents of the original array\n");
    elementToSearch = 37;
    print2DArray(testArray2);
    searchSortedMatrix(testArray2, elementToSearch);

    return 0;
}