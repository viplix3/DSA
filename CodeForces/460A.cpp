// https://codeforces.com/problemset/problem/460/A
 
#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int n, m;
	cin>>n>>m;
	int numDays = n + floor((n-1) / (1.0 * m-1));
	cout<<numDays<<endl;
	return 0;
}
