#include<bits/stdc++.h>
using namespace std;

int hoarePartition(vector<int> &arr, int pivotIdx, int lowIdx, int highIdx)
{
    /*
        Idead of Hoare's partition algorithm
         - Initialize pivot at 0 index
         - Divide array in three parts, i.e. left, mid and right
         - At each iteration, make sure that 
            - All the elements in left part < pivot
            - All the elements in right part > pivot
            - All the elements in the mid part: yet to be categorized
    */
   int pivot = arr[pivotIdx];
   swap(arr[pivotIdx], arr[lowIdx]); // Move pivot to smallest index
   int leftIdx = lowIdx - 1, rightIdx = highIdx + 1; // Initially both the partitions are empty

   while(true){
       do{ // finding left-most index for which left part < pivot
           leftIdx += 1;
       }while(arr[leftIdx] < pivot);

       do{ // finding right-most index for which right part > pivot
           rightIdx -= 1;
       }while(arr[rightIdx] > pivot);

       if(leftIdx >= rightIdx) // No mid part to categorize, everything is done
            return rightIdx;

       swap(arr[leftIdx], arr[rightIdx]);
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
    int pivotIdx;

    test_array = {10, 80, 30, 90, 40, 50, 70};
    pivotIdx = 4;
    printf("\nInput array is: ");
    printArray(test_array);
    printf("Index at which all the elements on left are less than pivot %d and all the elements at right are greater (in sorted array): %d\n", \
        test_array[pivotIdx], hoarePartition(test_array, pivotIdx, 0, test_array.size()-1));

    test_array = {70, 60, 80, 40, 30};
    pivotIdx = 4;
    printf("\nInput array is: ");
    printArray(test_array);
    printf("Index at which all the elements on left are less than pivot %d and all the elements at right are greater (in sorted array): %d\n", \
        test_array[pivotIdx], hoarePartition(test_array, pivotIdx, 0, test_array.size()-1));

    test_array = {30, 40, 20, 50, 80};
    pivotIdx = 4;
    printf("\nInput array is: ");
    printArray(test_array);
    printf("Index at which all the elements on left are less than pivot %d and all the elements at right are greater (in sorted array): %d\n", \
        test_array[pivotIdx], hoarePartition(test_array, pivotIdx, 0, test_array.size()-1));

    return 0;
}