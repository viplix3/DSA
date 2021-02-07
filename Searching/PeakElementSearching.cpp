#include<bits/stdc++.h>
using namespace std;

int findPeakElementIdx(vector<int> arr)
{
    int startIdx = 0, endIdx = arr.size()-1;

    while(startIdx <= endIdx){
        int midIdx = (startIdx+endIdx)/2;
        if( ((midIdx == 0) || (arr[midIdx-1] <= arr[midIdx])) &&
            ((midIdx == arr.size()-1) || (arr[midIdx] >= arr[midIdx+1])) )
                return midIdx;
        
        if(midIdx > 0 && (arr[midIdx-1] >= arr[midIdx]))
            endIdx = midIdx-1;
        else
            startIdx = midIdx+1;
    }
    // Will never reach this point as an array, no matter what the arrangement of elements is will always have a peak element
    return -1; 
}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    vector<int> test_array_1 = {5, 20, 40, 30, 20, 50, 60};
    vector<int> test_array_2 = {120, 80, 40, 30, 20, 50, 60};
    vector<int> test_array_3 = {10, 7, 8, 20, 12};

    printf("Elements in the input array: ");
    printArray(test_array_1);
    printf("Peak element index in the given array: %d\n", findPeakElementIdx(test_array_1));

    printf("\nElements in the input array: ");
    printArray(test_array_2);
    printf("Peak element index in the given array: %d\n", findPeakElementIdx(test_array_2));

    printf("\nElements in the input array: ");
    printArray(test_array_3);
    printf("Peak element index in the given array: %d\n", findPeakElementIdx(test_array_3));

    return 0;
}