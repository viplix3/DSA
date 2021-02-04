#include<bits/stdc++.h>
using namespace std;

int binarySeachIdx(vector<int> &arr, int element, int beginIdx, int endIdx)
{
    while(beginIdx <= endIdx){
        int midIdx = (beginIdx + endIdx) / 2;

        if(arr[midIdx] == element)
            return midIdx;
        if(arr[midIdx] < element)
            beginIdx = midIdx+1;
        else
            endIdx = midIdx-1;
    }
    return -1;
}

int infineArraySearch(vector<int> &arr, int element)
{
    if(arr[0] == element)
        return 0;
    
    int searchIdx = 1;
    while(arr[searchIdx] < element)
        searchIdx *= 2;
    if(arr[searchIdx] == element)
        return searchIdx;
    
    return binarySeachIdx(arr, element, (searchIdx/2)+1, searchIdx-1);
}