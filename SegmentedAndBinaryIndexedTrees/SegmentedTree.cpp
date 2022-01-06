#include <bits/stdc++.h>
using namespace std;

int constructSTree(int segmentStartIdx, int segmentEndIdx, int segTreeIdx, vector<int>& segTree, vector<int>& arr) {
	if(segmentStartIdx == segmentEndIdx) {
		segTree[segTreeIdx] = arr[segmentStartIdx];
		return segTree[segTreeIdx];
	}

	int midIdx = (segmentStartIdx + segmentEndIdx) / 2;
	int leftChildIdx = (2 * segTreeIdx + 1), rightChildIdx = (2 * segTreeIdx + 2);
	segTree[segTreeIdx] = constructSTree(segmentStartIdx, midIdx, leftChildIdx, segTree, arr) +
							constructSTree(midIdx + 1, segmentEndIdx, rightChildIdx, segTree, arr);
	return segTree[segTreeIdx];
}

vector<int> constructSegTree(vector<int> arr) {
	int numElements = arr.size();
	vector<int> segTree(4 * numElements, INT_MAX);

	constructSTree(0, numElements - 1, 0, segTree, arr);

	return segTree;
}

ostream& operator<<(ostream& outStream, vector<int> data) {
	for(int datum : data)
		if(datum != INT_MAX)
			outStream << datum << " ";
	return outStream;
}

int main() {
	vector<int> testData, segTree;

	testData = {10, 20, 30, 40};
	cout << "Input array: " << testData << endl;
	segTree = constructSegTree(testData);
	cout << "Segmented Indexed Tree: " << segTree << endl;
	cout << endl;

	testData = {10, 20, 30, 40, 50, 60};
	cout << "Input array: " << testData << endl;
	segTree = constructSegTree(testData);
	cout << "Segmented Indexed Tree: " << segTree << endl;
	cout << endl;

	return 0;
}