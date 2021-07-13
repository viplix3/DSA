#include <bits/stdc++.h>
using namespace std;

// Flip the middle bit of a number. If the number is having even bits, flip mid and mid-1 bits

int toggle_middle(int num)
{
	int num_bits = (int)log2(num) + 1;

	if(num_bits % 2 == 0) {
		int bit_flip_1 = num_bits / 2;
		int bit_flip_2 = (num_bits / 2) - 1;
		int flip_mask = (1 << bit_flip_1) | (1 << bit_flip_2);
		num = num ^ flip_mask;
		return num;
	}
	else {
		int bit_flip = num_bits / 2;
		num = num ^ (1 << bit_flip);
		return num;
	}
}


int main() {
	int num_test_cases;
	cin >> num_test_cases;

	while(num_test_cases) {
		int num;

		cin>>num;
		num = toggle_middle(num);
		cout << num << endl;

		num_test_cases--;
	}

	return 0;
}