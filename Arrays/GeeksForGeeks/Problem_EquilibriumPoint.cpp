#include<bits/stdc++.h>
using namespace std;

void getPrefixSum(int arr[], int arrSize, int prefixSumArr[])
{
    prefixSumArr[0] = arr[0];
    for(int i=1; i<arrSize; i++)
        prefixSumArr[i] = prefixSumArr[i-1] + arr[i];
}

void getSuffixSum(int arr[], int arrSize, int suffixSumArr[])
{
    suffixSumArr[arrSize-1] = arr[arrSize-1];
    for(int i=arrSize-2; i>=0; i--)
        suffixSumArr[i] = suffixSumArr[i+1] + arr[i];
}

bool equilibriumPointExists(int arr[], int size)
{
    int prefixSum[size], suffixSum[size];
    getPrefixSum(arr, size, prefixSum);
    getSuffixSum(arr, size, suffixSum);

    if(suffixSum[1] == 0)
        return true; // If edge element is the equilibrium point
    for(int i=1; i<size-1; i++){
        if(prefixSum[i-1] == suffixSum[i+1])
            return true;
    }
    if(prefixSum[size-2] == 0)
        return true; // If edge element is the equilibrium point
    
    return false;
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int test_array_1[] = {3, 4, 8, -9, 20, 6};
    int test_array_2[] = {4, 2, -2};
    int test_array_3[] = {4, 2, 2};
    int test_array_4[] = {2, -2, 4};

    printf("\nContents of array\n");
    printArray(test_array_1, 6);
    if(equilibriumPointExists(test_array_1, 6))
        printf("Equilibrium point exists in the array\n");
    else
        printf("There is no equilibrium point in the array\n");
    
    printf("\nContents of array\n");
    printArray(test_array_2, 3);
    if(equilibriumPointExists(test_array_2, 3))
        printf("Equilibrium point exists in the array\n");
    else
        printf("There is no equilibrium point in the array\n");

    printf("\nContents of array\n");
    printArray(test_array_3, 3);
    if(equilibriumPointExists(test_array_3, 3))
        printf("Equilibrium point exists in the array\n");
    else
        printf("There is no equilibrium point in the array\n");

    printf("\nContents of array\n");
    printArray(test_array_4, 3);
    if(equilibriumPointExists(test_array_4, 3))
        printf("Equilibrium point exists in the array\n");
    else
        printf("There is no equilibrium point in the array\n");
    return 0;
}