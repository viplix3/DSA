#include<bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int> &arr, int heapSize, int rootIdx)
{
    int largestIdx = rootIdx, leftIdx = 2*rootIdx+1, rightIdx = 2*rootIdx+2;
    
    if((leftIdx < heapSize) && (arr[largestIdx] < arr[leftIdx]))
        largestIdx = leftIdx;
    
    if((rightIdx < heapSize) && (arr[largestIdx] < arr[rightIdx]))
        largestIdx = rightIdx;

    if(largestIdx != rootIdx){
        swap(arr[largestIdx], arr[rootIdx]);
        maxHeapify(arr, heapSize, largestIdx);
    }
}

void buildHeap(vector<int> &arr)
{
    // parent node of index i = floor(i-1/2)
    // In our case, we are starting with last node
    for(int i=(arr.size()-2)/2; i>=0; i--)
        maxHeapify(arr, arr.size(), i);
}

void heapSort(vector<int> &arr)
{
    buildHeap(arr);
    for(int i=arr.size()-1; i>0; i--){
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }

}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int numElements;
    vector<int> arr;

    printf("Enter number of elements in the array: ");
    scanf("%d", &numElements);
    
    printf("\nEnter the array: ");
    for(int i=0; i<numElements; i++){
        int temp;
        scanf("%d", &temp);
        arr.push_back(temp);
    }
    
    printf("\nInput array: ");
    printArray(arr);

    heapSort(arr);
    printf("\nSorted array: ");
    printArray(arr);

    return 0;
}