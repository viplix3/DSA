#include<bits/stdc++.h>
using namespace std;

void cycleSortDistinct(vector<int> &arr)
{
    for(int cycleStart=0; cycleStart<arr.size()-1; cycleStart++){
        int item = arr[cycleStart];
        int position = cycleStart;

        for(int i=cycleStart+1; i<arr.size(); i++)
            if(arr[i] < item)
                position += 1; // Keeping track array elements < item. Current item will go to this position
        swap(item, arr[position]); // Item is now holding the replaced array value at position

        while(position != cycleStart){
            position = cycleStart;
            for(int i=cycleStart+1; i<arr.size(); i++)
                if(arr[i] < item)
                    position += 1;
            swap(item, arr[position]);
        }
    }
}

void cycleSort(vector<int> &arr)
{
    int numWrites = 0;
    for(int cycleStart=0; cycleStart<arr.size()-1; cycleStart++){
        int item = arr[cycleStart];
        int position = cycleStart;

        for(int i=cycleStart+1; i<arr.size(); i++)
            if(arr[i] < item)
                position += 1; // Keeping track array elements < item. Current item will go to this position

        if(position == cycleStart)
            continue; // Item under consideration is already at its correct position
        
        while(item == arr[position])
            position += 1; // Skipping duplicate elements

        if(position != cycleStart){
            swap(item, arr[position]); // Item is now holding the replaced array value at position
            numWrites += 1;
        }

        while(position != cycleStart){
            position = cycleStart;
            
            for(int i=cycleStart+1; i<arr.size(); i++)
                if(arr[i] < item)
                    position += 1;
            
            while(item == arr[position])
                position += 1;

            if(position != cycleStart){
                numWrites += 1;
                swap(item, arr[position]);
            }
        }
    }
    printf("\nNumber of writes: %d", numWrites);
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

    cycleSort(arr);
    printf("\nSorted array: ");
    printArray(arr);

    return 0;
}