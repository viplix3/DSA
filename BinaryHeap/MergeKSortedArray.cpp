#include<bits/stdc++.h>
using namespace std;

struct Triplet {
	int val, arrPos, valPos;

	Triplet(int element, int arrayIdx, int elementIdx)
		: val(element), arrPos(arrayIdx), valPos(elementIdx)
	{}

};

struct TripletComparator {
	bool operator()(Triplet& T1, Triplet& T2) {
		return T1.val > T2.val;
	}
};

vector<int> mergeKSorted(vector<vector<int>> &arr) {
	vector<int> merged;

	priority_queue<Triplet, vector<Triplet>, TripletComparator> TripletMinHeap;

	// Create an entry for first elment of each of the k-arrays in TripletMinHeap
	for(int i=0; i<arr.size(); i++) {
		Triplet T(arr[i][0], i, 0);
		TripletMinHeap.push(T);
	}

	while(TripletMinHeap.empty() == false) {
		Triplet currTriplet = TripletMinHeap.top();
		TripletMinHeap.pop();

		merged.push_back(currTriplet.val);

		int currArrIdx = currTriplet.arrPos;
		int currEleIdx = currTriplet.valPos;
		int nextEleIdx = currEleIdx+1;

		if(nextEleIdx < arr[currArrIdx].size()) {
			Triplet nextTriplet(arr[currArrIdx][nextEleIdx], currArrIdx, nextEleIdx);
			TripletMinHeap.push(nextTriplet);
		}
	}

	return merged;
}

std::ostream& operator<<(std::ostream& out_stream, vector<vector<int>>& arr) {
	for(auto subArr: arr) {
		for(auto ele : subArr)
			out_stream << ele << " ";
		out_stream << endl;
	}
	return out_stream;
}

std::ostream& operator<<(std::ostream& out_stream, vector<int>& arr) {
	for(auto ele : arr)
		out_stream << ele << " ";
	return out_stream;
}

int main() {
	vector<vector<int>> test_arr;
	vector<int> merged;

	test_arr = {{10,	20,	30},
				{5,	15},
				{1,	9,	11,	18}};
	cout << "\nSorted K input arrays" << endl;
	cout << test_arr;
	merged = mergeKSorted(test_arr);
	cout << "Merged array: " << merged << endl;

	test_arr = {{5,	20,	30},
				{1,	2}};
	cout << "\nSorted K input arrays" << endl;
	cout << test_arr;
	merged = mergeKSorted(test_arr);
	cout << "Merged array: " << merged << endl;

	return 0;
}