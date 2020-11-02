// https://codeforces.com/contest/230/problem/B

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
bool isPrime(ll num)
{
	if(num <=1)
		return false;
	
	if((num == 2) || (num == 3))
		return true;
	
	if((num % 2 == 0) || (num % 3 == 0))
		return false;
	
	ll i;
	for(i=5; i*i <= num; i+=6){
		if(num % i == 0)
			return false;
		if(num % (i+2) == 0)
			return false;
	}
	
	if(i>3)
		return true;
}
 
string isTPrime(ll num)
{
	if(num <= 3)
		return "NO";
	
	double sqrtNum = sqrt(num);
	if(sqrtNum - floor(sqrtNum) != 0)
		return "NO";
	
	if(isPrime(sqrtNum))
		return "YES";
	
	return "NO";
}
 
int main(){
	int numElements;
	cin>>numElements;
	ll arr[numElements];
	
	for(int i=0; i<numElements; i++)
		cin>>arr[i];
	
	for(int i=0; i<numElements; i++)
		cout<<isTPrime(arr[i])<<endl;
	
	return 0;
}
