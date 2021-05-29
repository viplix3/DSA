#include<bits/stdc++.h>
using namespace std;

int minimumDifference(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int minDiff = INT_MAX;
    for(int i=1; i<arr.size(); i++)
        minDiff = min(minDiff, arr[i] - arr[i-1]);
    return minDiff;
}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    vector<int> test_array;

    test_array = {1, 8, 12, 5, 18};
    printf("\nInput array: ");
    printArray(test_array);
    printf("Minimum difference in the given array: %d\n", minimumDifference(test_array));

    test_array = {8, 15};
    printf("\nInput array: ");
    printArray(test_array);
    printf("Minimum difference in the given array: %d\n", minimumDifference(test_array));

    test_array = {8, -1, 0, 3};
    printf("\nInput array: ");
    printArray(test_array);
    printf("Minimum difference in the given array: %d\n", minimumDifference(test_array));

    test_array = {10};
    printf("\nInput array: ");
    printArray(test_array);
    printf("Minimum difference in the given array: %d\n", minimumDifference(test_array));

    return 0;
}