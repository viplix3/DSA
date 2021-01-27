#include<bits/stdc++.h>
using namespace std;

void transposeMatrix(vector<vector<int>> &arr)
{
    for(int i=0; i<arr.size(); i++)
        for(int j=i+1; j<arr[i].size(); j++)
            swap(arr[i][j], arr[j][i]);
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
    transposeMatrix(testArray1);
    printf("Contents of the array after transpose\n");
    print2DArray(testArray1);

    printf("\nContents of the original array\n");
    print2DArray(testArray2);
    transposeMatrix(testArray2);
    printf("Contents of the array after transpose\n");
    print2DArray(testArray2);

    return 0;
}