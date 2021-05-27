#include<bits/stdc++.h>
using namespace std;

int countAndMerge(vector<int> &arr, int lowIdx, int midIdx, int highIdx)
{
    int numLeft = midIdx - lowIdx + 1;
    int numRight = highIdx - midIdx;

    vector<int> leftArr(numLeft);
    vector<int> rightArr(numRight);
    
    for(int i=0; i<numLeft; i++)
        leftArr[i] = arr[i+lowIdx];
    
    for(int j=0; j<numRight; j++)
        rightArr[j] = arr[j+midIdx+1];

    int leftItr = 0, rightItr = 0, arrItr = lowIdx;
    int numInversions = 0;

    while(leftItr < numLeft && rightItr < numRight){
        if(leftArr[leftItr] <= rightArr[rightItr]){
            arr[arrItr] = leftArr[leftItr];
            arrItr += 1;
            leftItr += 1;
        }
        else if(leftArr[leftItr] > rightArr[rightItr]){
            arr[arrItr] = rightArr[rightItr];
            arrItr += 1;
            rightItr += 1;
            numInversions += numLeft - leftItr;
        }
    }
    while(leftItr < numLeft){
        arr[arrItr] = leftArr[leftItr];
        arrItr += 1;
        leftItr += 1;
    }
    while(rightItr < numRight){
        arr[arrItr] = rightArr[rightItr];
        arrItr += 1;
        rightItr += 1;
    }
    return numInversions;
}

int countInversions(vector<int> &arr, int lowIdx, int highIdx)
{
    int numInversions = 0;
    if(highIdx > lowIdx){
        int midIdx = lowIdx + (highIdx - lowIdx) / 2;
        numInversions += countInversions(arr, lowIdx, midIdx);
        numInversions += countInversions(arr, midIdx+1, highIdx);
        numInversions += countAndMerge(arr, lowIdx, midIdx, highIdx);
    }
    return numInversions;
}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int numElems;
    printf("\nEnter number of elements: ");
    scanf("%d", &numElems);

    int temp;
    vector<int> test_arr;
    printf("\nEnter the array: ");
    for(int i=0; i<numElems; i++){
        scanf("%d", &temp);
        test_arr.push_back(temp);
    }

    printf("\nInput array: ");
    printArray(test_arr);
    printf("\nNumber of inversions in the input array: %d\n", countInversions(test_arr, 0, test_arr.size()-1));

    return 0;
}

/*
I/P
5
2 4 1 3 5
O/P
3

I/P
4
10 20 30 40
O/P
0

I/P
4
40 30 20 10
O/P
6

I/P
8
2 5 8 11 3 6 9 13
O/P
6
*/