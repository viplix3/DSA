#include<bits/stdc++.h>
using namespace std;

void segrerateArray_consecutivePivots(vector<int> &arr, int pivot_1, int pivot_2)
{
    int lowIdx = -1, midIdx = 0, highIdx = arr.size();
    
    while(midIdx < highIdx){
        if(arr[midIdx] < pivot_1){
            lowIdx++;
            swap(arr[lowIdx], arr[midIdx]);
            midIdx++;
        }
        else if((pivot_1 <= arr[midIdx]) && (arr[midIdx] < pivot_2))
            midIdx++;
        else{
            highIdx--;
            swap(arr[midIdx], arr[highIdx]);
        }
    }
}

void segrerateArray(vector<int> &arr, int pivot_1, int pivot_2)
{
    if((pivot_2 - pivot_1) == 1)
        return segrerateArray_consecutivePivots(arr, pivot_1, pivot_2);

    int lowIdx = 0, midIdx = 0, highIdx = arr.size()-1;
    
    while(midIdx <= highIdx){
        if(arr[midIdx] < pivot_1){
            swap(arr[lowIdx], arr[midIdx]);
            lowIdx++;
            midIdx++;
        }
        else if(arr[midIdx] > pivot_2){
            swap(arr[midIdx], arr[highIdx]);
            highIdx--;
        }
        else
            midIdx++;
    }
}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    vector<int> test_array;
    int pivot_1, pivot_2;

    test_array = {0, 1, 1, 2, 0, 1};
    pivot_1 = 1, pivot_2 = 2;
    printf("\nInput array: ");
    printArray(test_array);
    segrerateArray(test_array, pivot_1, pivot_2);
    printf("Array after segreration w.r.t. pivots %d and %d: ", pivot_1, pivot_2);
    printArray(test_array);

    test_array = {0, 1, 2, 1, 1, 2};
    pivot_1 = 1, pivot_2 = 2;
    printf("\nInput array: ");
    printArray(test_array);
    segrerateArray(test_array, pivot_1, pivot_2);
    printf("Array after segreration w.r.t. pivots %d and %d: ", pivot_1, pivot_2);
    printArray(test_array);

    test_array = {2, 1, 2, 20, 10, 1};
    pivot_1 = 2, pivot_2 = 10;
    printf("\nInput array: ");
    printArray(test_array);
    segrerateArray(test_array, pivot_1, pivot_2);
    printf("Array after segreration w.r.t. pivots %d and %d: ", pivot_1, pivot_2);
    printArray(test_array);

    test_array = {1, 2, 3, 3, 4};
    pivot_1 = 1, pivot_2 = 2;
    printf("\nInput array: ");
    printArray(test_array);
    segrerateArray(test_array, pivot_1, pivot_2);
    printf("Array after segreration w.r.t. pivots %d and %d: ", pivot_1, pivot_2);
    printArray(test_array);

    test_array = {10, 5, 6, 3, 20, 9, 40};
    pivot_1 = 5, pivot_2 = 9;
    printf("\nInput array: ");
    printArray(test_array);
    segrerateArray(test_array, pivot_1, pivot_2);
    printf("Array after segreration w.r.t. pivots %d and %d: ", pivot_1, pivot_2);
    printArray(test_array);

    return 0;
}