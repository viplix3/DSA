#include<bits/stdc++.h>
using namespace std;

void getSieve(int N, bool sieve[])
{
    sieve[0] = sieve[1] = false; //We know tht 0 and 1 are not prime
    for(int i=2; i*i<=N; i++){
        if(sieve[i]){
            int j = i*i;
            while(j <= N){
                sieve[j] = false;
                j += i;
            }
        }
    }
}


vector<int> getPrimesUpto(int N)
{
    bool primeSieve[N+1];
    vector<int> primes;

    memset(primeSieve, true, sizeof(primeSieve)); //Initializing the seive with all true
    getSieve(N, primeSieve);

    for(int i=2; i<=N; i++)
        if(primeSieve[i])
            primes.push_back(i);

    return primes;
}

void printArray(vector<int> arr)
{
    for(auto ele: arr)
        printf("%d ", ele);
    printf("\n");
}

int main(){
    vector<int> primeNumbers;
    
    primeNumbers = getPrimesUpto(7);
    printArray(primeNumbers);

    return 0;
}