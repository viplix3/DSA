#include<bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &arr)
{
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    vector<int> counter(range), outputArr(arr.size());

    for(int i=0; i<arr.size(); i++)
        counter[arr[i] - min] += 1;

    for(int i=1; i<counter.size(); i++)
        counter[i] = counter[i-1] + counter[i]; // counter[i] holds number of elements <= i
    
    for(int i=arr.size()-1; i>=0; i--){
        // We use arr[i] to get the number of elements <= arr[i]
        // If arr[i] == 1, then counter[arr[i]] would give us number of elements <= 1
        // Now if suppose there are 4 elements <= 1 hence, counter[1] == 4. 
        // This tells us that we should put 1 at index 3 (0 based indexing). 
        // As we have used up 1 once, counter[1] should be reduced.
        // By doing so, our algorithm is stable and can be applied to multiple types of input (i.e. if arr are keys) rather than just int
        outputArr[counter[arr[i] - min] - 1] = arr[i];
        counter[arr[i] - min] -= 1;
    }

    for(int i=0; i<arr.size(); i++)
        arr[i] = outputArr[i];

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

    countingSort(arr);
    printf("Sorted array: ");
    printArray(arr);

    return 0;
}