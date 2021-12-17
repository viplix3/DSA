#include<bits/stdc++.h>
using namespace std;

int fibonacciDP(int num, vector<int>& memoArr) {
	if(memoArr[num] == -1) {
		int currFib;

		if(num == 0 || num == 1)
			currFib = num;
		else
			currFib = fibonacciDP(num-1, memoArr) + fibonacciDP(num-2, memoArr);
		
		memoArr[num] = currFib;
	}

	return memoArr[num];
}

int fib(int n) {
	vector<int> memo(n+1, -1);
	return fibonacciDP(n, memo);
}

int main() {
	int num;
	cout << "Enter number for calculating fibonaachi: ";
	cin >> num;

	cout << "\nFibonacchi of " << num << " is: " << fib(num) << endl;
	return 0;
}