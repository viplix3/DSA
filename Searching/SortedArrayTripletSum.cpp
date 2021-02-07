#include<bits/stdc++.h>
using namespace std;

bool isSumPair(vector<int> arr, int startIdx, int endIdx, int requiredSum)
{
    int currentSum = arr[startIdx] + arr[endIdx];
    while(startIdx < endIdx){
        currentSum = arr[startIdx] + arr[endIdx];
        if(currentSum == requiredSum)
            return true;
        if(currentSum < requiredSum)
            startIdx += 1;
        else
            endIdx -= 1;
    }
    return false;
}

bool isSumTriplet(vector<int> arr, int requiredSum)
{
    for(int i=0; i<arr.size(); i++){
        if(isSumPair(arr, i+1, arr.size()-1, requiredSum-arr[i]))
            return true;
    }
    return false;
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
    printf("Required sum: %d\n", requiredSum);
    printf("Is there any triplet with required sum in the array: %d\n", isSumTriplet(test_array_1, requiredSum));

    requiredSum = 14;
    printf("\nElements in the input array: ");
    printArray(test_array_2);
    printf("Required sum: %d\n", requiredSum);
    printf("Is there any triplet with required sum in the array: %d\n", isSumTriplet(test_array_2, requiredSum));

    requiredSum = 23;
    printf("\nElements in the input array: ");
    printArray(test_array_3);
    printf("Required sum: %d\n", requiredSum);
    printf("Is there any triplet with required sum in the array: %d\n", isSumTriplet(test_array_3, requiredSum));

    requiredSum = 32;
    printf("\nElements in the input array: ");
    printArray(test_array_3);
    printf("Required sum: %d\n", requiredSum);
    printf("Is there any triplet with required sum in the array: %d\n", isSumTriplet(test_array_3, requiredSum));
    return 0;
}