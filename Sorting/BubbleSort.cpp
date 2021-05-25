#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    for(int i=0; i<arr.size(); i++){
        bool swapped = false;
        for(int j=0; j<arr.size()-i-1; j++)
            if(arr[j] > arr[j+1]){
                swapped = true;
                swap(arr[j], arr[j+1]);
            }
        if(swapped == false)
            break;
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
    bubbleSort(arr);
    printArray(arr);

    return 0;
}