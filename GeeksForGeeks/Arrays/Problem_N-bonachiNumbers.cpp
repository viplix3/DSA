#include<bits/stdc++.h>
using namespace std;

void findAndPrint_N_BonachiNumbers(int bonacciWindowSize, int numElementsToPrint)
{
    int n_bonacciSeries[numElementsToPrint];
    int bonacciWindowSum = 0;
    int windowInitIdx = bonacciWindowSize-1;

    // Initializing the first n number of the n-bonacci series
    memset(n_bonacciSeries, 0, sizeof(n_bonacciSeries));
    n_bonacciSeries[bonacciWindowSize-1] = 1;

    for(int i=0; i<bonacciWindowSize; i++){
        printf("%d ", n_bonacciSeries[i]);
        bonacciWindowSum += n_bonacciSeries[i];
    }

    for(int i=bonacciWindowSize; i<numElementsToPrint; i++){
        n_bonacciSeries[i] = bonacciWindowSum;
        bonacciWindowSum += (n_bonacciSeries[i] - n_bonacciSeries[i-bonacciWindowSize]);
        printf("%d ", n_bonacciSeries[i]);
    }
    printf("\n");
}

int main(){
    int bonacciWindow, numSeriesElements;

    bonacciWindow = 2;
    numSeriesElements = 13;
    printf("Initial %d terms of %d-bonacci series\n", numSeriesElements, bonacciWindow);
    findAndPrint_N_BonachiNumbers(bonacciWindow, numSeriesElements);

    bonacciWindow = 3;
    numSeriesElements = 13;
    printf("Initial %d terms of %d-bonacci series\n", numSeriesElements, bonacciWindow);
    findAndPrint_N_BonachiNumbers(bonacciWindow, numSeriesElements);

    bonacciWindow = 4;
    numSeriesElements = 13;
    printf("Initial %d terms of %d-bonacci series\n", numSeriesElements, bonacciWindow);
    findAndPrint_N_BonachiNumbers(bonacciWindow, numSeriesElements);
    return 0;
}