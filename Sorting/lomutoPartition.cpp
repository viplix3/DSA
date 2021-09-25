#include<bits/stdc++.h>
using namespace std;

int lomutoPartition(vector<int> &arr, int pivotIdx, int lowIdx, int highIdx)
{
    int pivot = arr[pivotIdx];
    swap(arr[pivotIdx], arr[highIdx]); // Move pivot to last position
    int pivotPosition = lowIdx-1;

    for(int i=lowIdx; i<=highIdx-1; i++){
        if(arr[i] < pivot){
            pivotPosition += 1;
            swap(arr[pivotPosition], arr[i]);
        }
    }

    pivotPosition += 1;
    swap(arr[pivotPosition], arr[highIdx]);
    return pivotPosition;
}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    vector<int> test_array;
    int pivotIdx;

    test_array = {10, 80, 30, 90, 40, 50, 70};
    pivotIdx = 4;
    printf("\nInput array is: ");
    printArray(test_array);
    printf("Position of pivot at index %d in sorted array would be: %d\n", pivotIdx, 
        lomutoPartition(test_array, pivotIdx, 0, test_array.size()-1));

    test_array = {70, 60, 80, 40, 30};
    pivotIdx = 4;
    printf("\nInput array is: ");
    printArray(test_array);
    printf("Position of pivot at index %d in sorted array would be: %d\n", pivotIdx, 
        lomutoPartition(test_array, pivotIdx, 0, test_array.size()-1));

    test_array = {30, 40, 20, 50, 80};
    pivotIdx = 4;
    printf("\nInput array is: ");
    printArray(test_array);
    printf("Position of pivot at index %d in sorted array would be: %d\n", pivotIdx, 
        lomutoPartition(test_array, pivotIdx, 0, test_array.size()-1));

    return 0;
}