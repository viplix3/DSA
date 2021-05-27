
#include<bits/stdc++.h>
using namespace std;

void printUnion(vector<int> arr_1, vector<int> arr_2)
{
    int iter_1 = 0, iter_2 = 0;
    
    while(iter_1 != arr_1.size() && iter_2 != arr_2.size()){
        if(iter_1 > 0 && arr_1[iter_1] == arr_1[iter_1 - 1]){
            iter_1 += 1;
            continue;
        }
        if(iter_2 > 0 && arr_2[iter_2] == arr_2[iter_2 - 1]){
            iter_2 += 1;
            continue;
        }
        if(arr_1[iter_1] == arr_2[iter_2]){
            printf("%d\t", arr_1[iter_1]);
            iter_1 += 1;
            iter_2 += 1;
        }
        else if(arr_1[iter_1] < arr_2[iter_2]){
            printf("%d\t", arr_1[iter_1]);
            iter_1 += 1;
        }
        else if(arr_2[iter_2] < arr_1[iter_1]){
            printf("%d\t", arr_2[iter_2]);
            iter_2 += 1;
        }
    }
    while(iter_1 != arr_1.size()){
        if(iter_1 > 0 && arr_1[iter_1] == arr_1[iter_1 - 1]){
            iter_1 += 1;
            continue;
        }
        printf("%d\t", arr_1[iter_1]);
        iter_1 += 1;
    }
    while(iter_2 != arr_2.size()){
        if(iter_2 > 0 && arr_2[iter_2] == arr_2[iter_2 - 1]){
            iter_2 += 1;
            continue;
        }
        printf("%d\t", arr_2[iter_2]);
        iter_2 += 1;
    }
    printf("\n");
}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    vector<int> test_array_1 = {3, 5, 5, 10, 10, 10, 15, 15, 20};
    vector<int> test_array_2 = {5, 10, 10, 15, 30};

    printf("\nTest array 1\n");
    printArray(test_array_1);
    printf("\nTest array 2\n");
    printArray(test_array_2);

    printf("\nElements in union: ");
    printUnion(test_array_1, test_array_2);


    test_array_1 = {1, 1, 3, 3, 3};
    test_array_2 = {1, 1, 1, 1, 3, 5, 7};

    printf("\nTest array 1\n");
    printArray(test_array_1);
    printf("\nTest array 2\n");
    printArray(test_array_2);

    printf("\nElements in union: ");
    printUnion(test_array_1, test_array_2);


    test_array_1 = {1, 20, 20, 40, 60};
    test_array_2 = {2, 20, 20, 20};

    printf("\nTest array 1\n");
    printArray(test_array_1);
    printf("\nTest array 2\n");
    printArray(test_array_2);

    printf("\nElements in union: ");
    printUnion(test_array_1, test_array_2);


    test_array_1 = {2, 20, 20, 40, 60};
    test_array_2 = {10, 20, 20, 20};

    printf("\nTest array 1\n");
    printArray(test_array_1);
    printf("\nTest array 2\n");
    printArray(test_array_2);

    printf("\nElements in union: ");
    printUnion(test_array_1, test_array_2);


    test_array_1 = {1, 2, 3, 4};
    test_array_2 = {5, 6, 7, 8};

    printf("\nTest array 1\n");
    printArray(test_array_1);
    printf("\nTest array 2\n");
    printArray(test_array_2);

    printf("\nElements in union: ");
    printUnion(test_array_1, test_array_2);

    return 0;
}