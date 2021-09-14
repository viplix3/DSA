#include<bits/stdc++.h>
using namespace std;

vector<double> getMedian(vector<double>& arr) {
	priority_queue<double> smallerHalf;
	priority_queue<double, vector<double>, greater<double>> greaterHalf;

	/*
		smallerHalf is a max-heap, so smallerHalf.top() will give us the max element is smaller half
		greaterHalf is a min-heap, so greaterHalf.top() will give is the min element in the greater half
		We will always try to keep the number of elements same in both the smallerHalf and greaterHalf
		If there are odd number of elements, smallerHalf will hold the extra element
		At any point of time, the median can be calculated by taking 
			Even case: average of largest element in the smallerHalf and smallest element is the greaterHalf
			Odd Case: largest element in the smallerHalf
	*/

	smallerHalf.push(arr[0]);
	double currMedian = arr[0];
	vector<double> streamMedians;
	streamMedians.push_back(currMedian);

	for(int i=1; i<arr.size(); i++) {
		double currKey = arr[i];

		// Element will be inserted in the half having lower number of elements
		if(smallerHalf.size() > greaterHalf.size()) {
			// If largest element in smallerHalf is greater than the currKey being inserted,
			// move the element from smaller half to greater half and insert the currKey in smaller half
			if(smallerHalf.top() > currKey) {
				greaterHalf.push(smallerHalf.top());
				smallerHalf.pop();
				smallerHalf.push(currKey);
			}
			else
				greaterHalf.push(currKey);
			currMedian = (smallerHalf.top() + greaterHalf.top()) / 2.0;
		}
		else {
			// If currKey being inserted is less than max element in smaller half, insert the currKey in smallerHalf
			if(currKey <= smallerHalf.top()) 
				smallerHalf.push(currKey);
			else {
				greaterHalf.push(currKey);
				smallerHalf.push(greaterHalf.top());
				greaterHalf.pop();
			}
			currMedian = smallerHalf.top();
		}

		streamMedians.push_back(currMedian);
	}

	return streamMedians;
}

std::ostream& operator<<(std::ostream& out_stream, vector<double> arr) {
	for(auto key : arr)
		out_stream << key << " ";
	return out_stream;
}


int main() {
	vector<double> keys;
	vector<double> medians;

	keys = {12, 15, 10, 5, 8, 7, 16};
	cout << "\nInput stream: " << keys << endl;
	medians = getMedian(keys);
	cout << "Medians: " << medians << endl;

	keys = {25, 7, 10, 15, 20};
	cout << "\nInput stream: " << keys << endl;
	medians = getMedian(keys);
	cout << "Medians: " << medians << endl;

	return 0;
}