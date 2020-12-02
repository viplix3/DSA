// https://www.geeksforgeeks.org/count-digits-factorial-set-1/?ref=lbp

#include<bits/stdc++.h>
using namespace std;

int digitsInFactorial(int N)
{
    if(N < 0) // Edge case handling
        return 0;

    if(N <= 1) // Factorial of 0 and 1 is 1
        return 1;

    double digitsInFact = 0;

    for(int i=2; i<=N; i++) //As suggested in Hint-2
        digitsInFact += log10(i);

    return floor(digitsInFact) + 1;
}

int main()
{
    int T;

    //taking testcases
    cin>>T;
    while(T--)
    {
        int N;

        //taking N
        cin>>N;

        //calling method digitsInFactorial()
        cout<<digitsInFactorial(N)<<endl;
    }
    return 0;
}
