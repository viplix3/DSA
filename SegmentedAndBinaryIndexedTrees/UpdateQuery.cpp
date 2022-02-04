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

void updateSegTree(vector<int>& segmentTree, int updateIdx, int updateData,
					int segmentBeginIdx, int segmentEndIdx, int currSegmentIdx) {

	if(updateIdx < segmentBeginIdx && updateIdx > segmentEndIdx)
		return;

	segmentTree[currSegmentIdx] += updateData;

	if(segmentEndIdx > segmentBeginIdx) {
		int midIdx = (segmentBeginIdx + segmentEndIdx) / 2;
		int leftChildIdx = (2 * currSegmentIdx) + 1;
		int rightChildIdx = (2 * currSegmentIdx) + 2;

		updateSegTree(segmentTree, updateIdx, updateData, segmentBeginIdx, midIdx, leftChildIdx);
		updateSegTree(segmentTree, updateIdx, updateData, midIdx + 1, segmentEndIdx, rightChildIdx);
	}
}

ostream& operator<<(ostream& outStream, vector<int> data) {
	for(int datum : data)
		if(datum != INT_MAX)
			outStream << datum << " ";
	return outStream;
}

enum queryType {
	UPDATE, SUM
};

struct query {
	int beginIdx, endIdx_data;
	queryType type;

	query(int val1, int val2, const queryType _type)
		: beginIdx(val1), endIdx_data(val2), type(_type)
	{}
};

int main() {
	vector<int> testData, segTree;
	vector<query> queries;

	testData = {10, 20, 30, 40};
	queries = {query(1, 25, queryType::UPDATE),
				query(0, 15, queryType::UPDATE),
				query(0, 1, queryType::SUM),
				query(1, 2, queryType::SUM)};

	int numQueries = queries.size();
	int numElements = testData.size() - 1;

	cout << "Input array: " << testData << endl;

	segTree = constructSegTree(testData);
	cout << "Segment tree for input array: " << segTree << endl << endl;

	for(int i = 0; i < numQueries; i++) {
		query currQuery = queries[i];

		if(currQuery.type == queryType::SUM)
			cout << "Sum for range [" << currQuery.beginIdx << ", " << currQuery.endIdx_data << "]: "
				<< getSegTreeSum(segTree, currQuery.beginIdx, currQuery.endIdx_data, 0, numElements, 0) << endl;
		else {
			cout << "Updating segment tree for update query at index " << currQuery.beginIdx << " with data " << currQuery.endIdx_data << endl;
			updateSegTree(segTree, currQuery.beginIdx, currQuery.endIdx_data - testData[currQuery.beginIdx], 0, numElements, 0);
			cout << "Updated segment tree: " << segTree << endl;
		}
	}


	return 0;
}
