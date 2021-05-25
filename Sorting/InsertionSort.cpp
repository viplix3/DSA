#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr)
{
    for(int i=0; i<arr.size()-1; i++){
        int minIdx = i;
        for(int j=i+1; j<arr.size(); j++)
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        swap(arr[minIdx], arr[i]);
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
    insertionSort(arr);
    printArray(arr);

    return 0;
}