#include<bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE 6

int getArrayMaximum(int array[], int numElements)
{
    int maximumElement = array[0];
    for(int i=1; i<numElements; i++)
        if(array[i] > maximumElement)
            maximumElement = array[i];
    
    return maximumElement;
}

int main(){
    int testArray_1[] = {0, 1, 2, 3, 4, 5};
    int testArray_2[] = {5, 4, 3, 2, 1, 0};
    int testArray_3[] = {4, 2, 5, 1, 3, 0};

    printf("Expected largest value: %d\t Computed largest value: 5\n", getArrayMaximum(testArray_1, ARRAY_SIZE));
    printf("Expected largest value: %d\t Computed largest value: 5\n", getArrayMaximum(testArray_2, ARRAY_SIZE));
    printf("Expected largest value: %d\t Computed largest value: 5\n", getArrayMaximum(testArray_3, ARRAY_SIZE));
    


    return 0;
}