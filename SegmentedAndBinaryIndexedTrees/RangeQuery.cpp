#include <bits/stdc++.h>
using namespace std;

int constructSTree(int segmentStartIdx, int segmentEndIdx, int segTreeIdx, vector<int>& segTree, const vector<int>& arr) {
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

int getSegTreeSum(const vector<int>& segmentTree, int queryStartIdx, int queryEndIdx,
					int segmentStartIdx, int segmentEndIdx, int currSegmentIdx) {
	
	bool outOfBounds = (segmentStartIdx > queryEndIdx || segmentEndIdx < queryStartIdx);

	if(outOfBounds)
		return 0;

	if(queryStartIdx <= segmentStartIdx && queryEndIdx >= segmentEndIdx)
		return segmentTree[currSegmentIdx];
	
	int midIdx = (segmentStartIdx + segmentEndIdx) / 2;
	int leftChildIdx = (2 * currSegmentIdx) + 1;
	int rightChildIdx = (2 * currSegmentIdx) + 2;

	return getSegTreeSum(segmentTree, queryStartIdx, queryEndIdx, segmentStartIdx, midIdx, leftChildIdx) +
			getSegTreeSum(segmentTree, queryStartIdx, queryEndIdx, midIdx + 1, segmentEndIdx, rightChildIdx);
}

ostream& operator<<(ostream& outStream, vector<int> data) {
	for(int datum : data)
		if(datum != INT_MAX)
			outStream << datum << " ";
	return outStream;
}

int main() {
	vector<int> testData, segTree;
	vector<pair<int, int>> rangeQueries;

	testData = {10, 20, 30, 40};
	rangeQueries = {{0, 2},
					{1, 3},
					{0, 3}};
	int numQueries = rangeQueries.size();
	int numElements = testData.size() - 1;

	cout << "Input array: " << testData << endl;

	segTree = constructSegTree(testData);

	for(int i = 0; i < numQueries; i++) {
		cout << "Sum for range [" << rangeQueries[i].first << ", " << rangeQueries[i].second << "]: "
			<< getSegTreeSum(segTree, rangeQueries[i].first, rangeQueries[i].second, 0, numElements, 0) << endl;
	}


	return 0;
}