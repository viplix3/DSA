// https://codeforces.com/contest/231/problem/A

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int numProblems, a, b, c, count;
	count = 0;
	cin>>numProblems;
	while(numProblems--){
		cin>>a>>b>>c;
		
		if(a+b+c >= 2)
			count++;
	}
	cout<<count<<endl;
	return 0;
}
