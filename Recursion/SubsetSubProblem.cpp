#include<bits/stdc++.h>
using namespace std;

int getNumSubsetWithSum(int set[], int numSetElements, int sum, int selectionIdx=0)
{
    if((selectionIdx) == numSetElements)
        return (sum == 0);

            //Do not select current element for subset creation                       //Select current element for subset creation
    return getNumSubsetWithSum(set, numSetElements, sum, selectionIdx+1) + getNumSubsetWithSum(set, numSetElements, sum-set[selectionIdx], selectionIdx+1);
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){

    int test_array_1[] = {10, 5, 2, 3, 6};
    int test_array_2[] = {1, 2, 3};
    int test_array_3[] = {10, 20, 15};
    int test_array_4[] = {0, 10, 20, 15};
    int requiredSubsetSum;

    printf("\nContents of the input set:\n");
    printArray(test_array_1, 5);
    requiredSubsetSum = 8;
    printf("Number of subsets with sum %d in the given input set: %d\n", requiredSubsetSum, getNumSubsetWithSum(test_array_1, 5, requiredSubsetSum));

    printf("\nContents of the input set:\n");
    printArray(test_array_2, 3);
    requiredSubsetSum = 4;
    printf("Number of subsets with sum %d in the given input set: %d\n", requiredSubsetSum, getNumSubsetWithSum(test_array_2, 3, requiredSubsetSum));
    
    printf("\nContents of the input set:\n");
    printArray(test_array_3, 3);
    requiredSubsetSum = 37;
    printf("Number of subsets with sum %d in the given input set: %d\n", requiredSubsetSum, getNumSubsetWithSum(test_array_3, 3, requiredSubsetSum));

    printf("\nContents of the input set:\n");
    printArray(test_array_3, 3);
    requiredSubsetSum = 0;
    printf("Number of subsets with sum %d in the given input set: %d\n", requiredSubsetSum, getNumSubsetWithSum(test_array_3, 3, requiredSubsetSum));

    printf("\nContents of the input set:\n");
    printArray(test_array_3, 3);
    requiredSubsetSum = 25;
    printf("Number of subsets with sum %d in the given input set: %d\n", requiredSubsetSum, getNumSubsetWithSum(test_array_3, 3, requiredSubsetSum));

    printf("\nContents of the input set:\n");
    printArray(test_array_4, 4);
    requiredSubsetSum = 0;
    printf("Number of subsets with sum %d in the given input set: %d\n", requiredSubsetSum, getNumSubsetWithSum(test_array_4, 4, requiredSubsetSum));
    return 0;
}