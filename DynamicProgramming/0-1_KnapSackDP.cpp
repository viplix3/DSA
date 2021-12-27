#include <bits/stdc++.h>
using namespace std;

int solveKnapSack(vector<int> values, vector<int> weights, int knapSackCapacity, int currIdx) {
	int totalElems = values.size();
	vector<vector<int>> knapSackProfit(totalElems + 1, vector<int>(knapSackCapacity + 1, INT_MIN));

	for(int currWeight = 0; currWeight <= knapSackCapacity; currWeight++)
		knapSackProfit[0][currWeight] = 0; // Profit will be 0 if item value is 0, irrespective of item weight
	
	for(int currItemIdx = 0; currItemIdx <= totalElems; currItemIdx++)
		knapSackProfit[currItemIdx][0] = 0; // Profit will be 0 if knapSackCapacity is 0, irrespective of the value of item
	
	for(int currItemIdx = 1; currItemIdx <= totalElems; currItemIdx++) {
		for(int currWeight = 1; currWeight <= knapSackCapacity; currWeight++) {
			knapSackProfit[currItemIdx][currWeight] = knapSackProfit[currItemIdx - 1][currWeight]; // Don't add current item

			if(weights[currItemIdx - 1] <= currWeight)
				knapSackProfit[currItemIdx][currWeight] = max(values[currItemIdx - 1] +
																knapSackProfit[currItemIdx - 1][currWeight - weights[currItemIdx - 1]],
																knapSackProfit[currItemIdx - 1][currWeight]);
		}
	}

	return knapSackProfit[totalElems][knapSackCapacity];
}

template<typename T>
ostream& operator<<(ostream& outStream, vector<T> data) {
	for(T datum : data)
		outStream << datum << " ";
	return outStream;
}

int main() {
	vector<int> values, weights;
	int knapSackCapacity;

	values = {10, 40, 30, 50};
	weights = {5, 4, 6, 3};
	knapSackCapacity = 10;
	cout << "Values: " << values << endl;
	cout << "Weights: " << weights << endl;
	cout << "Max value that can be held in a knapsack with weight capacity of " << knapSackCapacity << " : ";
	cout << solveKnapSack(values, weights, knapSackCapacity, values.size()) << endl;
	cout << endl;

	values = {60, 100, 120};
	weights = {10, 20, 30};
	knapSackCapacity = 50;
	cout << "Values: " << values << endl;
	cout << "Weights: " << weights << endl;
	cout << "Max value that can be held in a knapsack with weight capacity of " << knapSackCapacity << " : ";
	cout << solveKnapSack(values, weights, knapSackCapacity, values.size()) << endl;
	cout << endl;

	// values = {};
	// weights = {};
	// knapSackCapacity = ;
	// cout << "Values: " << values << endl;
	// cout << "Weights: " << weights << endl;
	// cout << "Max value that can be held in a knapsack with weight capacity of " << knapSackCapacity << " : ";
	// cout << solveKnapSack(values, weights, knapSackCapacity, values.size()) << endl;
	// cout << endl;

	return 0;
}
