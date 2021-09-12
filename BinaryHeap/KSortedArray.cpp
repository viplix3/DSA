#include<bits/stdc++.h>
using namespace std;

void sortKSorted(vector<int>& arr, int k) {
	priority_queue<int, vector<int>, greater<int>> minHeapK;

	// Make a minHeap of size k
	// As each elment is +- k places from its sorted index
	// all the elements of that window will be on the heap of size k
	// We just need to take the min of the heap to get the actual sorted index
	// of the element
	for(int i=0; i<=k; i++)
		minHeapK.push(arr[i]);
	
	// Get the sorted element index, update array and add new element in the heap
	int sortedIdx = 0;
	for(int i=k+1; i<arr.size(); i++) {
		arr[sortedIdx] = minHeapK.top();
		minHeapK.pop();

		sortedIdx += 1;
		minHeapK.push(arr[i]);
	}

	// Add remaining elements of the minHeap in the sorted array
	while(minHeapK.empty() == false) {
		arr[sortedIdx] = minHeapK.top();
		minHeapK.pop();
		sortedIdx += 1;
	}
}

std::ostream& operator<<(std::ostream& out_stream, vector<int>& arr) {
	for(auto x : arr)
		out_stream << x << " ";
	return out_stream;
}

int main() {
	vector<int> test_arr;
	int k;

	test_arr = {9, 8, 7, 18, 19, 17};
	k = 2;
	cout << "Input k-sorted array: " << test_arr << endl;
	sortKSorted(test_arr, k);
	cout << "After sorting: " << test_arr << endl;

	test_arr = {10, 9, 7, 8, 4, 70, 50, 60};
	k = 4;
	cout << "\nInput k-sorted array: " << test_arr << endl;
	sortKSorted(test_arr, k);
	cout << "After sorting: " << test_arr << endl;

	return 0;
}