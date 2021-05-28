#include<bits/stdc++.h>
using namespace std;

int hoarePartition(vector<int> &arr, int lowIdx, int highIdx)
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
   int pivot = arr[lowIdx];
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

void quickSort(vector<int> &arr, int lowIdx, int highIdx)
{
    if(lowIdx < highIdx){
        int partitionIdx = hoarePartition(arr, lowIdx, highIdx);
        quickSort(arr, lowIdx, partitionIdx);
        quickSort(arr, partitionIdx+1, highIdx);
    }

}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int numElements;
    vector<int> arr;

    printf("Enter number of elements in the array: ");
    scanf("%d", &numElements);
    
    printf("\nEnter the array: ");
    for(int i=0; i<numElements; i++){
        int temp;
        scanf("%d", &temp);
        arr.push_back(temp);
    }
    
    printf("\nInput array: ");
    printArray(arr);

    printf("\nSorted array: ");
    quickSort(arr, 0, arr.size()-1);
    printArray(arr);

    return 0;
}