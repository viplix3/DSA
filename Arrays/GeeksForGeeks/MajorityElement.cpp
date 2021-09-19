#include<bits/stdc++.h>
using namespace std;

int getCandidateMajorityElement(int arr[], int size)
{
    int candidate = arr[0];
    int voteCount = 1;

    for(int i=1; i<size; i++){
        if(arr[i] == candidate)
            voteCount++;
        else
            voteCount--;

        if(voteCount == 0){
            voteCount = 1;
            candidate = arr[i];
        }
    }
    return candidate;
}

int getMajorityElementIndex(int arr[], int size)
{
    int candidateMajorityElement = getCandidateMajorityElement(arr, size);
    int counter = 0;
    
    for(int i=0; i<size; i++)
        if(arr[i] == candidateMajorityElement)
            counter++;
    
    if(counter > size/2)
        return candidateMajorityElement;
    else
        return -1;
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int test_array_1[] = {8, 3, 4, 8, 8};
    int test_array_2[] = {3, 7, 4, 7, 7, 5};
    int test_array_3[] = {20, 30, 40, 50, 50, 50, 50};
    int test_array_4[] = {8, 7, 6, 8, 6, 6, 6, 6};
    int majorityElementIndex = -1;

    printf("\nContents of array\n");
    printArray(test_array_1, 5);
    majorityElementIndex = getMajorityElementIndex(test_array_1, 5);
    if(majorityElementIndex != -1)
        printf("Majority element in the given array: %d\n", majorityElementIndex);
    else
        printf("No majority element exists in the array\n");

    printf("\nContents of array\n");
    printArray(test_array_2, 6);
    majorityElementIndex = getMajorityElementIndex(test_array_2, 6);
    if(majorityElementIndex != -1)
        printf("Majority element in the given array: %d\n", majorityElementIndex);
    else
        printf("No majority element exists in the array\n");

    printf("\nContents of array\n");
    printArray(test_array_3, 7);
    majorityElementIndex = getMajorityElementIndex(test_array_3, 7);
    if(majorityElementIndex != -1)
        printf("Majority element in the given array: %d\n", majorityElementIndex);
    else
        printf("No majority element exists in the array\n");

    printf("\nContents of array\n");
    printArray(test_array_4, 8);
    majorityElementIndex = getMajorityElementIndex(test_array_4, 8);
    if(majorityElementIndex != -1)
        printf("Majority element in the given array: %d\n", majorityElementIndex);
    else
        printf("No majority element exists in the array\n");

    return 0;
}