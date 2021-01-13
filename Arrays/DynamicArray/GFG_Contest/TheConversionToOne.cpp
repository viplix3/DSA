#include<bits/stdc++.h>
using namespace std;

bool isOdd(int num){
    return ((num %2) != 0);
}

bool isEven(int num){
    return ((num%2) == 0);
}


int getMinStepsForConversionToOne(int num)
{
    int numSteps = 0;

    while(num != 1){
        if(isEven(num)){
            num /= 2;
            numSteps += 1;
        }
        else 
            if(isOdd(num)){
                if(isOdd((num-1)/2) && ((num-1)/2 != 1)){
                    num += 1;
                }
                else
                    num -= 1;
                numSteps += 1;
            }
    }
    return numSteps;
}

int main(){
    int numTestCases;
    scanf("%d", &numTestCases);

    while(numTestCases--){
        int num;
        scanf("%d", &num);
        printf("%d\n", getMinStepsForConversionToOne(num));
    }
    return 0;
}