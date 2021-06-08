#include<bits/stdc++.h>
using namespace std;

bool zeroSumSubArray(vector<int> &arr)
{
    unordered_set<int> prefixSumHashTable;
    int prefixSum = arr[0];
    prefixSumHashTable.insert(prefixSum);

    for(int i=1; i<arr.size(); i++){
        prefixSum += arr[i];
        if(prefixSum == 0)
            return true;
        if(prefixSumHashTable.find(prefixSum) != prefixSumHashTable.end())
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

    test_array = {-3, 4, -3, -1, 1};
    printf("\nInput array: ");
    printArray(test_array);
    if(zeroSumSubArray(test_array))
        printf("Zero sum sub-array exists\n");
    else
        printf("Zero sub sub-array doesn't exist\n");

    test_array = {1, 4, 13, -3, -10, 5};
    printf("\nInput array: ");
    printArray(test_array);
    if(zeroSumSubArray(test_array))
        printf("Zero sum sub-array exists\n");
    else
        printf("Zero sub sub-array doesn't exist\n");

    test_array = {-1, 4, -3, 5, 1};
    printf("\nInput array: ");
    printArray(test_array);
    if(zeroSumSubArray(test_array))
        printf("Zero sum sub-array exists\n");
    else
        printf("Zero sub sub-array doesn't exist\n");

    test_array = {3, 1, -2, 5, 6};
    printf("\nInput array: ");
    printArray(test_array);
    if(zeroSumSubArray(test_array))
        printf("Zero sum sub-array exists\n");
    else
        printf("Zero sub sub-array doesn't exist\n");

    test_array = {5, 6, 0, 8};
    printf("\nInput array: ");
    printArray(test_array);
    if(zeroSumSubArray(test_array))
        printf("Zero sum sub-array exists\n");
    else
        printf("Zero sub sub-array doesn't exist\n");

    return 0;
}