#include<bits/stdc++.h>
using namespace std;

pair<int, int> pairSum(vector<int> &arr, int sum)
{
    pair<int, int> res;
    unordered_set<int> hashmap;
    
    hashmap.insert(sum - arr[0]);
    for(int i=1; i<arr.size(); i++){
        if(hashmap.find(arr[i]) != hashmap.end()){
            res.second = arr[i];
            res.first = sum - arr[i];
            return res;
        }
        else
            hashmap.insert(sum - arr[i]);
    }
    res.first = -1;
    res.second = -1;
    return res;
}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    vector<int> test_array;
    int sum;
    pair<int, int> res;

    test_array = {3, 2, 8, 15, -8};
    sum = 17;
    printf("\nInput array: ");
    printArray(test_array);
    res = pairSum(test_array, sum);
    if(res.first == -1 && res.second == -1)
        printf("No pair with sum %d present in the given input array\n", sum);
    else
        printf("Pair with sum %d in the given array: (%d, %d)\n", sum, res.first, res.second);

    test_array = {2, 1, 6, 3};
    sum = 6;
    printf("\nInput array: ");
    printArray(test_array);
    res = pairSum(test_array, sum);
    if(res.first == -1 && res.second == -1)
        printf("No pair with sum %d present in the given input array\n", sum);
    else
        printf("Pair with sum %d in the given array: (%d, %d)\n", sum, res.first, res.second);

    test_array = {5, 8, -3, 6};
    sum = 3;
    printf("\nInput array: ");
    printArray(test_array);
    res = pairSum(test_array, sum);
    if(res.first == -1 && res.second == -1)
        printf("No pair with sum %d present in the given input array\n", sum);
    else
        printf("Pair with sum %d in the given array: (%d, %d)\n", sum, res.first, res.second);

    test_array = {8, 3, 2, 4, 5};
    sum = 6;
    printf("\nInput array: ");
    printArray(test_array);
    res = pairSum(test_array, sum);
    if(res.first == -1 && res.second == -1)
        printf("No pair with sum %d present in the given input array\n", sum);
    else
        printf("Pair with sum %d in the given array: (%d, %d)\n", sum, res.first, res.second);

    return 0;
}