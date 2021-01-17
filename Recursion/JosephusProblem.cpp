#include<bits/stdc++.h>
using namespace std;

int solveJosephusProblem(int numRemainingPersons, int killIdx)
{
    if(numRemainingPersons==1)
        return 0;
    return (solveJosephusProblem(numRemainingPersons-1, killIdx) + killIdx) % numRemainingPersons;
}

int main(){

    int numPersons, numKillingIdx;
    while(true){
        printf("Enter number of persons in the game and the killing index: ");
        scanf("%d %d", &numPersons, &numKillingIdx);
        printf("\nIndex of remaining person after the game is finished: %d\n", solveJosephusProblem(numPersons, numKillingIdx));
    }

    return 0;
}