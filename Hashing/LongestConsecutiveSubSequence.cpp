#include<bits/stdc++.h>
using namespace std;

int longestConsecutiveSubSequence(vector<int> &arr)
{
    unordered_set<int> hash_map(arr.begin(), arr.end());
    int max_length = 1;

    for(auto ele: hash_map){
        if(hash_map.find(ele - 1) == hash_map.end()){
            // No smaller element than current is present in the hash table, so current element must be
            // the fist element of a possible sub-sequence. We will count the length of sub-sequence with current element
            // as the starting of the sub-sequence
            int curr_length = 1;
            int next_element = ele + 1;
            while(hash_map.find(next_element) != hash_map.end()){
                next_element++;
                curr_length++;
            }
            max_length = max(max_length, curr_length);
        }
    }
    return max_length;
}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    vector<int> test_arr;

    test_arr = {1, 9, 3, 4, 2, 20};
    printf("\nInput array: ");
    printArray(test_arr);
    printf("Longest consevutive sub-sequence length in the given array: %d\n",
        longestConsecutiveSubSequence(test_arr));

    test_arr = {8, 20, 7, 30};
    printf("\nInput array: ");
    printArray(test_arr);
    printf("Longest consevutive sub-sequence length in the given array: %d\n",
        longestConsecutiveSubSequence(test_arr));

    test_arr = {20, 30, 40};
    printf("\nInput array: ");
    printArray(test_arr);
    printf("Longest consevutive sub-sequence length in the given array: %d\n",
        longestConsecutiveSubSequence(test_arr));

    test_arr = {1, 3, 9, 2, 8, 2};
    printf("\nInput array: ");
    printArray(test_arr);
    printf("Longest consevutive sub-sequence length in the given array: %d\n",
        longestConsecutiveSubSequence(test_arr));

    return 0;
}