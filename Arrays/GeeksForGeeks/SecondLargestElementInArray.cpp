#include<bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE 6

int getSecondLargestElement(int array[], int numElements)
{
    int largestElement = array[0];
    int secondLargestElement = -1;
    for(int i=1; i<numElements; i++){
        if(array[i] != largestElement){
            if(array[i] > largestElement){
                secondLargestElement = largestElement;
                largestElement = array[i];
            }

            else if(secondLargestElement==-1 || array[i] > secondLargestElement)
                secondLargestElement = array[i];
        }
    }
    
    return secondLargestElement;
}

int main(){
    int testArray_1[] = {0, 1, 2, 3, 4, 5};
    int testArray_2[] = {5, 4, 3, 2, 1, 0};
    int testArray_3[] = {4, 2, 5, 1, 3, 0};
    int testArray_4[] = {5, 20, 12, 20, 8, 8};
    int testArray_5[] = {5, 5, 5, 5, 5, 5};

    printf("Expected value: 4\t Computed value: %d\n", getSecondLargestElement(testArray_1, ARRAY_SIZE));
    printf("Expected value: 4\t Computed value: %d\n", getSecondLargestElement(testArray_2, ARRAY_SIZE));
    printf("Expected value: 4\t Computed value: %d\n", getSecondLargestElement(testArray_3, ARRAY_SIZE));
    printf("Expected value: 12\t Computed value: %d\n", getSecondLargestElement(testArray_4, ARRAY_SIZE));
    printf("Expected value: -1\t Computed value: %d\n", getSecondLargestElement(testArray_5, ARRAY_SIZE));
    


    return 0;
}