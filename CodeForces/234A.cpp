// https://codeforces.com/contest/236/problem/A

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int alphaCount[26];
	memset(alphaCount, 0, sizeof(alphaCount));
	int counter = 0;
	string username;
	
	cin>>username;
	for(int i=0; i<username.size(); i++)
		alphaCount[username[i] - 'a'] = 1;
		
	for(int i=0; i<26; i++)
		counter += alphaCount[i];	
	
	if(counter % 2 == 0)
		cout<<"CHAT WITH HER!"<<endl;
	else
		cout<<"IGNORE HIM!"<<endl;
	
	return 0;
}
