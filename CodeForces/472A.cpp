// https://codeforces.com/contest/472/problem/A

#include<bits/stdc++.h>
using namespace std;
#define NUM_BOUNDS 1000000
bool compositeSieve[NUM_BOUNDS+1];
 
void setCompositeSieve()
{
	for(int i=2; i*i<=NUM_BOUNDS; i++){
		if(compositeSieve[i] == 1){
			for(int j=i*i; j<=NUM_BOUNDS; j+=i)
				compositeSieve[j] = false;
		}
	}
}
 
void getCompositeFactors(int &lower, int &upper)
{
	// cout<<lower<<": "<<compositeSieve[lower]<<" "<<upper<<": "<<compositeSieve[upper]<<endl;
	while((compositeSieve[lower]) || (compositeSieve[upper])){
		lower--;
		upper++;
		// cout<<lower<<": "<<compositeSieve[lower]<<" "<<upper<<": "<<compositeSieve[upper]<<endl;
	}
}
 
int main(){
	memset(compositeSieve, 1, sizeof(compositeSieve));
	setCompositeSieve();
	
	int num;
	cin>>num;
	
	int lower, upper;
	lower = floor(num / 2.0);
	upper = ceil(num / 2.0);
	
	getCompositeFactors(lower, upper);
	cout<<lower<<" "<<upper<<endl;
	
	return 0;
}

