#include <bits/stdc++.h>
using namespace std;

int getMinDelOps(vector<int> arr) {
	int numElems = arr.size();
	int numLisElems = 1;
	vector<int> lisArr;
	
	lisArr.emplace_back(arr[0]);

	for(int i = 1; i < numElems; i++) {
		if(arr[i] > lisArr[numLisElems - 1]) {
			lisArr.emplace_back(arr[i]);
			numLisElems += 1;
		}
		else {
			auto itr = upper_bound(lisArr.begin(), lisArr.end(), arr[i]);
			*itr = arr[i];
		}
	}

	int numDeleteOps = numElems - numLisElems;
	return numDeleteOps;
}

ostream& operator<<(ostream& outStream, vector<int> data) {
	for(int datum : data)
		outStream << datum << " ";
	return outStream;
}

int main() {
	vector<int> testArray;

	testArray = {5, 10, 3, 6, 7, 8};
	cout << "Input array: " << testArray << endl;
	cout << "Minimum deletion operations required to sort the array: " << getMinDelOps(testArray);
	cout << endl;

	return 0;
}