#include <bits/stdc++.h>
using namespace std;

pair<int, int> findOddOccurringNumbers(vector<int>& arr) {
	int arrXOR = 0;
	pair<int, int> result = make_pair(0, 0);

	for(int i = 0; i < arr.size(); i++)
		arrXOR ^= arr[i];
	
	int rightMostSetBit = arrXOR & (~(arrXOR - 1));

	for(int i = 0; i < arr.size(); i++) {
		if((arr[i] & rightMostSetBit) != 0)
			result.first ^= arr[i];
		else
			result.second ^= arr[i];
	}

	return result;
}


int main() {
	int numTestCases;
	cin >> numTestCases;

	while(numTestCases--) {
		int data, numArrElems;
		vector<int> arr;

		cin >> numArrElems;
		for(int i = 0; i < numArrElems; i++) {
			cin >> data;
			arr.push_back(data);
		}

		pair<int, int> output = findOddOccurringNumbers(arr);
		cout << "Two odd occurring numbers in given array: " <<
				output.first << " " << output.second << endl;
		
		arr.clear();
	}

	return 0;
}