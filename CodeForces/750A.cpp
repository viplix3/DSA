// https://codeforces.com/contest/750/problem/A
#include<bits/stdc++.h>
using namespace std;
#define MAX_TIME 240

int main(){
	int n, k;
	cin>>n>>k;

	int availableTime = floor((MAX_TIME - (k*1.0)) / 5);
	int possibleQues = floor((-1 + sqrt(1 + 8.0*availableTime)) / 2);
	possibleQues = min(possibleQues, n);
	
	cout<<possibleQues<<endl;	
	return 0;
}
