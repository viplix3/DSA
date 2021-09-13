#include<bits/stdc++.h>
using namespace std;

vector<int> getKClosest(vector<int>& arr, int ele, int k) {
	priority_queue<pair<int, int>> maxHeapK;

	for(int i=0; i<k; i++)
		maxHeapK.push(make_pair(abs(ele - arr[i]), arr[i]));

	for(int i=k; i<arr.size(); i++) {
		int curr_dist = abs(ele - arr[i]);

		if(maxHeapK.top().first < curr_dist)
			continue;
		else {
			maxHeapK.pop();
			maxHeapK.push(make_pair(curr_dist, arr[i]));
		}
	}

	vector<int> kClosest;
	while(maxHeapK.empty() == false) {
		auto dist_ele_pair = maxHeapK.top();
		maxHeapK.pop();
		kClosest.push_back(dist_ele_pair.second);
	}

	return kClosest;
}

std::ostream& operator<<(std::ostream& out_stream, vector<int> arr) {
	for(auto x : arr)
		out_stream << x << " ";
	return out_stream;
}

int main() {
	vector<int> test_arr;
	int x, k;
	vector<int> kClosest;

	test_arr = {10, 15, 7, 3, 4};
	x = 8;
	k = 2;
	cout << "\nInput array: " << test_arr << endl;
	kClosest = getKClosest(test_arr, x, k);
	cout << k << " closest elements to " << x << " are: " << kClosest << endl;

	test_arr = {100, 80, 10, 5, 70};
	x = 2;
	k = 3;
	cout << "\nInput array: " << test_arr << endl;
	kClosest = getKClosest(test_arr, x, k);
	cout << k << " closest elements to " << x << " are: " << kClosest << endl;

	test_arr = {20, 40, 5, 100, 150};
	x = 100;
	k = 3;
	cout << "\nInput array: " << test_arr << endl;
	kClosest = getKClosest(test_arr, x, k);
	cout << k << " closest elements to " << x << " are: " << kClosest << endl;

	test_arr = {30, 40, 32, 33, 36, 37};
	x = 38;
	k = 3;
	cout << "\nInput array: " << test_arr << endl;
	kClosest = getKClosest(test_arr, x, k);
	cout << k << " closest elements to " << x << " are: " << kClosest << endl;

	return 0;
}