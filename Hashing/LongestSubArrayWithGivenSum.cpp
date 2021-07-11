#include<bits/stdc++.h>
using namespace std;

int longestSubArrayWithGivenSum(vector<int> &arr, int sum)
{
    unordered_map<int, int> prefixSum_Idx;
    int prefixSum = 0, length = 0;

    for(int i=0; i<arr.size(); i++){
        prefixSum += arr[i];

        if(prefixSum == sum)
            length = max(length, i+1);
        
        if(prefixSum_Idx.find(prefixSum) == prefixSum_Idx.end())
            prefixSum_Idx.insert({prefixSum, i});

        auto hash_pair = prefixSum_Idx.find(prefixSum - sum);
        if(hash_pair != prefixSum_Idx.end())
            length = max(length, i - hash_pair->second);

    }
    return length;
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

    test_array = {5, 8, -4, -4, 9, -2, 2};
    sum = 0;
    printf("\nInput array: ");
    printArray(test_array);
    printf("Length of longest sub-array with sum %d in the given array: %d\n", sum, 
        longestSubArrayWithGivenSum(test_array, sum));

    test_array = {3, 1, 0, 1, 8, 2, 3, 6};
    sum = 5;
    printf("\nInput array: ");
    printArray(test_array);
    printf("Length of longest sub-array with sum %d in the given array: %d\n", sum, 
        longestSubArrayWithGivenSum(test_array, sum));

    test_array = {8, 3, 7};
    sum = 15;
    printf("\nInput array: ");
    printArray(test_array);
    printf("Length of longest sub-array with sum %d in the given array: %d\n", sum, 
        longestSubArrayWithGivenSum(test_array, sum));

    test_array = {8, 3, 1, 5, -6, 6, 2, 2};
    sum = 4;
    printf("\nInput array: ");
    printArray(test_array);
    printf("Length of longest sub-array with sum %d in the given array: %d\n", sum, 
        longestSubArrayWithGivenSum(test_array, sum));

    return 0;
}