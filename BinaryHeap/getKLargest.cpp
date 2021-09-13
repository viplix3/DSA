#include<bits/stdc++.h>
using namespace std;

vector<int> getKLargest(vector<int>& arr, int k) {
	priority_queue<int, vector<int>, greater<int>> minHeapK(arr.begin(), arr.begin() + k);

	for(int i=k; i<arr.size(); i++) {
		if(minHeapK.top() > arr[i])
			continue;
		else {
			minHeapK.pop();
			minHeapK.push(arr[i]);
		}
	}

	vector<int> topK;
	while(minHeapK.empty() == false) {
		topK.push_back(minHeapK.top());
		minHeapK.pop();
	}

	return topK;
}

std::ostream& operator<<(std::ostream& out_stream, vector<int>arr) {
	for(auto x : arr)
		out_stream << x << " ";
	return out_stream;
}

int main() {
	vector<int> test_arr;
	int k;
	vector<int> topK;

	test_arr = {5, 15, 10, 20, 8};
	k = 2;
	cout << "\nInput array: " << test_arr << endl;
	topK = getKLargest(test_arr, k);
	cout << "Top " << k << " largest elements in the array: " << topK << endl;

	test_arr = {8, 6, 7, 4, 10, 9};
	k = 3;
	cout << "\ninput array: " << test_arr << endl;
	topK = getKLargest(test_arr, k);
	cout << "top " << k << " largest elements in the array: " << topK << endl;

	test_arr = {5, 15, 10, 20, 8, 25, 18};
	k = 3;
	cout << "\ninput array: " << test_arr << endl;
	topK = getKLargest(test_arr, k);
	cout << "top " << k << " largest elements in the array: " << topK << endl;

	return 0;
}