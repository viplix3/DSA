#include<bits/stdc++.h>
using namespace std;

int findAndPrintFrequencies(vector<int> &arr)
{
    unordered_map<int, int> hash_map;

    for(int i=0; i<arr.size(); i++)
        hash_map[arr[i]] += 1;

    for(auto x: hash_map)
        printf("%d: %d\n", x.first, x.second);

    return hash_map.size();
}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    vector<int> test_array;

    test_array = {15, 12, 13, 12, 13, 13, 18};
    printf("\nInput array: ");
    printArray(test_array);
    printf("Number of distinct elements in the provided array: %d\n", findAndPrintFrequencies(test_array));

    test_array = {10, 10, 10};
    printf("\nInput array: ");
    printArray(test_array);
    printf("Number of distinct elements in the provided array: %d\n", findAndPrintFrequencies(test_array));

    test_array = {10, 11, 12};
    printf("\nInput array: ");
    printArray(test_array);
    printf("Number of distinct elements in the provided array: %d\n", findAndPrintFrequencies(test_array));

    return 0;
}