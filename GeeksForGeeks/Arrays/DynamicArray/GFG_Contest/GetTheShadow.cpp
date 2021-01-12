#include<bits/stdc++.h>
using namespace std;

void findAndPrintRepeatingAndMissingNumber(int arr[], int arrSize)
{
    int frequencyCounter[arrSize+1];
    memset(frequencyCounter, 0, sizeof(frequencyCounter));

    for(int i=0; i<arrSize; i++)
        frequencyCounter[arr[i]] += 1;
    
    int missingNumber, repeatingNumber;
    for(int i=1; i<arrSize+1; i++){
        if(frequencyCounter[i] == 2)
            repeatingNumber = i;
        if(frequencyCounter[i] == 0)
            missingNumber = i;
    }

    printf("%d %d\n", repeatingNumber, missingNumber);
}

int main(){
    int numTestCases;
    scanf("%d", &numTestCases);

    while(numTestCases--){
        int arraySize;
        scanf("%d", &arraySize);

        int arr[arraySize];
        for(int i=0; i<arraySize; i++)
            scanf("%d", &arr[i]);

        findAndPrintRepeatingAndMissingNumber(arr, arraySize);
    }
    return 0;
}