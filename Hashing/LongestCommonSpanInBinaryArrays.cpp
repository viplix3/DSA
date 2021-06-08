#include<bits/stdc++.h>
using namespace std;

int getLongestCommonSubArrayLength(vector<int> &arr_1, vector<int> &arr_2)
{
    vector<int> merged;
    for(int i=0; i<arr_1.size(); i++)
        merged.push_back(arr_1[i] - arr_2[i]);

    unordered_map<int, int> prefixSum_Idx;
    int prefixSum = merged[0];
    prefixSum_Idx.insert({prefixSum, 0});
    int maxLength = 0;

    for(int i=1; i<merged.size(); i++){
        prefixSum += merged[i];

        if(prefixSum == 0)
            maxLength = max(maxLength, i+1);

        auto hashItr = prefixSum_Idx.find(prefixSum);
        if(hashItr != prefixSum_Idx.end())
            maxLength = max(maxLength, i - hashItr->second);
        
        else
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
    vector<int> test_arr_1;
    vector<int> test_arr_2;
    int sum;

    test_arr_1 = {0, 1, 0, 0, 0, 0};
    test_arr_2 = {1, 0, 1, 0, 0, 1};
    printf("\nInput test array 1: ");
    printArray(test_arr_1);
    printf("Input test array 2: ");
    printArray(test_arr_2);
    printf("Longest common sub-array (i.e. subarray with same starting and ending index in both arrays) is of length: %d\n",
        getLongestCommonSubArrayLength(test_arr_1, test_arr_2));

    test_arr_1 = {0, 1, 0, 1, 1, 1, 1};
    test_arr_2 = {1, 1, 1, 1, 1, 0, 1};
    printf("\nInput test array 1: ");
    printArray(test_arr_1);
    printf("Input test array 2: ");
    printArray(test_arr_2);
    printf("Longest common sub-array (i.e. subarray with same starting and ending index in both arrays) is of length: %d\n",
        getLongestCommonSubArrayLength(test_arr_1, test_arr_2));

    test_arr_1 = {0, 0, 0};
    test_arr_2 = {1, 1, 1};
    printf("\nInput test array 1: ");
    printArray(test_arr_1);
    printf("Input test array 2: ");
    printArray(test_arr_2);
    printf("Longest common sub-array (i.e. subarray with same starting and ending index in both arrays) is of length: %d\n", 
        getLongestCommonSubArrayLength(test_arr_1, test_arr_2));

    test_arr_1 = {0, 0, 1, 0};
    test_arr_2 = {1, 1, 1, 1};
    printf("\nInput test array 1: ");
    printArray(test_arr_1);
    printf("Input test array 2: ");
    printArray(test_arr_2);
    printf("Longest common sub-array (i.e. subarray with same starting and ending index in both arrays) is of length: %d\n",
        getLongestCommonSubArrayLength(test_arr_1, test_arr_2));

    return 0;
}