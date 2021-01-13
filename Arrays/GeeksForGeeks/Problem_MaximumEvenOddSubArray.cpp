#include<bits/stdc++.h>
using namespace std;

int getMaximumEvenOddSubArrayLength(int arr[], int size)
{
    int maxLength, currentLength, i;
    i = maxLength = currentLength = 1;

    while(i<size){
        while((i<size) && (arr[i]%2 != arr[i-1]%2)){
            i++;
            currentLength++;
        }
        maxLength = max(maxLength, currentLength);
        currentLength = 1;
        i++;
    }
    return maxLength;
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int test_array_1[] = {10, 12, 14, 7, 8};
    int test_array_2[] = {7, 10, 13, 14};
    int test_array_3[] = {10, 12, 14};
    int test_array_4[] = {5, 10, 20, 6, 3, 8};

    printf("\nContents of array\n");
    printArray(test_array_1, 5);
    printf("Maximum length of even odd sub-array: %d\n", getMaximumEvenOddSubArrayLength(test_array_1, 5));

    printf("\nContents of array\n");
    printArray(test_array_2, 4);
    printf("Maximum length of even odd sub-array: %d\n", getMaximumEvenOddSubArrayLength(test_array_2, 4));

    printf("\nContents of array\n");
    printArray(test_array_3, 3);
    printf("Maximum length of even odd sub-array: %d\n", getMaximumEvenOddSubArrayLength(test_array_3, 3));

    printf("\nContents of array\n");
    printArray(test_array_4, 6);
    printf("Maximum length of even odd sub-array: %d\n", getMaximumEvenOddSubArrayLength(test_array_4, 6));

    return 0;
}