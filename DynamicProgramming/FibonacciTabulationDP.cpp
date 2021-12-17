#include<bits/stdc++.h>
using namespace std;

int fib(int n) {
	vector<int> fibonacci(n+1);
	fibonacci[0] = 0, fibonacci[1] = 1;

	for(int i = 2; i <= n; i++)
		fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];

	return fibonacci[n];
}

int main() {
	int num;
	cout << "Enter number for calculating fibonaachi: ";
	cin >> num;

	cout << "\nFibonacchi of " << num << " is: " << fib(num) << endl;
	return 0;
}
