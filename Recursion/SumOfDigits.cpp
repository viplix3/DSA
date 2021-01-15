#include<bits/stdc++.h>
using namespace std;

int sumOfDigits(int num)
{
    if(num == 0)
        return 0;
    return (num%10) + sumOfDigits(num/10);
}

int main(){

    int num;

    while(true){
        printf("Enter number to get sum of digits or enter -1 to exit: ");
        scanf("%d", &num);
        if(num == -1)
            break;
        printf("Sum of digits of number %d is %d\n", num, sumOfDigits(num));
    }

    return 0;
}