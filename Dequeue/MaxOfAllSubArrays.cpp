#include <bits/stdc++.h>
using namespace std;

vector<int> getMaxOfSubArray(vector<int>& arr, int windowSize)
{
	vector<int> subArrayMax;
	deque<int> window;

	for(int i=0; i<windowSize; i++) {
		while(window.empty() == false && \
				arr[i] >= arr[window.back()]) // Inserting window elements in decreasing order
			window.pop_back();

		window.push_back(i);
	}

	for(int i=windowSize; i < arr.size(); i++) {
		subArrayMax.emplace_back(arr[window.front()]);

		while(window.empty() == false && \
				window.front() <= (i - windowSize)) // Removing older window elements
			window.pop_front();

		while(window.empty() == false && \
				arr[i] >= arr[window.back()]) // Inserting new window elements in decresing order
			window.pop_back();
		window.push_back(i);
	}

	// Max of last window
	subArrayMax.emplace_back(arr[window.front()]);

	return subArrayMax;
}

std::ostream& operator<<(std::ostream& out, vector<int> arr) {
	for(auto x: arr)
		out << x << " ";
	return out;
}

int main() {
	vector<int> test_vector;
	int windowSize;

	test_vector = {20, 40, 30, 10, 60};
	windowSize = 3;
	cout << "Input vector: " << test_vector << endl;
	cout << "Maximum of each subarray of size " << windowSize << ": ";
	cout << getMaxOfSubArray(test_vector, windowSize) << endl;

	test_vector = {10, 8, 5, 12, 15, 7, 6};
	windowSize = 3;
	cout << "\nInput vector: " << test_vector << endl;
	cout << "Maximum of each subarray of size " << windowSize << ": ";
	cout << getMaxOfSubArray(test_vector, windowSize) << endl;

	test_vector = {20, 5, 3, 8, 6, 15};
	windowSize = 4;
	cout << "\nInput vector: " << test_vector << endl;
	cout << "Maximum of each subarray of size " << windowSize << ": ";
	cout << getMaxOfSubArray(test_vector, windowSize) << endl;

	return 0;
}