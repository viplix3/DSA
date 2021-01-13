#include<bits/stdc++.h>
using namespace std;

long long getNearestNum(long long num, long long candidate_1, long long candidate_2)
{
    long long dist_1 = abs(num - candidate_1);
    long long dist_2 = abs(num - candidate_2);

    if(dist_1 == dist_2)
        return candidate_1 > candidate_2? candidate_1: candidate_2;
    return dist_1 < dist_2? candidate_1: candidate_2;
}

long long getNearestPerfectSquare(long long num)
{
    double root = sqrt(num);
    long long root_floor = (long long)floor(root);
    long long root_ceil = (long long)ceil(root);

    if(root_floor == root_ceil){
        root_floor -= 1;
        root_ceil += 1;
    }
    
    long long root_foor_square = (long long)pow(root_floor, 2);
    long long root_ceil_square = (long long)pow(root_ceil, 2);

    long long nearestPerfectSquare = getNearestNum(num, root_foor_square, root_ceil_square);
    return nearestPerfectSquare;
}

int main(){
    int numTestCases;
    scanf("%d", &numTestCases);

    while(numTestCases--){
        long long num;
        scanf("%lld", &num);
        printf("%lld\n", getNearestPerfectSquare(num));
    }
    return 0;
}