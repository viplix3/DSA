#include<bits/stdc++.h>
using namespace std;

vector<int> findDistinctWindowElements(vector<int> &arr, int window_size)
{
    vector<int> distinct_elements;
    unordered_set<int> window_elements(arr.begin(), arr.begin() + window_size);
    distinct_elements.push_back(window_elements.size());

    for(int windowInit=1; windowInit<=arr.size() - window_size; windowInit++){
        window_elements.clear();
        for(int i=windowInit; i<windowInit+window_size; i++)
            window_elements.insert(arr[i]);
        distinct_elements.push_back(window_elements.size());
    }
    return distinct_elements;
}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    vector<int> test_array;
    vector<int> distinct_window_elements;
    int windowSize;

    test_array = {10, 20, 20, 10, 30, 40, 10};
    windowSize = 4;
    printf("\nInput Array: ");
    printArray(test_array);
    distinct_window_elements = findDistinctWindowElements(test_array, windowSize);
    printf("Distinct elements in each window of size %d in the provided array: ", windowSize);
    printArray(distinct_window_elements);

    test_array = {10, 10, 10, 10};
    windowSize = 3;
    printf("\nInput Array: ");
    printArray(test_array);
    distinct_window_elements = findDistinctWindowElements(test_array, windowSize);
    printf("Distinct elements in each window of size %d in the provided array: ", windowSize);
    printArray(distinct_window_elements);

    test_array = {10, 20, 430, 40};
    windowSize = 3;
    printf("\nInput Array: ");
    printArray(test_array);
    distinct_window_elements = findDistinctWindowElements(test_array, windowSize);
    printf("Distinct elements in each window of size %d in the provided array: ", windowSize);
    printArray(distinct_window_elements);

    return 0;
}