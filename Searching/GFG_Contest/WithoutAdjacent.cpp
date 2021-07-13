#include <bits/stdc++.h>
using namespace std;

// Get the maximum subsequence sum of the array such that the subsequence contains no consecutive elements

long long getMaxNonAdjacentSubSequenceSum(vector<int>& arr)
{
	long long sum_including_prev = arr[0], sum_excluding_prev = 0;
	long long sum_including_curr, sum_excluding_curr;

	for(int i=1; i<arr.size(); i++) {
		sum_excluding_curr = max(sum_including_prev, sum_excluding_prev);
		sum_including_curr = sum_excluding_prev + arr[i];

		sum_including_prev = sum_including_curr;
		sum_excluding_prev = sum_excluding_curr;
	}
	return max(sum_including_curr, sum_excluding_curr);
}

int main() {
	vector<int> arr;
	int num_test_cases;

	cin >> num_test_cases;
	while(num_test_cases) {
		int n;
		cin >> n;

		for(int i=0; i<n; i++) {
			int temp;
			cin >> temp;
			arr.emplace_back(temp);
		}
		
		if(n == 1)
			cout << arr[0] << endl;
		else {
			long long max_non_adjacent_suarray_sum = getMaxNonAdjacentSubSequenceSum(arr);
			cout << max_non_adjacent_suarray_sum << endl;
		}

		arr.clear();
		num_test_cases--;
	}
	
	return 0;
}