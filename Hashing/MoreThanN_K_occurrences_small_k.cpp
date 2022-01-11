#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> modified_moore_voting(vector<int> &arr, int k)
{
    unordered_map<int, int> frequency_map;

    for(int i=0; i<arr.size(); i++){
        // If element is already present in the map, increase its voting count
        if(frequency_map.find(arr[i]) != frequency_map.end())
            frequency_map[arr[i]] += 1;

        // If map has space to accomodate more elements, add the current element in the map
        else if(frequency_map.size() < k-1)
            frequency_map[arr[i]] += 1;

        else // Neither map has the current element, nor there is any space left in the map
            for(auto itr: frequency_map){
                itr.second -=1; // Current element would reduce count of all the elements in the map
                if(itr.second == 0) // If count of any element is reduced to 0, it is removed
                    frequency_map.erase(itr.first);
            }
    }
    return frequency_map;
}

vector<int> get_nk_occurrence_elements(vector<int> &arr, int k)
{
    /*
        If count is the number of elements in the results then
            count <= (K - 1)
    */
    unordered_map<int, int> frequency_map = modified_moore_voting(arr, k);
    vector<int> out_elements;

    // Select/ Reject the condidates on the basis of actual occurrence conts
    for(auto itr: frequency_map){
        itr.second = 0;
        for(int i=0; i<arr.size(); i++)
            if(arr[i] == itr.first)
                itr.second += 1;
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