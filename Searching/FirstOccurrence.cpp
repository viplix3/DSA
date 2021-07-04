#include<bits/stdc++.h>
using namespace std;

int getFirstOccurenceIdx(vector<int> arr, int element)
{
    int beginIdx=0, endIdx=arr.size()-1;

    while(beginIdx <= endIdx){
        int midIdx = (beginIdx + endIdx) / 2;

        if(arr[midIdx] < element)
            beginIdx = midIdx+1;
        else if(arr[midIdx] > element)
            endIdx = midIdx-1;
        else {
            if(midIdx == 0 || arr[midIdx-1] != arr[midIdx])
                return midIdx;
            else
                endIdx = midIdx-1;
        }
    }
    return -1;
}

int main(){
    int numElements;
    scanf("%d", &numElements);

    vector<int> arr(numElements);
    for(int i=0; i<numElements; i++)
        scanf("%d", &arr[i]);
    
    int searchElement;
    scanf("%d", &searchElement);
    int leastOccIdx = getFirstOccurenceIdx(arr, searchElement);
    if(leastOccIdx == -1)
        printf("Element not present in the provided array\n");
    else
        printf("Element %d found at index %d in the provided array\n", searchElement, leastOccIdx);


    return 0;
}