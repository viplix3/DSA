#include<bits/stdc++.h>
using namespace std;

void cycleSort(vector<int> &arr)
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
    cycleSort(arr);
    printArray(arr);

    return 0;
}