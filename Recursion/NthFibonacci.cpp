#include<bits/stdc++.h>
using namespace std;

int getNthFibonacciNumber(int N)
{
    if(N==0)
        return 0;
    if(N==1 || N==2)
        return 1;
    return getNthFibonacciNumber(N-1) + getNthFibonacciNumber(N-2); 
}


int main(){
    int N;

    while(true){
        printf("Enter number for getting fibonacci term, enter -1 to exit: ");
        scanf("%d", &N);
        if(N == -1)
            break;
        printf("%d-th fibonacci term is %d\n\n", N, getNthFibonacciNumber(N));
    }

    return 0;
}