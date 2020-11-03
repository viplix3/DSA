// https://codeforces.com/problemset/problem/1343/A

#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int k=2; k<=30; k++){
			int val = pow(2, k) - 1;
			if(n % val == 0){
				cout<<n/val<<endl;
				break;
			}
		}	
	}
	return 0;
}
