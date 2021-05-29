#include<bits/stdc++.h>
using namespace std;

void segreratePostNegArray(vector<int> &arr)
{
    int lowIdx = -1, highIdx = arr.size();

    while(true){
        do{
            lowIdx++;
        }while(arr[lowIdx] < 0);

        do{
            highIdx--;
        }while(arr[highIdx] > 0);

        if(lowIdx >= highIdx)
            return;

        swap(arr[lowIdx], arr[highIdx]);
    }
}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    vector<int> test_array;

    test_array = {13, -12, 18, -10};
    printf("\nInput array: ");
    printArray(test_array);
    segreratePostNegArray(test_array);
    printf("Array after segreration: ");
    printArray(test_array);

    return 0;
}