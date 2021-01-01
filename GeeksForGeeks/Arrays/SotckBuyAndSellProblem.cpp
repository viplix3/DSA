#include<bits/stdc++.h>
using namespace std;

int getMaxProfit(int stockPrice[], int size)
{
    /* The basic logic is we already know the stock prices. So, we will buy stock when stock price in current time-stamp 
    is greater than the stock price in the last time-stamp. */
    int maxProfit = 0;

    for(int i=1; i<size; i++){
        if(stockPrice[i] > stockPrice[i-1])
            maxProfit += (stockPrice[i] - stockPrice[i-1]);    
    }
    return maxProfit;
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int test_array_1[] = {1, 5, 3, 8, 12};
    int test_array_2[] = {30, 20, 10};
    int test_array_3[] = {1, 5, 3, 1, 2, 8};

    printf("\nContents of array\n");
    printArray(test_array_1, 5);
    printf("Maximum profit we can get from the given stock prices is: %d\n", getMaxProfit(test_array_1, 5));

    printf("\nContents of array\n");
    printArray(test_array_2, 3);
    printf("Maximum profit we can get from the given stock prices is: %d\n", getMaxProfit(test_array_2, 3));

    printf("\nContents of array\n");
    printArray(test_array_3, 6);
    printf("Maximum profit we can get from the given stock prices is: %d\n", getMaxProfit(test_array_3, 6));

    return 0;
}