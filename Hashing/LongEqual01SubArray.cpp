#include<bits/stdc++.h>
using namespace std;

int longestEqual01SubArray(vector<int> &arr)
{
    for(int i=0; i<arr.size(); i++)
        if(arr[i] == 0)
            arr[i] = -1;

    unordered_map<int, int> prefixSum_Idx;
    int prefixSum = arr[0];
    prefixSum_Idx.insert({prefixSum, 0});
    int maxLength = 0;

    for(int i=1; i<arr.size(); i++){
        prefixSum += arr[i];

        if(prefixSum == 0)
            maxLength = max(maxLength, i+1);
        
        auto hashItr = prefixSum_Idx.find(prefixSum);
        if(hashItr != prefixSum_Idx.end())
            maxLength = max(maxLength, i - hashItr->second);

        if(prefixSum_Idx.find(prefixSum) == prefixSum_Idx.end())
            prefixSum_Idx.insert({prefixSum, i});
    }
    return maxLength;
}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    vector<int> test_array;

    test_array = {1, 1, 1, 0, 1, 0, 1, 1, 1};
    printf("\nInput array: ");
    printArray(test_array);
    printf("Length of longest sub-array with equal number of 0's and 1's in the given array: %d\n",
        longestEqual01SubArray(test_array));
    
    test_array = {1, 0, 1, 1, 1, 0, 0};
    printf("\nInput array: ");
    printArray(test_array);
    printf("Length of longest sub-array with equal number of 0's and 1's in the given array: %d\n",
        longestEqual01SubArray(test_array));
    
    test_array = {1, 1, 1, 1};
    printf("\nInput array: ");
    printArray(test_array);
    printf("Length of longest sub-array with equal number of 0's and 1's in the given array: %d\n",
        longestEqual01SubArray(test_array));
    
    test_array = {0, 0, 1, 1, 1, 1, 1, 0};
    printf("\nInput array: ");
    printArray(test_array);
    printf("Length of longest sub-array with equal number of 0's and 1's in the given array: %d\n",
        longestEqual01SubArray(test_array));
    
    test_array = {0, 0, 1, 0, 1, 1};
    printf("\nInput array: ");
    printArray(test_array);
    printf("Length of longest sub-array with equal number of 0's and 1's in the given array: %d\n",
        longestEqual01SubArray(test_array));
    
    return 0;
}