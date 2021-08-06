#include<bits/stdc++.h>
using namespace std;

void generateAndPrint(string digit1, string digit2, int nums)
{
	queue<string> Q;

	Q.push(digit1);
	Q.push(digit2);

	for(int i=0; i<nums; i++) {
		string currNum = Q.front();
		cout << currNum << " ";
		Q.pop();
		Q.push(currNum + digit1);
		Q.push(currNum + digit2);
	}
	cout << endl;
}

int main() {
	string digit1 = "5", digit2 = "6";
	int num = 10;
	generateAndPrint(digit1, digit2, num);

	return 0;
}