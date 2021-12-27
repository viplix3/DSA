#include <bits/stdc++.h>
using namespace std;

int solveKnapSack(vector<int> values, vector<int> weights, int knapSackCapacity, int currIdx) {
	if(currIdx == 0 || knapSackCapacity <= 0)
		return 0;

	int selectionProfit, rejectionProfit, maxProfit;
	selectionProfit = rejectionProfit = maxProfit = INT_MIN;

	if(weights[currIdx - 1] <= knapSackCapacity)
		selectionProfit = values[currIdx - 1] + solveKnapSack(values, weights, knapSackCapacity - weights[currIdx - 1],
																	currIdx - 1);
	rejectionProfit = solveKnapSack(values, weights, knapSackCapacity, currIdx - 1);
	maxProfit = max(selectionProfit, rejectionProfit);

	return maxProfit;
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