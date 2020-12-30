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

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int test_array_1[] = {1, 2, 3, 4, 5};
    int test_array_2[] = {5, 4, 3, 2, 1};
    int test_array_3[] = {30, 7, 6, 5, 10};

    printf("\nContents of test array\n");
    printArray(test_array_1, 5);
    reverseArray(test_array_1, 5);
    printf("Contents of reversed array\n");
    printArray(test_array_1, 5);

    printf("\nContents of test array\n");
    printArray(test_array_2, 5);
    reverseArray(test_array_2, 5);
    printf("Contents of reversed array\n");
    printArray(test_array_2, 5);

    printf("\nContents of test array\n");
    printArray(test_array_3, 5);
    reverseArray(test_array_3, 5);
    printf("Contents of reversed array\n");
    printArray(test_array_3, 5);

    return 0;
}