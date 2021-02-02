#include<bits/stdc++.h>
using namespace std;

int getNumOccurrences(vector<int> &arr, int element, int beginIdx, int endIdx)
{
    if(beginIdx > endIdx)
        return 0;

    int count = 0;
    int midIdx = (beginIdx + endIdx) / 2;
    
    if(arr[midIdx] == element){
        count += 1;
        if((midIdx > 0) && (arr[midIdx-1] == element))
            count += getNumOccurrences(arr, element, beginIdx, midIdx-1);
        if((midIdx < arr.size()-1) && (arr[midIdx+1] == element))
            count += getNumOccurrences(arr, element, midIdx+1, endIdx);
        return count;
    }
    else if(arr[midIdx] < element){
        beginIdx = midIdx+1;
        return getNumOccurrences(arr, element, beginIdx, endIdx);
    }
    else{
        endIdx = midIdx-1;
        return getNumOccurrences(arr, element, beginIdx, endIdx);
    }
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
    int numOccurrences = getNumOccurrences(arr, searchElement, 0, numElements-1);
    if(numOccurrences == 0)
        printf("\nElement not present in the provided array\n");
    else
        printf("\nElement %d occurs %d times in the provided array\n", searchElement, numOccurrences);


    return 0;
}