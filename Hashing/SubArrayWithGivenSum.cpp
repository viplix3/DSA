#include<bits/stdc++.h>
using namespace std;

bool subArrayWithGivenSum(vector<int> &arr, int sum)
{
    unordered_set<int> prefixSumHashTable;
    int prefixSum = arr[0];
    prefixSumHashTable.insert(prefixSum);

    for(int i=1; i<arr.size(); i++){
        if(prefixSum == sum)
            return true;
        prefixSum += arr[i];
        if(prefixSumHashTable.find(prefixSum - sum) != prefixSumHashTable.end())
            return true;
        prefixSumHashTable.insert(prefixSum);
    }
    return false;
}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    vector<int> test_array;
    int sum;

    test_array = {5, 8, 6, 13, 3, -1};
    sum = 22;
    printf("\nInput array: ");
    printArray(test_array);
    if(subArrayWithGivenSum(test_array, sum))
        printf("Sub-array with sum %d exists in the given array\n", sum);
    else
        printf("Sub-array with sum %d doesn't exist in the the given array\n", sum);

    test_array = {15, 2, 8, 10, -5, -8, 6};
    sum = 3;
    printf("\nInput array: ");
    printArray(test_array);
    if(subArrayWithGivenSum(test_array, sum))
        printf("Sub-array with sum %d exists in the given array\n", sum);
    else
        printf("Sub-array with sum %d doesn't exist in the the given array\n", sum);

    test_array = {3, 2, 5, 6};
    sum = 10;
    printf("\nInput array: ");
    printArray(test_array);
    if(subArrayWithGivenSum(test_array, sum))
        printf("Sub-array with sum %d exists in the given array\n", sum);
    else
        printf("Sub-array with sum %d doesn't exist in the the given array\n", sum);

    test_array = {5, 3, 2, -1};
    sum = 4;
    printf("\nInput array: ");
    printArray(test_array);
    if(subArrayWithGivenSum(test_array, sum))
        printf("Sub-array with sum %d exists in the given array\n", sum);
    else
        printf("Sub-array with sum %d doesn't exist in the the given array\n", sum);

    return 0;
}