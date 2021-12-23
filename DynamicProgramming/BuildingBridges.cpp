#include <bits/stdc++.h>
using namespace std;

struct BridgeInfo {
	int source, destination;

	BridgeInfo(int from, int to)
		:source(from), destination(to)
	{}
};

bool BridgeComparator(const BridgeInfo& bridge1, const BridgeInfo& bridge2) {
	if(bridge1.source == bridge2.source)
		return bridge1.destination < bridge2.destination;

	return bridge1.source < bridge2.source;
}

ostream& operator<<(ostream& outStream, vector<BridgeInfo> data) {
	for(BridgeInfo bridge : data)
		outStream << bridge.source << " -> " << bridge.destination << endl;
	return outStream;
}

int getLIS(vector<int> arr) {
	int numElems = arr.size();
	vector<int> lisArr;

	lisArr.emplace_back(arr[0]);
	int numLisElems = 1;

	for(int currIdx = 1; currIdx < numElems; currIdx++) {
		if(arr[currIdx] > lisArr[numLisElems - 1]) {
			lisArr.emplace_back(arr[currIdx]);
			numLisElems += 1;
		}
		else {
			auto itr = upper_bound(lisArr.begin(), lisArr.end(), arr[currIdx]);
			*itr = arr[currIdx];
		}
	}

	return lisArr.size();
}

int getMaxBridges(vector<BridgeInfo> bridges) {
	sort(bridges.begin(), bridges.end(), BridgeComparator);

	vector<int> bridgeDestinations;

	for(BridgeInfo bridgeData : bridges)
		bridgeDestinations.emplace_back(bridgeData.destination);
	
	return getLIS(bridgeDestinations);
}


int main() {
	vector<BridgeInfo> testData;

	testData = {BridgeInfo(6, 2), BridgeInfo(4, 3), BridgeInfo(2, 6), BridgeInfo(1, 5)};
	cout << "Bridge construction plan" << endl;
	cout << testData;
	cout << "Maximum bridges that can be constructed without crossing: " << getMaxBridges(testData) << endl;
	cout << endl;

	testData = {BridgeInfo(8, 1), BridgeInfo(1, 2), BridgeInfo(4, 3), BridgeInfo(3, 4),
				BridgeInfo(2, 6), BridgeInfo(6, 7), BridgeInfo(7, 8), BridgeInfo(5, 5)};
	cout << "Bridge construction plan" << endl;
	cout << testData;
	cout << "Maximum bridges that can be constructed without crossing: " << getMaxBridges(testData) << endl;
	cout << endl;

	return 0;
}