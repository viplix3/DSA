#include<bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int size)
{
    int begin = 0;
    int end = size-1;

    while(begin < end){
        swap(arr[begin], arr[end]);
        begin++;
        end--;
    }
}

void leftRotateArray(int arr[], int size, int numRotations)
{
    numRotations = numRotations%size; //if numRotations = size + x, it is same as rotation by x

    reverseArray(arr, numRotations);
    reverseArray(arr+numRotations, size-numRotations);
    reverseArray(arr, size);
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int test_array_1[] = {5, 1, 2, 3, 4};
    int test_array_2[] = {30, 5, 20};
    int test_array_3[] = {15, 10, 5, 30};

    printf("\nContents of test array\n");
    printArray(test_array_1, 5);
    leftRotateArray(test_array_1, 5, 1);
    printf("Contents of rotated array after 1 left rotation\n");
    printArray(test_array_1, 5);

    printf("\nContents of test array\n");
    printArray(test_array_2, 3);
    leftRotateArray(test_array_2, 3, 1);
    printf("Contents of rotated array after 1 left rotation\n");
    printArray(test_array_2, 3);

    printf("\nContents of test array\n");
    printArray(test_array_1, 5);
    leftRotateArray(test_array_1, 5, 2);
    printf("Contents of rotated array after 2 left rotations\n");
    printArray(test_array_1, 5);

    printf("\nContents of test array\n");
    printArray(test_array_3, 4);
    leftRotateArray(test_array_3, 4, 3);
    printf("Contents of rotated array after 3 left rotations\n");
    printArray(test_array_3, 4);

    printf("\nContents of test array\n");
    printArray(test_array_3, 4);
    leftRotateArray(test_array_3, 4, 5);
    printf("Contents of rotated array after 5 left rotations\n");
    printArray(test_array_3, 4);

    return 0;
}