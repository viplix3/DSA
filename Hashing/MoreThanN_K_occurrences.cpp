#include<bits/stdc++.h>
using namespace std;

vector<int> get_nk_occurrence_elements(vector<int> &arr, int k)
{
    vector<int> out_elements;
    unordered_map<int, int> frequency_map;

    for(int i=0; i<arr.size(); i++)
        frequency_map[arr[i]] += 1;

    for(auto itr: frequency_map){
        if(itr.second > arr.size() / k)
            out_elements.push_back(itr.first);
    }
    return out_elements;
}


void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    vector<int> test_array;
    vector<int> elements;
    int k;

    test_array = {30, 10, 20, 20, 10, 20, 30, 30};
    k = 4;
    printf("\nInput Array: ");
    printArray(test_array);
    elements  = get_nk_occurrence_elements(test_array, k);
    printf("Elements occuring more than %ld times: ", test_array.size()/k);
    printArray(elements);

    test_array = {30, 10, 20, 30, 30, 40, 30, 40, 30};
    k = 2;
    printf("\nInput Array: ");
    printArray(test_array);
    elements = get_nk_occurrence_elements(test_array, k);
    printf("Elements occurring more than %ld times: ", test_array.size()/k);
    printArray(elements);

    test_array = {10, 10, 20, 30, 20, 10, 10};
    k = 2;
    printf("\nInput Array: ");
    printArray(test_array);
    elements = get_nk_occurrence_elements(test_array, k);
    printf("Elements occurring more than %ld times: ", test_array.size()/k);
    printArray(elements);

    return 0;
}