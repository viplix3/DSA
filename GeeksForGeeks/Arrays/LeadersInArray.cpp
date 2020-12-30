#include<bits/stdc++.h>
using namespace std;

void findAndPrintLeaders(int arr[], int size)
{
    int currentLeader = arr[size-1];
    printf("arr[%d]: %d\n", size-1, currentLeader);
    for(int i=size-2; i>0; i--){
        if(arr[i] > currentLeader){
            currentLeader = arr[i];
            printf("arr[%d]: %d\n", i, currentLeader);
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
    int test_array_1[] = {1, 2, 3, 4, 5};
    int test_array_2[] = {7, 10, 4, 10, 6, 5, 2};

    printf("\nContents of array\n");
    printArray(test_array_1, 5);
    printf("Leaders in the given array\n");
    findAndPrintLeaders(test_array_1, 5);

    printf("\nContents of array\n");
    printArray(test_array_2, 7);
    printf("Leaders in the given array\n");
    findAndPrintLeaders(test_array_2, 7);

    return 0;
}