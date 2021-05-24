#include <bits/stdc++.h>
using namespace std;

int minNumber(int arr[], int low, int high)
{
    int minElement = INT_MAX;

    while(low <= high){
        int midIdx = (low + high) / 2;

        if(arr[low] < arr[midIdx]){ // First half of the array is sorted
            minElement = min(minElement, arr[low]);
            low = midIdx+1;
        }
        else{ // Second half of the array is sorted
            if(midIdx != high)
                minElement = min(minElement, arr[midIdx+1]);
            minElement = min(minElement, arr[midIdx]);
            high = midIdx-1;
        }
    }
    return minElement;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int a[n];
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
        
        printf("%d\n", minNumber(a, 0, n-1));
    }
    return 0;
}