#include <bits/stdc++.h>
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

int exactly3Divisors(int N)
{
    if(N <= 3)
        return 0;

    int exactly3DivNumCounter = 0;

    for(int numIter=2; numIter*numIter<=N; numIter++){ //Iterating fro 2 to sqrt(N)
            if(isPrime(numIter))
                // Only the number which have prime square root will have exactly 3 divisors
                // In other words, any prime number whose square <=N will contribute to our count
                if(numIter * numIter <= N)
                    exactly3DivNumCounter++;
    }

    return exactly3DivNumCounter;
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

        //calling function exactly3Divisors()
        cout<<exactly3Divisors(N)<<endl;
    }
	return 0;
}
