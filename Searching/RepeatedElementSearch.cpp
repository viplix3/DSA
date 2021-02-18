#include<bits/stdc++.h>
using namespace std;

int getRepeatingElement(vector<int> &arr)
{
    /* Rules about the elements of the array
        1. array.size() >= 2
        2. Only one of the present elements repeat, but it can repeat any number of times
        3. All the elements from 0 to max(array) will be present in the array at-least once.

        From above given factos we can infer that
        0 <= max(array) <= arr.size() - 2
    */
    int slowPtr = arr[0]+1, fastPtr = arr[0]+1;
    do{
        slowPtr = arr[slowPtr]+1;
        fastPtr = arr[arr[fastPtr]+1]+1;
    } while(slowPtr != fastPtr);

    slowPtr = arr[0]+1;
    while(slowPtr != fastPtr){
        fastPtr = arr[fastPtr]+1;
        slowPtr = arr[slowPtr]+1;
    }

    return slowPtr-1;
}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    vector<int> test_array_1 = {0, 2, 1, 3, 2, 2};
    vector<int> test_array_2 = {1, 2, 3, 0, 3, 4, 5};
    vector<int> test_array_3 = {0, 0};
    vector<int> test_array_4 = {0, 2, 1, 3, 4, 5, 6, 2};

    printf("\nContents of the array: ");
    printArray(test_array_1);
    printf("Repeated element in the given array: %d\n", getRepeatingElement(test_array_1));

    printf("\nContents of the array: ");
    printArray(test_array_2);
    printf("Repeated element in the given array: %d\n", getRepeatingElement(test_array_2));

    printf("\nContents of the array: ");
    printArray(test_array_3);
    printf("Repeated element in the given array: %d\n", getRepeatingElement(test_array_3));

    printf("\nContents of the array: ");
    printArray(test_array_4);
    printf("Repeated element in the given array: %d\n", getRepeatingElement(test_array_4));
    return 0;
}