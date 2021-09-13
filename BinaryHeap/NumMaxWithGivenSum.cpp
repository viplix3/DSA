#include<bits/stdc++.h>
using namespace std;

int getMaxItems(vector<int>& arr, int sum) {
	priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());

	int count = 0;
	while(minHeap.empty() == false && minHeap.top() <= sum) {
		sum -= minHeap.top();
		minHeap.pop();
		count += 1;
	}

	return count;
}

std::ostream& operator<<(std::ostream& out_stream, vector<int> arr) {
	for(auto x : arr)
		out_stream << x << " ";
	return out_stream;
}

int main() {
	vector<int> test_arr;
	int cost;
	int num_items;

	test_arr = {1, 12, 5, 111, 200};
	cost = 10;
	cout << "Input array: " << test_arr << endl;
	num_items = getMaxItems(test_arr, cost);
	cout << "Maximum items we can buy with " << cost << " units of money: " << num_items << endl;

	test_arr = {20, 10, 5, 30, 100};
	cost = 35;
	cout << "\nInput array: " << test_arr << endl;
	num_items = getMaxItems(test_arr, cost);
	cout << "Maximum items we can buy with " << cost << " units of money: " << num_items << endl;
	

	return 0;
}