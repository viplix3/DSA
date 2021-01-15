// https://www.hackerrank.com/challenges/crush/problem

#include <bits/stdc++.h>
using namespace std;

int main(){
    int arrSize, numQueries;
    scanf("%d %d", &arrSize, &numQueries);
    
    long *prefixSumArray = new long[arrSize+1]();
    int leftIdx, rightIdx;
    long summand; 
    for(int i=0; i<numQueries; i++){
        scanf("%d %d %ld", &leftIdx, &rightIdx, &summand);
        
        prefixSumArray[leftIdx] += summand;
        if((rightIdx+1) <= arrSize)
            prefixSumArray[rightIdx+1] -= summand;
    }

    long maxVal = LONG_MIN;
    for(int i=1; i<=arrSize; i++){
        prefixSumArray[i] += prefixSumArray[i-1];
        maxVal = max(maxVal, prefixSumArray[i]);
    }
    printf("%ld\n", maxVal);

    return 0;
}
