// 
#include<bits/stdc++.h>
using namespace std;

void solveTowersOfHanoi(int numDiscsToMove, char sourceTower, char auxTower, char destinationTower)
{
    if(numDiscsToMove == 1)
    {
        printf("Move disc 1 from tower %c to tower %c\n", sourceTower, destinationTower);
        return;
    }

    solveTowersOfHanoi(numDiscsToMove-1, sourceTower, destinationTower, auxTower);
    printf("Move disc %d from tower %c to tower %c\n", numDiscsToMove, sourceTower, destinationTower);
    solveTowersOfHanoi(numDiscsToMove-1, auxTower, sourceTower, destinationTower);
}

int main(){
    int numDiscs;
    printf("Naming convention, Source tower name: 'A', Aux. tower name 'B', Destination tower name 'C'");

    while(true){
        printf("\nEnter number of discs to solve 'Towers of Hanoi' problem, enter -1 to exit: ");
        scanf("%d", &numDiscs);
        if(numDiscs == -1)
            break;
        solveTowersOfHanoi(numDiscs, 'A', 'B', 'C');
    }

    return 0;
}