#include<bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int size, int requiredSum)
{
    int currentSum = arr[0];
    int windowInit = 0;

    for(int i=1; i<size; i++){
        if(currentSum == requiredSum)
            return true;
        
        currentSum += arr[i];
        while((currentSum>requiredSum) && (windowInit<i)){
            currentSum -= arr[windowInit];
            windowInit++;
        }
    }
    return (currentSum == requiredSum);
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int test_array_1[] = {1, 4, 20, 3, 10, 5};
    int test_array_2[] = {1, 4, 0, 0, 3, 10, 5};
    int test_array_3[] = {2, 4};
    int requiredSum;

    printf("\nContents of array\n");
    printArray(test_array_1, 6);
    requiredSum = 15;
    if(subArrayExists(test_array_1, 6, requiredSum))
        printf("A sub-array with sum %d exists\n", requiredSum);
    else
        printf("No sub-array with sum %d exists.\n", requiredSum);

    printf("\nContents of array\n");
    printArray(test_array_2, 7);
    requiredSum = 7;
    if(subArrayExists(test_array_2, 7, requiredSum))
        printf("A sub-array with sum %d exists\n", requiredSum);
    else
        printf("No sub-array with sum %d exists.\n", requiredSum);

    printf("\nContents of array\n");
    printArray(test_array_3, 2);
    requiredSum = 3;
    if(subArrayExists(test_array_3, 2, requiredSum))
        printf("A sub-array with sum %d exists\n", requiredSum);
    else
        printf("No sub-array with sum %d exists.\n", requiredSum);
    return 0;
}