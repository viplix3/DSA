#include<bits/stdc++.h>
using namespace std;

int getTrappedRainwater(int arr[], int size)
{
    int leftMax[size], rightMax[size], trappedWater;
    leftMax[0] = arr[0];
    rightMax[size-1] = arr[size-1];
    trappedWater = 0;

    for(int i=1; i<size; i++) // Finding maximum left support for the cuurent position
        leftMax[i] = max(leftMax[i-1], arr[i]);

    for(int i=size-2; i>0; i--) // Finding maximum right support for the cuurent position
        rightMax[i] = max(rightMax[i+1], arr[i]);
    
    for(int i=1; i<size-1; i++) // Finding maximum water trapped
        trappedWater += min(leftMax[i], rightMax[i]) - arr[i];
    
    return trappedWater;
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int test_array_1[] = {2, 0, 2};
    int test_array_2[] = {3, 0, 1, 2, 5};
    int test_array_3[] = {1, 2, 3};
    int test_array_4[] = {3, 2, 1};
    int test_array_5[] = {5, 0, 6, 2, 3};

    printf("\nContents of array\n");
    printArray(test_array_1, 3);
    printf("Maximum trapped rainwater for the given array: %d\n", getTrappedRainwater(test_array_1, 3));

    printf("\nContents of array\n");
    printArray(test_array_2, 5);
    printf("Maximum trapped rainwater for the given array: %d\n", getTrappedRainwater(test_array_2, 5));

    printf("\nContents of array\n");
    printArray(test_array_3, 3);
    printf("Maximum trapped rainwater for the given array: %d\n", getTrappedRainwater(test_array_3, 3));

    printf("\nContents of array\n");
    printArray(test_array_4, 3);
    printf("Maximum trapped rainwater for the given array: %d\n", getTrappedRainwater(test_array_4, 3));

    printf("\nContents of array\n");
    printArray(test_array_5, 5);
    printf("Maximum trapped rainwater for the given array: %d\n", getTrappedRainwater(test_array_5, 5));

    return 0;
}