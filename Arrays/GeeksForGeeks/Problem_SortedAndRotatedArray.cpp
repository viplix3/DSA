#include<bits/stdc++.h>
using namespace std;

bool isDecreasinglySortedAndRotated(int arr[], int arrSize, int arrMinIdx, int arrMaxIdx)
{
    for(int i=1; i<arrMinIdx; i++)
        if((arr[i] > arr[i-1]) || (arr[i] < arr[arrMinIdx]))
            return false;

    for(int i=arrMaxIdx+1; i<arrSize; i++)
        if((arr[i] > arr[i-1]) || (arr[i] > arr[arrMaxIdx]))
            return false;
    
    if(arr[0] > arr[arrSize-1])
        return false;
    return true;
}

bool isIncreasinglySortedAndRotated(int arr[], int arrSize, int arrMinIdx, int arrMaxIdx)
{
    for(int i=1; i<arrMaxIdx; i++)
        if((arr[i] < arr[i-1]) || (arr[i] > arr[arrMaxIdx]))
            return false;
    
    for(int i=arrMinIdx+1; i<arrSize; i++)
        if((arr[i] < arr[i-1]) || (arr[i] < arr[arrMinIdx]))
            return false;
    
    if(arr[0] < arr[arrSize-1])
        return false;
    return true;
}

bool ifAdjacent(int value_1, int value_2)
{
    return value_1<value_2 ? (value_1+1 == value_2) : (value_1-1 == value_2);
}

void getArrayMinMaxIdx(int arr[], int arrSize, int *arrMinIdx, int *arrMaxIdx)
{
    int arrMin = INT_MAX;
    int arrMax = INT_MIN;
    for(int i=0; i<arrSize; i++){
        if(arr[i] > arrMax){
            arrMax = arr[i];
            *arrMaxIdx = i;
        }
        if(arr[i] < arrMin){
            arrMin = arr[i];
            *arrMinIdx = i;
        }
    }
}

bool checkRotatedAndSorted(int arr[], int arrSize){
    int arrMinIdx, arrMaxIdx;
    getArrayMinMaxIdx(arr, arrSize, &arrMinIdx, &arrMaxIdx);

    // Minimum and maximum elements of the array will always be adjacent if the array is sorted and rotated
    if(ifAdjacent(arrMinIdx, arrMaxIdx) == false) 
        return false;
    
    if(arrMinIdx > arrMaxIdx)
        return isIncreasinglySortedAndRotated(arr, arrSize, arrMinIdx, arrMaxIdx);
    else
        return isDecreasinglySortedAndRotated(arr, arrSize, arrMinIdx, arrMaxIdx);
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int test_array_1[] = {3, 4, 1, 2};
    int test_array_2[] = {1, 2, 3};
    int test_array_3[] = {2, 1, 4, 10, 0, 1, 3};
    int test_array_4[] = {2, 1, 4, 3};
    int test_array_5[] = {30, 20, 10, 50, 25};

    printf("\nContents of array\n");
    printArray(test_array_1, 4);
    if(checkRotatedAndSorted(test_array_1, 4))
        printf("Array is sorted and rotated\n");
    else
        printf("Array is not sorted and rotated\n");

    printf("\nContents of array\n");
    printArray(test_array_2, 3);
    if(checkRotatedAndSorted(test_array_2, 3))
        printf("Array is sorted and rotated\n");
    else
        printf("Array is not sorted and rotated\n");

    printf("\nContents of array\n");
    printArray(test_array_3, 7);
    if(checkRotatedAndSorted(test_array_3, 7))
        printf("Array is sorted and rotated\n");
    else
        printf("Array is not sorted and rotated\n");

    printf("\nContents of array\n");
    printArray(test_array_4, 4);
    if(checkRotatedAndSorted(test_array_4, 4))
        printf("Array is sorted and rotated\n");
    else
        printf("Array is not sorted and rotated\n");

    printf("\nContents of array\n");
    printArray(test_array_5, 5);
    if(checkRotatedAndSorted(test_array_5, 5))
        printf("Array is sorted and rotated\n");
    else
        printf("Array is not sorted and rotated\n");
    return 0;
}