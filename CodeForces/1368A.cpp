// https://codeforces.com/problemset/problem/1368/A

#include<bits/stdc++.h>
using namespace std;

int getNumSteps(int a, int b, int n)
{
	int numSteps = 0;
	int c;
	
	if(a>b){
		c = a;
		a = b;
		b = c;
	}

	while((a<=n) && (b<=n)){
		c = a + b;
		a = b;
		b = c;
		numSteps++;
	}
	return numSteps;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int a, b, n;
		cin>>a>>b>>n;
		
		if(a+b > n)
			cout<<"1"<<endl;
		else{
			int numSteps = getNumSteps(a, b, n);
			cout<<numSteps<<endl;
		}
	}
	return 0;
}
