// https://codeforces.com/contest/546/problem/A

#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int cost, dollars, numBananas;
	cin>>cost>>dollars>>numBananas;
	int totalCost = cost * (0.5 * (numBananas * (numBananas + 1)));
	int moneyBorrowed = totalCost - dollars > 0 ? totalCost - dollars: 0;
	cout<<moneyBorrowed;
	return 0;
}
