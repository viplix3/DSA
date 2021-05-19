#include<bits/stdc++.h>
using namespace std;

double sortedArrayMedian(vector<int> &arr_1, vector<int> &arr_2)
{
    /*
        We are trying to divide both the sorted arrays into 2 halves.
        Out goal is to get the division index of both arrays such that
            1. num_elements(left_half(arr_1 + arr_2))[+-1] == num_elements(right_half(arry_1 + arr_2)) -> Always
            2. left_half(arr_1 + arr_2) < right_half(arr_1 + arr_2) --> End goal
    */
    int startIdx = 0, endIdx = arr_1.size()-1;
    int numElem_arr_1 = arr_1.size(), numElem_arr_2 = arr_2.size();

    while(startIdx <= endIdx){
        int midIdx_arr_1 = (startIdx + endIdx) / 2; // Elements before midIdx_arr_1 is the left half of array_1
        int midIdx_arr_2 = ((numElem_arr_1 + numElem_arr_2 + 1) / 2) - midIdx_arr_1; // Getting the midIdx for arr_2 to meet condition #1

        int maxLeft_arr_1 = (midIdx_arr_1 == 0) ? INT_MIN: arr_1[midIdx_arr_1 - 1];
        int maxLeft_arr_2 = (midIdx_arr_2 == 0) ? INT_MIN: arr_2[midIdx_arr_2 - 1];
        int maxLeft = max(maxLeft_arr_1, maxLeft_arr_2);

        int minRight_arr_1 = (midIdx_arr_1 == numElem_arr_1) ? INT_MAX: arr_1[midIdx_arr_1];
        int minRight_arr_2 = (midIdx_arr_2 == numElem_arr_2) ? INT_MAX: arr_2[midIdx_arr_2];
        int minRight = min(minRight_arr_1, minRight_arr_2);

        if(maxLeft_arr_1 <= minRight_arr_2 && maxLeft_arr_2 <= minRight_arr_1){
            // If we fall inside this block then condition #2 is met
            if(((numElem_arr_1 + numElem_arr_2) % 2) == 0) // Even number of elements
                return (double) ((maxLeft + minRight)/2.0);
            else
                return (double) maxLeft;
        }
        if(maxLeft_arr_1 > minRight_arr_2)
            endIdx = midIdx_arr_1 - 1;
        else
            startIdx = midIdx_arr_1 + 1;

    }
    return -1.0;
}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    vector<int> testArray1 = {10, 20, 30, 40, 50};
    vector<int> testArray2 = {5, 15, 25, 35, 45, 55, 65, 75, 85};
    double median;
    
    printf("Array 1: \n");
    printArray(testArray1);
    printf("Array 2: \n");
    printArray(testArray2);
    median = testArray1.size() < testArray2.size() ? sortedArrayMedian(testArray1, testArray2) : \
                sortedArrayMedian(testArray2, testArray1);
    printf("Median element after merging testArray 1 and testArray 2: %f\n", median);

    testArray1 = {10, 20, 30};
    testArray2 = {5, 15, 25, 35, 45};
    printf("Array 1: \n");
    printArray(testArray1);
    printf("Array 2: \n");
    printArray(testArray2);
    median = testArray1.size() < testArray2.size() ? sortedArrayMedian(testArray1, testArray2) : \
                sortedArrayMedian(testArray2, testArray1);
    printf("Median element after merging testArray 1 and testArray 2: %f\n", median);

    testArray1 = {30, 40, 50, 60};
    testArray2 = {5, 6, 7, 8, 9};
    printf("Array 1: \n");
    printArray(testArray1);
    printf("Array 2: \n");
    printArray(testArray2);
    median = testArray1.size() < testArray2.size() ? sortedArrayMedian(testArray1, testArray2) : \
                sortedArrayMedian(testArray2, testArray1);
    printf("Median element after merging testArray 1 and testArray 2: %f\n", median);

    return 0;
}