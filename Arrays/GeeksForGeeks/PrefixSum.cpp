#include<bits/stdc++.h>
using namespace std;

void getPrefixSum(int arr[], int size, int prefixSumArr[])
{
    prefixSumArr[0] = arr[0];
    for(int i=1; i<size; i++)
        prefixSumArr[i] = prefixSumArr[i-1] + arr[i];
}

void processQueriesAndPrintSum(int arr[], int arrSize, int queryList[][2], int numQueries)
{
    int prefixSum[arrSize];
    getPrefixSum(arr, arrSize, prefixSum);

    for(int i=0; i<numQueries; i++){
        int beginIdx = queryList[i][0];
        int endIdx = queryList[i][1];

        if(!beginIdx)
            printf("For begin index %d to end index %d, sum is: %d\n", beginIdx, endIdx, prefixSum[endIdx]);
        else{
            int querySum = prefixSum[endIdx] - prefixSum[beginIdx-1];
            printf("For begin index %d to end index %d, sum is: %d\n", beginIdx, endIdx, querySum);
        }
        
    }
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int test_array_1[] = {2, 8, 3, 9, 6, 5, 4};
    int queryList_1[][2] = {{0, 2}, {1, 3}, {2, 6}};

    printf("\nContents of array\n");
    printArray(test_array_1, 6);
    processQueriesAndPrintSum(test_array_1, 7, queryList_1, 3);

    return 0;
}