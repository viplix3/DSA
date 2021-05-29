#include<bits/stdc++.h>
using namespace std;


int getMinDivisionDifference(vector<int> &arr, int numDivisions)
{
    int minDiff = INT_MAX;
    sort(arr.begin(), arr.end());
    for(int i=0; (i+numDivisions) < arr.size(); i++)
        minDiff = min(minDiff, (arr[i+numDivisions-1] - arr[i]));
    return minDiff;
}

void printarray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    /*
        Divide the packets of chocolates in numDivisions.
        Rules of division
            - 1 packet per division
            - difference(minChocolate - maxChocolates) after division should be minimum
    */

    vector<int> test_array;
    int numDivisions;
    int minDivisionDifference;

    test_array = {7, 3, 2, 4, 9, 12, 56}; // 2, 3, 4, 7, 9, 12, 56 -> 2
    numDivisions = 3;
    printf("\nNumber of chocolates in each packet: ");
    printArray(test_array);
    minDivisionDifference = getMinDivisionDifference(test_array, numDivisions);
    printf("Minimum difference between minChocolate and maxChocolate after division in %d parts is: %d\n",
        numDivisions, minDivisionDifference);


    test_array = {3, 4, 1, 9, 56, 7, 9, 12}; // 1, 3, 4, 7, 9, 9, 12, 56 -> 6
    numDivisions = 5;
    printf("\nNumber of chocolates in each packet: ");
    printArray(test_array);
    minDivisionDifference = getMinDivisionDifference(test_array, numDivisions);
    printf("Minimum difference between minChocolate and maxChocolate after division in %d parts is: %d\n",
        numDivisions, minDivisionDifference);

    return 0;
}