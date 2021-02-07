#include<bits/stdc++.h>
using namespace std;

void findAndPrintPair(vector<int> arr, int requiredSum)
{
    int startIdx = 0, endIdx = arr.size()-1;
    int currentSum = arr[startIdx] + arr[endIdx];

    while(startIdx < endIdx){
        currentSum = arr[startIdx] + arr[endIdx];
        if(currentSum == requiredSum){
            printf("Element pair (arr[%d], arr[%d]) or (%d, %d) will have the required sum %d\n", 
                    startIdx, endIdx, arr[startIdx], arr[endIdx], currentSum);
            return;
        }
        if(currentSum < requiredSum)
            startIdx += 1;
        else
            endIdx -= 1;
    }
    printf("Given array doesn't contain any pair having required sum %d\n", requiredSum);
}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    vector<int> test_array_1 = {2, 5, 8, 12, 30};
    vector<int> test_array_2 = {3, 8, 13, 18};
    vector<int> test_array_3 = {2, 4, 8, 9, 11, 12, 20, 30};
    int requiredSum;

    requiredSum = 17;
    printf("\nElements in the input array: ");
    printArray(test_array_1);
    findAndPrintPair(test_array_1, requiredSum);

    requiredSum = 14;
    printf("\nElements in the input array: ");
    printArray(test_array_2);
    findAndPrintPair(test_array_2, requiredSum);

    requiredSum = 23;
    printf("\nElements in the input array: ");
    printArray(test_array_3);
    findAndPrintPair(test_array_3, requiredSum);
    return 0;
}