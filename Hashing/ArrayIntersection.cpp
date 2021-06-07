#include<bits/stdc++.h>
using namespace std;

void findAndPrintIntersection(vector<int> &arr_1, vector<int> &arr_2)
{
    unordered_set<int> intersection(arr_1.begin(), arr_1.end());

    for(int i=0; i<arr_2.size(); i++)
        if(intersection.find(arr_2[i]) != intersection.end()){
            printf("%d ", arr_2[i]);
            intersection.erase(arr_2[i]);
        }
}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    vector<int> test_array_1;
    vector<int> test_array_2;

    test_array_1 = {10, 20, 10, 30, 20};
    test_array_2 = {20, 10, 10, 40};
    printf("\nInput array 1: ");
    printArray(test_array_1);
    printf("Input array 2: ");
    printArray(test_array_2);
    printf("Elements in intersection: ");
    findAndPrintIntersection(test_array_1, test_array_2);
    printf("\n");

    test_array_1 = {10, 10, 20};
    test_array_2 = {10, 10, 20};
    printf("\nInput array 1: ");
    printArray(test_array_1);
    printf("Input array 2: ");
    printArray(test_array_2);
    printf("Elements in intersection: ");
    findAndPrintIntersection(test_array_1, test_array_2);
    printf("\n");

    test_array_1 = {10};
    test_array_2 = {20};
    printf("\nInput array 1: ");
    printArray(test_array_1);
    printf("Input array 2: ");
    printArray(test_array_2);
    printf("Elements in intersection: ");
    findAndPrintIntersection(test_array_1, test_array_2);
    printf("\n");

    return 0;
}