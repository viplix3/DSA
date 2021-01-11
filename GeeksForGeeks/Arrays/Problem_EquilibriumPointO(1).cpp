
#include<bits/stdc++.h>
using namespace std;

int getEquilibriumPointIndex(int arr[], int n) {
    if(n == 1)
        return 1;
        
    int prefixSum, suffixSum, equilibriumPoint;
    prefixSum = suffixSum = 0;
    equilibriumPoint = -1;
    
    for(int i=0; i<n; i++)
        suffixSum += arr[i];
    
    for(int i=0; i<n; i++){
        suffixSum -= arr[i];
        if(prefixSum == suffixSum)
            equilibriumPoint = i+1;
        else
            prefixSum += arr[i];
    }
    return equilibriumPoint;
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int test_array_1[] = {3, 4, 8, -9, 20, 6};
    int test_array_2[] = {4, 2, -2};
    int test_array_3[] = {4, 2, 2};
    int test_array_4[] = {2, -2, 4};
    int equilibriumPointIndex = -1;

    printf("\nContents of array\n");
    printArray(test_array_1, 6);
    equilibriumPointIndex = getEquilibriumPointIndex(test_array_1, 6);
    if(equilibriumPointIndex != -1)
        printf("Equilibrium point exists in the array at position: %d\n", equilibriumPointIndex);
    else
        printf("There is no equilibrium point in the array\n");
    
    printf("\nContents of array\n");
    printArray(test_array_2, 3);
    equilibriumPointIndex = getEquilibriumPointIndex(test_array_2, 3);
    if(equilibriumPointIndex != -1)
        printf("Equilibrium point exists in the array at position: %d\n", equilibriumPointIndex);
    else
        printf("There is no equilibrium point in the array\n");

    printf("\nContents of array\n");
    printArray(test_array_3, 3);
    equilibriumPointIndex = getEquilibriumPointIndex(test_array_3, 3);
    if(equilibriumPointIndex != -1)
        printf("Equilibrium point exists in the array at position: %d\n", equilibriumPointIndex);
    else
        printf("There is no equilibrium point in the array\n");

    printf("\nContents of array\n");
    printArray(test_array_4, 3);
    equilibriumPointIndex = getEquilibriumPointIndex(test_array_4, 3);
    if(equilibriumPointIndex != -1)
        printf("Equilibrium point exists in the array at position: %d\n", equilibriumPointIndex);
    else
        printf("There is no equilibrium point in the array\n");
    return 0;
}