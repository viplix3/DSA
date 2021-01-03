#include<bits/stdc++.h>
using namespace std;

int getMaximumConsecutiveElementSum(int arr[], int arrSize, int windowSize)
{
    int windowSum = 0;

    for(int i=0; i<windowSize; i++)
        windowSum += arr[i];
    
    int candidateWindowSum = windowSum;
    for(int i=windowSize; i<arrSize; i++){
        candidateWindowSum += (arr[i] - arr[i-windowSize]);
        windowSum = max(windowSum, candidateWindowSum);
    }
    return windowSum;
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int test_array_1[] = {1, 8, 30, -5, 20, 7};
    int test_array_2[] = {5, -10, 6, 90, 3};
    int windowSize;

    printf("\nContents of array\n");
    printArray(test_array_1, 6);
    windowSize = 3;
    printf("Maximum %d consecutive element sum for the given array: %d\n", windowSize, getMaximumConsecutiveElementSum(test_array_1, 6, windowSize));

    printf("\nContents of array\n");
    printArray(test_array_2, 5);
    windowSize = 2;
    printf("Maximum %d consecutive element sum for the given array: %d\n", windowSize, getMaximumConsecutiveElementSum(test_array_2, 5, windowSize));

    return 0;
}