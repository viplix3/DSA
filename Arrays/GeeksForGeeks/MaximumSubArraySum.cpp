#include<bits/stdc++.h>
using namespace std;

int getMaximumSubArraySum(int arr[], int size)
{
    int currentSubArraySum, maxSubArraySum;
    currentSubArraySum = maxSubArraySum = arr[0];

    for(int i=1; i<size; i++){
        currentSubArraySum = max(currentSubArraySum+arr[i], arr[i]);
        maxSubArraySum = max(currentSubArraySum, maxSubArraySum);
    }
    return maxSubArraySum;
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int test_array_1[] = {2, 3, -8, 7, -1, 2, 3};
    int test_array_2[] = {5, 8, 3};
    int test_array_3[] = {-6, -1, -8};
    int test_array_4[] = {1, -2, 3, -1, 2};

    printf("\nContents of array\n");
    printArray(test_array_1, 7);
    printf("Maximum sub-array sum for the given array: %d\n", getMaximumSubArraySum(test_array_1, 7));

    printf("\nContents of array\n");
    printArray(test_array_2, 3);
    printf("Maximum sub-array sum for the given array: %d\n", getMaximumSubArraySum(test_array_2, 3));

    printf("\nContents of array\n");
    printArray(test_array_3, 3);
    printf("Maximum sub-array sum for the given array: %d\n", getMaximumSubArraySum(test_array_3, 3));

    printf("\nContents of array\n");
    printArray(test_array_4, 5);
    printf("Maximum sub-array sum for the given array: %d\n", getMaximumSubArraySum(test_array_4, 5));
    return 0;
}