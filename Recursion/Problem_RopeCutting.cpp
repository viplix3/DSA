#include<bits/stdc++.h>
using namespace std;

int cutRope(int ropeLength, int cutSizes[])
{
    if(ropeLength < 0)
        return -1;
    
    if(ropeLength == 0)
        return 0;
    
    int numCuts = max(cutRope(ropeLength - cutSizes[0], cutSizes), 
                    max(cutRope(ropeLength - cutSizes[1], cutSizes), cutRope(ropeLength - cutSizes[2], cutSizes)));

    if(numCuts == -1)
        return -1;

    return numCuts+1;
}

int main(){

    int ropeLength;
    int cutSizes[3];

    while(true){
        printf("Enter rope length followed by 3 cut sized allowed: ");
        scanf("%d %d %d %d", &ropeLength, &cutSizes[0], &cutSizes[1], &cutSizes[2]);
        printf("Maximum number of cuts possible: %d\n", cutRope(ropeLength, cutSizes));
    }

    return 0;
}