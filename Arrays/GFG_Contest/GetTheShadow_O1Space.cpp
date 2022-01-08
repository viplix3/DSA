#include<bits/stdc++.h>
using namespace std;

void findAndPrintRepeatingAndMissingNumber(int arr[], int arrSize)
{
    for(int i = 0;  i < arrSize; i++)
        arr[i] -= 1;
        
    for(int i = 0; i < arrSize; i++)
        arr[arr[i] % arrSize] += arrSize;

    for(int i = 0; i < arrSize; i++)
        arr[i] /= arrSize;
    
    int repeatingNum, missingNum;
    
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] == 0)
            missingNum = i + 1;
        if(arr[i] == 2)
            repeatingNum = i+1;
    }
    
    cout << repeatingNum << " " << missingNum << endl;
    
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