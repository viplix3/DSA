#include<bits/stdc++.h>
using namespace std;

int getFirstOccurenceIdx(vector<int> arr, int element)
{
    int beginIdx=0, endIdx=arr.size()-1, currOccIdx=arr.size();

    while(beginIdx <= endIdx){
        int midIdx = (beginIdx + endIdx) / 2;

        if(arr[midIdx] == element){
            currOccIdx = min(currOccIdx, midIdx);

            if(arr[midIdx-1] < element)
                return currOccIdx;
            else if(arr[midIdx-1] == element)
                endIdx = midIdx-1;
        }

        else if(arr[midIdx] < element)
            beginIdx = midIdx+1;
        else
            endIdx = midIdx-1;
    }
    return -1;
}

int getLastOccurenceIdx(vector<int> arr, int element)
{
    int beginIdx=0, endIdx=arr.size()-1, currOccIdx=-1;

    while(beginIdx <= endIdx){
        int midIdx = (beginIdx + endIdx) / 2;

        if(arr[midIdx] == element){
            currOccIdx = max(currOccIdx, midIdx);

            if((midIdx == arr.size()-1) || (arr[midIdx+1] > element))
                return currOccIdx;
            else if(arr[midIdx+1] == element)
                beginIdx = midIdx+1;
        }

        else if(arr[midIdx] < element)
            beginIdx = midIdx+1;
        else
            endIdx = midIdx-1;
    }
    return -1;
}

int getNumOccurrences(vector<int> &arr, int element)
{
    int firstOccurrenceIdx = getFirstOccurenceIdx(arr, element);
    
    if(firstOccurrenceIdx == -1)
        return 0;
    
    int lastOccurrentIdx = getLastOccurenceIdx(arr, element);
    int numOccurrences = lastOccurrentIdx - firstOccurrenceIdx + 1;
    return numOccurrences;
}

int main(){
    printf("Enter number of elements in the array: ");
    int numElements;
    scanf("%d", &numElements);

    printf("\nEnter the array: ");
    vector<int> arr(numElements);
    for(int i=0; i<numElements; i++)
        scanf("%d", &arr[i]);
    
    printf("\nEnter the element to be searched for: ");
    int searchElement;
    scanf("%d", &searchElement);
    int numOccurrences = getNumOccurrences(arr, searchElement);
    if(numOccurrences == 0)
        printf("\nElement not present in the provided array\n");
    else
        printf("\nElement %d occurs %d times in the provided array\n", searchElement, numOccurrences);


    return 0;
}