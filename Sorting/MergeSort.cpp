
#include<bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int> &arr, int lowIdx, int midIdx, int highIdx)
{
    int leftArrElem = midIdx - lowIdx + 1;
    int rightArrElem = highIdx - midIdx;

    vector<int> leftArr(leftArrElem);
    vector<int> rightArr(rightArrElem);

    for(int i=0; i<leftArrElem; i++)
        leftArr[i] = arr[i + lowIdx];
    
    for(int j=0; j<rightArrElem; j++)
        rightArr[j] = arr[j + midIdx + 1];

    int leftArrItr = 0, rightArrItr = 0, mergedArrItr = lowIdx;

    while((leftArrItr < leftArrElem) && (rightArrItr < rightArrElem)){
        if(leftArr[leftArrItr] <= rightArr[rightArrItr]){
            arr[mergedArrItr] = leftArr[leftArrItr];
            leftArrItr += 1;
            mergedArrItr += 1;
        }
        else{
            arr[mergedArrItr] = rightArr[rightArrItr];
            rightArrItr += 1;
            mergedArrItr += 1;
        }
    }

    while(leftArrItr < leftArrElem){
        arr[mergedArrItr] = leftArr[leftArrItr];
        leftArrItr += 1;
        mergedArrItr += 1;
    }

    while(rightArrItr < rightArrElem){
        arr[mergedArrItr] = rightArr[rightArrItr];
        rightArrItr += 1;
        mergedArrItr += 1;
    }
}

void mergeSort(vector<int> &arr, int lowIdx, int highIdx)
{
    if(highIdx > lowIdx){
        int midIdx = lowIdx + (highIdx - lowIdx) / 2;
        mergeSort(arr, lowIdx, midIdx);
        mergeSort(arr, midIdx+1, highIdx);
        mergeArrays(arr, lowIdx, midIdx, highIdx);
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
    mergeSort(arr, 0, arr.size()-1);
    printArray(arr);

    return 0;
}