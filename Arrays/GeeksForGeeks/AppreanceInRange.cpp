#include<bits/stdc++.h>
using namespace std;

void getPrefixSum(int arr[], int arrSize, int prefixSumArr[])
{
    prefixSumArr[0] = arr[0];
    for(int i=1; i<arrSize; i++)
        prefixSumArr[i] = prefixSumArr[i-1] + arr[i];
}

int getArrayMaximum(int array[], int numElements, bool returnIdx)
{
    int maximumElement = array[0];
    int elementIdx = 0;
    for(int i=1; i<numElements; i++)
        if(array[i] > maximumElement){
            maximumElement = array[i];
            elementIdx = i;
        }
    if(returnIdx)
        return elementIdx; 
    return maximumElement;
}

int findMaximumOccuringElementIdx(int leftRangeArray[], int rightRangeArray[], int numRanges)
{
    // Take a zero initialized array and mark off beginning of the ranges by 1 and (end+1) of ranges by -1.
    // Take pre-fix sum of the array created and it will provide the occurent count of each element.
    int maxRange = max(getArrayMaximum(leftRangeArray, numRanges, false), getArrayMaximum(rightRangeArray, numRanges, false));
    int counterArray[maxRange];
    memset(counterArray, 0, sizeof(counterArray));

    for(int i=0; i<numRanges; i++){
        counterArray[leftRangeArray[i]]++;
        counterArray[rightRangeArray[i]+1]--;
    }

    getPrefixSum(counterArray, maxRange, counterArray);
    int maxOccuringElementIdx = getArrayMaximum(counterArray, maxRange, true);
    return maxOccuringElementIdx;
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int leftRange_testArray_1[] = {1, 2, 5, 15};
    int rightRange_testArray_1[] = {5, 8, 7, 18};
    int leftRange_testArray_2[] = {1, 2, 3};
    int rightRange_testArray_2[] = {3, 5, 7};
    int numRanges;

    numRanges = 4;
    printf("\nContents of left range array\n");
    printArray(leftRange_testArray_1, numRanges);
    printf("Contents of right range array\n");
    printArray(rightRange_testArray_1, numRanges);
    printf("As per the given ranges, most frequent element would be present at index: %d\n", 
        findMaximumOccuringElementIdx(leftRange_testArray_1, rightRange_testArray_1, numRanges));

    numRanges = 3;
    printf("\nContents of left range array\n");
    printArray(leftRange_testArray_2, numRanges);
    printf("Contents of right range array\n");
    printArray(rightRange_testArray_2, numRanges);
    printf("As per the given ranges, most frequent element would be present at index: %d\n", 
        findMaximumOccuringElementIdx(leftRange_testArray_2, rightRange_testArray_2, numRanges));
    return 0;
}