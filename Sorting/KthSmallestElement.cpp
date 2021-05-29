#include<bits/stdc++.h>
using namespace std;

int lomutoPartition(vector<int> &arr, int lowIdx, int highIdx)
{   /*
        This is also known as QuickSelect algorithm.
        Worst Case: O(N^2)
        Average Case: Theta(N)

        Even though worse case is O(N^2), this performs better than 
        sorting and indexing (O(NlogN)) on average.
    */
    int pivotIdx = lowIdx + (rand() % (highIdx - lowIdx));
    swap(arr[pivotIdx], arr[highIdx]);

    int pivot = arr[highIdx];
    int partitionIdx = lowIdx-1;

    for(int i=lowIdx; i<=highIdx-1; i++){
        if(arr[i] < pivot){
            partitionIdx += 1;
            swap(arr[i], arr[partitionIdx]);
        }
    }
    swap(arr[partitionIdx+1], arr[highIdx]);
    return partitionIdx+1;
}

int findKthSmallest(vector<int> &arr, int k)
{
    int lowIdx = 0, highIdx = arr.size()-1;

    while(highIdx > lowIdx){
        int partitionIdx = lomutoPartition(arr, lowIdx, highIdx);
        if(partitionIdx == (k-1))
            return arr[partitionIdx];
        if(partitionIdx > (k-1))
            highIdx = partitionIdx-1;
        else
            lowIdx = partitionIdx+1;
    }
    return arr[lowIdx];
}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main(){
    vector<int> test_array;
    int k;

    test_array = {0, 1, 3, 4, 5, 6};
    k = 3;
    printf("\nInput array: ");
    printArray(test_array);
    printf("%dth smallest element in the input array is: %d\n", k, findKthSmallest(test_array, k));

    test_array = {6, 5, 4, 3, 1, 0};
    k = 3;
    printf("\nInput array: ");
    printArray(test_array);
    printf("%dth smallest element in the input array is: %d\n", k, findKthSmallest(test_array, k));

    test_array = {10, 4, 5, 8, 11, 6, 26};
    k = 5;
    printf("\nInput array: ");
    printArray(test_array);
    printf("%dth smallest element in the input array is: %d\n", k, findKthSmallest(test_array, k));

    return 0;
}