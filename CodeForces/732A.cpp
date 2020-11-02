// https://codeforces.com/problemset/problem/732/A

#include<bits/stdc++.h>
using namespace std;

int main(){
	int k, r, i;
	cin>>k>>r;

	for(i=1; i<10; i++){
		if((k*i)%10 == 0)
			break;
		if((k*i)%10 == r)
			break;	
	}

	cout<<i<<endl;

	return 0;
}
