#include<bits/stdc++.h>
using namespace std;

void findAndPrintFrequencies(int arr[], int size)
{
    int counter = 1;
    int i = 0;
    while(i<size){
        while((i<size-1) && (arr[i]==arr[i+1])){
            i++;
            counter++;
        }
        printf("Frequency for %d: %d\n", arr[i], counter);
        counter = 1;
        i++;
    }
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int test_array_1[] = {10, 10, 10, 25, 30, 30};
    int test_array_2[] = {10, 10, 10, 10};
    int test_array_3[] = {10, 20, 30};
    int test_array_4[] = {10, 10, 20, 20, 30, 30};

    printf("\nContents of array\n");
    printArray(test_array_1, 6);
    findAndPrintFrequencies(test_array_1, 6);

    printf("\nContents of array\n");
    printArray(test_array_2, 4);
    findAndPrintFrequencies(test_array_2, 4);

    printf("\nContents of array\n");
    printArray(test_array_3, 3);
    findAndPrintFrequencies(test_array_3, 3);

    printf("\nContents of array\n");
    printArray(test_array_4, 6);
    findAndPrintFrequencies(test_array_4, 6);
    return 0;
}