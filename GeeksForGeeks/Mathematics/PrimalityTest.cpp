#include<bits/stdc++.h>
using namespace std;

bool isPrime(int N)
{
    if(N == 1) // 1 is neither prime, nor composite
        return false;

    if(N == 2) // 2 is the only even prime, so handling this case separately
       return true;

    if(N == 3) // 3 is a prime, handling this case separately for code optimization
        return true;

    if((N % 2 == 0) || (N % 3 == 0))
        return false;

    int i;
    for(i=5; i*i <= N; i += 6){
        if((N % i) == 0)
            return false;

        if((N % (i+2)) == 0)
            return false;
    }

    if(i > 3)
        return true;

}


// { Driver Code Starts.

int main()
{
    int T; //testcases
    cin>>T; //input testcases
    while(T--) //while testcase have not been exhausted
    {
        int N;
        cin>>N; //input n

        if(isPrime(N))
        cout<<"Yes";
        else
            cout<<"No";

        cout << endl;
    }
    return 0;
}
