#include<bits/stdc++.h>
using namespace std;

vector<int> getCeilingOnLeft(vector<int>& arr) {
	set<int> bst;
	vector<int> leftCeiling;

	leftCeiling.emplace_back(-1);
	bst.insert(arr[0]);

	for(int i=1; i<arr.size(); i++) {
		if(bst.lower_bound(arr[i]) != bst.end())
			leftCeiling.emplace_back(*(bst.lower_bound(arr[i])));
		else
			leftCeiling.emplace_back(-1);
		bst.insert(arr[i]);
	}
	
	return leftCeiling;
}

std::ostream& operator<<(std::ostream& out, vector<int>& arr) {
	for(auto x: arr)
		out << x << " ";
	return out;
}

int main() {
	vector<int> testVec;
	vector<int> leftCeiling;

	testVec = {2, 8, 30, 15, 25, 12};
	cout << "\nTest vector: " << testVec << endl;
	leftCeiling = getCeilingOnLeft(testVec);
	cout << "Left ceiling of each element: " << leftCeiling << endl;

	testVec = {30, 20, 10};
	cout << "\nTest vector: " << testVec << endl;
	leftCeiling = getCeilingOnLeft(testVec);
	cout << "Left ceiling of each element: " << leftCeiling << endl;

	testVec = {10, 20, 30};
	cout << "\nTest vector: " << testVec << endl;
	leftCeiling = getCeilingOnLeft(testVec);
	cout << "Left ceiling of each element: " << leftCeiling << endl;

	testVec = {6, 18, 4, 5};
	cout << "\nTest vector: " << testVec << endl;
	leftCeiling = getCeilingOnLeft(testVec);
	cout << "Left ceiling of each element: " << leftCeiling << endl;

	return 0;
}