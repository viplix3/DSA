#include<bits/stdc++.h>
using namespace std;

int sqrtFloor(int num)
{
    if(num <= 0){
        printf("Invalid input for square root calculation\n");
        return -1;
    }
    if(num <= 3)
        return 1;

    int searchRangeInit = 2, searchRangeEnd = num/2, sqrtFloor_val=2;
    while(searchRangeInit <= searchRangeEnd){
        int sqrtCandidate = (searchRangeInit + searchRangeEnd) / 2;
        int sqrtCandidate_sq = sqrtCandidate*sqrtCandidate;

        if(sqrtCandidate_sq == num)
            return sqrtCandidate;

        if(sqrtCandidate_sq > num){
            searchRangeEnd = sqrtCandidate-1;
        }
        else{
            searchRangeInit = sqrtCandidate+1;
            sqrtFloor_val = sqrtCandidate;
        }
    }
    return sqrtFloor_val;
}

int main(){
    int numTestCases;
    printf("\nEnter number of test cases: ");
    scanf("%d", &numTestCases);

    while(numTestCases--){
        int num;
        printf("\nEnter number: ");
        scanf("%d", &num);
        int num_sqrtFloor = sqrtFloor(num);
        if(num_sqrtFloor != -1)
            printf("\nFloor of square root of number %d is: %d\n", num, sqrtFloor(num));
    }
}