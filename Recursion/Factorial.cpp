#include<bits/stdc++.h>
using namespace std;

int getFactorial(int N)
{
    if(N==0)
        return 1;
    return N * getFactorial(N-1);
}

int main(){
    int N;

    while(true){
        printf("Enter number for generating factorial, enter -1 to exit: ");
        scanf("%d", &N);
        if(N == -1)
            break;
        printf("Factorial of %d is %d\n\n", N, getFactorial(N));
    }

    return 0;
}