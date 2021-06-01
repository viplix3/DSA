#include<bits/stdc++.h>
using namespace std;

void cocktailSort(vector<int> &arr)
{
    int startIdx = 0, endIdx = arr.size()-1;
    bool swapped = true;

    while(swapped){
        swapped = false;

        for(int i=startIdx; i<endIdx; i++) // Vanilla bubble sort, move largest element to last
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
                swapped = true;
            }
        
        if(swapped == false)
            break;
        
        endIdx -= 1; // Element at endIdx is at its correct position

        for(int i=endIdx; i>=startIdx; i--) // Inversed bubble sort, move smallest element to first
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
                swapped = true;
            }
        
        if(swapped == false)
            break;
        
        startIdx += 1; // Element at startIdx is at its corrent position
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

    cocktailSort(arr);
    printf("Sorted array: ");
    printArray(arr);

    return 0;
}