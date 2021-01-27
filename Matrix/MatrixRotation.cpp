// Anti-clockwise 90 degress rotation
#include<bits/stdc++.h>
using namespace std;

void transposeMatrix(vector<vector<int>> &arr)
{
    for(int i=0; i<arr.size(); i++)
        for(int j=i+1; j<arr[i].size(); j++)
            swap(arr[i][j], arr[j][i]);
}

void rotateMatrix(vector<vector<int>> &matrix)
{
    transposeMatrix(matrix);
    for(int i=0; i<matrix.size()/2; i++)
        swap(matrix[i], matrix[matrix.size()-(i+1)]);
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
    vector<vector<int>> testArray1 = {{1, 2, 3, 4},
                                      {5, 6, 7, 8},
                                      {9, 10, 11, 12},
                                      {13, 14, 15, 16}};
    
    vector<vector<int>> testArray2 = {{1, 1},
                                      {2, 2}};

    printf("Contents of the original array\n");
    print2DArray(testArray1);
    rotateMatrix(testArray1);
    printf("Contents of the array after anti-clockwise 90 degree rotation\n");
    print2DArray(testArray1);

    printf("\nContents of the original array\n");
    print2DArray(testArray2);
    rotateMatrix(testArray2);
    printf("Contents of the array after anti-clockwise 90 degree rotation\n");
    print2DArray(testArray2);

    return 0;
}

/*
Original
1   2   3   4
5   6   7   8  
9   10  11  12
13  14  15  16

Transpose
1   5   9   13
2   6   10  14       
3   7   11  15
4   8   12  16

Row-Swap
4   8   12  16
3   7   11  15
2   6   10  14
1   5   9   13
*/