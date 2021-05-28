#include<bits/stdc++.h>
using namespace std;

int lomutoPartition(vector<int> &arr, int lowIdx, int highIdx)
{
    int pivot = arr[highIdx];
    int pivotPosition = lowIdx-1;

    for(int i=lowIdx; i<=highIdx-1; i++){
        if(arr[i] < pivot){
            pivotPosition += 1;
            swap(arr[pivotPosition], arr[i]);
        }
    }
    swap(arr[pivotPosition+1], arr[highIdx]);
    return pivotPosition+1;
}

void quickSort(vector<int> &arr, int lowIdx, int highIdx)
{
    /*
        When using Lomuto's partition, we will get a partition index such the element at that partition index is at its
        correct position already. So we need to sort the left and right of the parition index.
    */
    if(lowIdx < highIdx){
        int partitionIdx = lomutoPartition(arr, lowIdx, highIdx);
        quickSort(arr, lowIdx, partitionIdx-1);
        quickSort(arr, partitionIdx+1, highIdx);
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

    printf("\nSorted array: ");
    quickSort(arr, 0, arr.size()-1);
    printArray(arr);

    return 0;
}