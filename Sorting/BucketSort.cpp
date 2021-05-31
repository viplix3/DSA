#include<bits/stdc++.h>
using namespace std;

void bucketSort(vector<int> &arr, int numBuckets)
{
    int max_value = *max_element(arr.begin(), arr.end());
    max_value += 1;
    
    vector<int> bucket[numBuckets];
    for(int i=0; i<arr.size(); i++){
        int elem_bucket = (numBuckets * arr[i]) / max_value;
        bucket[elem_bucket].push_back(arr[i]);
    }

    for(int i=0; i<numBuckets; i++)
        sort(bucket[i].begin(), bucket[i].end());

    int arrIdx = 0;
    for(int i=0; i<numBuckets; i++)
        for(int j=0; j<bucket[i].size(); j++)
            arr[arrIdx++] = bucket[i][j];
}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int numElements, numBuckets;
    vector<int> arr;

    printf("Enter number of elements in the array: ");
    scanf("%d", &numElements);

    printf("\nEnter number of buckets to be used for sorting: ");
    scanf("%d", &numBuckets);
    
    printf("\nEnter the array: ");
    for(int i=0; i<numElements; i++){
        int temp;
        scanf("%d", &temp);
        arr.push_back(temp);
    }
    
    printf("\nInput array: ");
    printArray(arr);

    bucketSort(arr, numBuckets);
    printf("Sorted array: ");
    printArray(arr);

    return 0;
}