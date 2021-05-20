#include<bits/stdc++.h>
using namespace std;

int ternarySearchIdx(vector<int> &arr, int element)
{
    int beginIdx = 0, endIdx = arr.size()-1;

    while(beginIdx <= endIdx){
        int firstPartitionEndIdx = beginIdx + ((endIdx - beginIdx)/3);
        int secondPartitionEndIdx = endIdx - ((endIdx - beginIdx)/3);

        /*
            Array divided into 3 partition
            First Partition: arr[beginIdx: firstPartitionEndIdx]
            Second Partition: arr[firstPartitionEndIdx+1: secondPartitionEndIdx]
            Third Partition: arr[secondPartitionEndIdx+1: endIdx]
        */

        // Element found
        if(arr[firstPartitionEndIdx] == element)
            return firstPartitionEndIdx;
        if(arr[secondPartitionEndIdx] == element)
            return secondPartitionEndIdx;

        // Element not found, sub-array search
        if(element < arr[firstPartitionEndIdx])
            endIdx = firstPartitionEndIdx-1; // Element is present in the first partition, skipping the other 2
        else if(element > arr[secondPartitionEndIdx])
            beginIdx = secondPartitionEndIdx+1; // Element is not present in the first or second partition, will search in the last one
        else {
            beginIdx = firstPartitionEndIdx+1; // Element is present in the second partition
            endIdx = secondPartitionEndIdx-1;
        }
    }

    return -1;
}

int main(){
    int numElements;
    printf("Enter the number of elements inthe input array: ");
    scanf("%d", &numElements);

    printf("\nEnter the sorted array: ");
    vector<int> array(numElements);
    for(int i=0; i<numElements; i++)
        scanf("%d", &array[i]);
        
    printf("\nEnter the elements to be searched for: ");
    int searchElememnt;
    scanf("%d", &searchElememnt);
    int elementIdx = ternarySearchIdx(array, searchElememnt);
    if(elementIdx == -1)
        printf("\nElement not found in the provided input array\n");
    else
        printf("\nElement found at index %d\n", elementIdx);
    

    return 0;
}