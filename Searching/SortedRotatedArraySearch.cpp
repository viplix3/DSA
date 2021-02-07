#include<bits/stdc++.h>
using namespace std;

int searchInSortedRotatedArray(vector<int> arr, int element)
{
    int startIdx = 0, endIdx = arr.size()-1;
    while(startIdx <= endIdx){
        int midIdx = (startIdx + endIdx) / 2;
        
        if(arr[midIdx] == element)
            return midIdx;
        if(arr[startIdx] < arr[midIdx]){ // Left half of the array is sorted
            if((arr[startIdx] <= element) && (element < arr[midIdx]))
                endIdx = midIdx-1;
            else
                startIdx = midIdx+1;
        }
        else{ // Right half of the array is sorted
            if((arr[midIdx] < element) && (element <= arr[endIdx]))
                startIdx = midIdx+1;
            else
                endIdx = midIdx-1;
        }
    }
    return -1;
}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    vector<int> test_array_1 = {10, 20, 40, 50, 5, 8};
    vector<int> test_array_2 = {100, 200, 300, 10, 20};
    vector<int> test_array_3 = {100, 200, 400, 1000, 10, 20};
    vector<int> test_array_4 = {100, 200, 500, 1000, 2000, 10, 20};
    vector<int> test_array_5 = {100, 500, 10, 20, 30, 40, 50};
    vector<int> test_array_6 = {100, 200, 300, 400, 20, 30, 40};
    int search_element, elementIdx;

    search_element = 40;
    elementIdx = -1;
    printf("\nElements of the array: ");
    printArray(test_array_1);
    printf("Element to be searched for: %d\n", search_element);
    elementIdx = searchInSortedRotatedArray(test_array_1, search_element);
    if(elementIdx != -1)
        printf("Element %d found at position %d\n", search_element, elementIdx);
    else
        printf("Element %d not found\n", search_element);
    
    search_element = 40;
    elementIdx = -1;
    printf("\nElements of the array: ");
    printArray(test_array_2);
    printf("Element to be searched for: %d\n", search_element);
    elementIdx = searchInSortedRotatedArray(test_array_2, search_element);
    if(elementIdx != -1)
        printf("Element %d found at position %d\n", search_element, elementIdx);
    else
        printf("Element %d not found\n", search_element);
    
    search_element = 10;
    elementIdx = -1;
    printf("\nElements of the array: ");
    printArray(test_array_3);
    printf("Element to be searched for: %d\n", search_element);
    elementIdx = searchInSortedRotatedArray(test_array_3, search_element);
    if(elementIdx != -1)
        printf("Element %d found at position %d\n", search_element, elementIdx);
    else
        printf("Element %d not found\n", search_element);
    
    search_element = 100;
    elementIdx = -1;
    printf("\nElements of the array: ");
    printArray(test_array_4);
    printf("Element to be searched for: %d\n", search_element);
    elementIdx = searchInSortedRotatedArray(test_array_4, search_element);
    if(elementIdx != -1)
        printf("Element %d found at position %d\n", search_element, elementIdx);
    else
        printf("Element %d not found\n", search_element);
    
    search_element = 40;
    elementIdx = -1;
    printf("\nElements of the array: ");
    printArray(test_array_5);
    printf("Element to be searched for: %d\n", search_element);
    elementIdx = searchInSortedRotatedArray(test_array_5, search_element);
    if(elementIdx != -1)
        printf("Element %d found at position %d\n", search_element, elementIdx);
    else
        printf("Element %d not found\n", search_element);
    
    search_element = 50;
    elementIdx = -1;
    printf("\nElements of the array: ");
    printArray(test_array_6);
    printf("Element to be searched for: %d\n", search_element);
    elementIdx = searchInSortedRotatedArray(test_array_6, search_element);
    if(elementIdx != -1)
        printf("Element %d found at position %d\n", search_element, elementIdx);
    else
        printf("Element %d not found\n", search_element);
    
    return 0;
}