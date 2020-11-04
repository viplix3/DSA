// https://codeforces.com/problemset/problem/1363/A

#include<bits/stdc++.h>
using namespace std;

int main(){
#ifdef __DEBUG__
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin>>t;
	while(t--){
		int n, x;
		cin>>n>>x;
		int placeHolder, oddCount, evenCount;
		oddCount = evenCount = 0;
		for(int i=0; i<n; i++){
			cin>>placeHolder;
			if(placeHolder % 2 == 0)
				evenCount++;
			else
				oddCount++;
		}

/*
#ifdef __DEBUG__
cout<<"Odd count: "<<oddCount<<"\tEven count: "<<evenCount<<endl;
#endif
*/

		if(oddCount == 0){
			cout<<"No"<<endl;
			continue;
		}
		if((x == n) && (oddCount % 2 == 0)){
			cout<<"No"<<endl;
			continue;
		}

		bool possibilityFlag = false;
		for(int i=1; i<=oddCount && i<=x; i+=2){
			if((x - i) == 0){
				possibilityFlag = true;
				break;
			}
			if((x-i) <= evenCount){
				possibilityFlag = true;
				break;
			}
		}

		if(possibilityFlag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;

	}	
	return 0;
}
