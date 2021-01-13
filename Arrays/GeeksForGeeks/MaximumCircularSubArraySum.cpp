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

void invertArrayPolarity(int arr[], int size)
{
    for(int i=0; i<size; i++)
        arr[i] = -arr[i];
}

int getMaximumCircularSubArraySum(int arr[], int size)
{
    int maximumSubArraySum = getMaximumSubArraySum(arr, size);

    if(maximumSubArraySum < 0)
        return maximumSubArraySum; // Or else, circular subArraySum will invert the array and will give zero sum

    int arraySum = 0;
    for(int i=0; i<size; i++)
        arraySum += arr[i];
    
    invertArrayPolarity(arr, size);
    int invertedMaxSubArraySum = getMaximumSubArraySum(arr, size);
    int maximumCircularSubArraySum = max(arraySum + invertedMaxSubArraySum, maximumSubArraySum);
    return maximumCircularSubArraySum;
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int test_array_1[] = {10, 5, -5};
    int test_array_2[] = {5, -2, 3, 4};
    int test_array_3[] = {2, 3, -4};
    int test_array_4[] = {8, -4, 3, -5, 4};
    int test_array_5[] = {-3, 4, 6, -2};
    int test_array_6[] = {-8, 7, 6};
    int test_array_7[] = {3, -4, 5, 6, -8, 7};
    int test_array_8[] = {-1, -2, -3, -4, -5};

    printf("\nContents of array\n");
    printArray(test_array_1, 3);
    printf("Maximum curcular sub-array sum for the given array: %d\n", getMaximumCircularSubArraySum(test_array_1, 3));

    printf("\nContents of array\n");
    printArray(test_array_2, 4);
    printf("Maximum curcular sub-array sum for the given array: %d\n", getMaximumCircularSubArraySum(test_array_2, 4));

    printf("\nContents of array\n");
    printArray(test_array_3, 3);
    printf("Maximum curcular sub-array sum for the given array: %d\n", getMaximumCircularSubArraySum(test_array_3, 3));

    printf("\nContents of array\n");
    printArray(test_array_4, 5);
    printf("Maximum curcular sub-array sum for the given array: %d\n", getMaximumCircularSubArraySum(test_array_4, 5));

    printf("\nContents of array\n");
    printArray(test_array_5, 4);
    printf("Maximum curcular sub-array sum for the given array: %d\n", getMaximumCircularSubArraySum(test_array_5, 4));

    printf("\nContents of array\n");
    printArray(test_array_6, 3);
    printf("Maximum curcular sub-array sum for the given array: %d\n", getMaximumCircularSubArraySum(test_array_6, 3));

    printf("\nContents of array\n");
    printArray(test_array_7, 6);
    printf("Maximum curcular sub-array sum for the given array: %d\n", getMaximumCircularSubArraySum(test_array_7, 6));

    printf("\nContents of array\n");
    printArray(test_array_8, 5);
    printf("Maximum curcular sub-array sum for the given array: %d\n", getMaximumCircularSubArraySum(test_array_8, 5));
    return 0;
}