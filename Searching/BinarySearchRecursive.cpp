
#include<bits/stdc++.h>
using namespace std;

int binarySeachIdx(vector<int> &arr, int element, int beginIdx, int endIdx)
{
    if(beginIdx > endIdx)
        return -1;

    int midIdx = (beginIdx + endIdx) / 2;
    if(arr[midIdx] == element)
        return midIdx;
    if(arr[midIdx] < element)
        beginIdx = midIdx+1;
    else
        endIdx = midIdx-1;
    
    return binarySeachIdx(arr, element, beginIdx, endIdx);
}

int main(){
    int numElements;
    scanf("%d", &numElements);

    vector<int> array(numElements);
    for(int i=0; i<numElements; i++)
        scanf("%d", &array[i]);
        
    int searchElememnt;
    scanf("%d", &searchElememnt);
    int elementIdx = binarySeachIdx(array, searchElememnt, 0, array.size());
    if(elementIdx == -1)
        printf("Element not found in the provided input array\n");
    else
        printf("Element found at index %d\n", elementIdx);
    

    return 0;
}