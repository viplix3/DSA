#include<bits/stdc++.h>
using namespace std;

int findMaximumDifference(int arr[], int size)
{
    int maxDifference, currentSmallest;
    maxDifference = arr[1] - arr[0];
    currentSmallest = arr[0];

    for(int i=1; i<size; i++){
        maxDifference = max(maxDifference, arr[i] - currentSmallest);
        currentSmallest = min(currentSmallest, arr[i]);
    }
    return maxDifference;
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int test_array_1[] = {1, 2, 3, 4, 5};
    int test_array_2[] = {7, 10, 4, 10, 6, 5, 2};
    int test_array_3[] = {2, 3, 6, 10, 4, 8, 1};
    int test_array_4[] = {7, 9, 5, 6, 3, 2};
    int test_array_5[] = {10, 20, 30};
    int test_array_6[] = {30, 10, 8, 2};

    printf("\nContents of array\n");
    printArray(test_array_1, 5);
    printf("Maximum difference in the given array is: %d\n", findMaximumDifference(test_array_1, 5));

    printf("\nContents of array\n");
    printArray(test_array_2, 7);
    printf("Maximum difference in the given array is: %d\n", findMaximumDifference(test_array_2, 7));

    printf("\nContents of array\n");
    printArray(test_array_3, 7);
    printf("Maximum difference in the given array is: %d\n", findMaximumDifference(test_array_3, 7));

    printf("\nContents of array\n");
    printArray(test_array_4, 6);
    printf("Maximum difference in the given array is: %d\n", findMaximumDifference(test_array_4, 6));

    printf("\nContents of array\n");
    printArray(test_array_5, 3);
    printf("Maximum difference in the given array is: %d\n", findMaximumDifference(test_array_5, 3));

    printf("\nContents of array\n");
    printArray(test_array_6, 4);
    printf("Maximum difference in the given array is: %d\n", findMaximumDifference(test_array_6, 4));

    return 0;
}