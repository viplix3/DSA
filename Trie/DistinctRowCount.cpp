#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
	TrieNode *child[2];

	TrieNode() {
		for(int i = 0; i < 2; i++)
			child[i] = nullptr;
	}
};

bool insert(TrieNode *root, vector<vector<int>>& matrix, int rowIdx) {
	TrieNode *curr = root;
	bool newData = false;
	int numCols = matrix[rowIdx].size();

	for(int colIdx = 0; colIdx < numCols; colIdx++) {
		int data = matrix[rowIdx][colIdx];

		if(curr->child[data] == nullptr) {
			curr->child[data] = new TrieNode();
			newData = true;
		}

		curr = curr->child[data];
	}

	return newData;
}

int countDistinctRows(vector<vector<int>> data) {
	TrieNode *root = new TrieNode();
	int numRows = data.size();
	int numDistinctRows = 0;

	for(int currRow = 0; currRow < numRows; currRow++)
		if(insert(root, data, currRow))
			numDistinctRows += 1;

	return numDistinctRows;
}

ostream& operator<<(ostream& outStream, const vector<vector<int>>& data) {
	for(vector<int> rowData : data) {
		for(int datum : rowData)
			outStream << datum << " ";
		outStream << endl;
	}

	return outStream;
}

int main() {
	vector<vector<int>> testData;

	testData = { {1, 0, 0},
				 {1, 1, 1},
				 {1, 0, 0},
				 {1, 1, 1} };
	cout << "Input matrix \n" << testData;
	cout << "Number of distinct rows: " << countDistinctRows(testData) << endl;
	cout << endl;
	
	testData = { {1, 1, 0, 0},
				 {1, 1, 0, 0},
				 {1, 1, 0, 0},
				 {1, 1, 0, 0} };
	cout << "Input matrix \n" << testData;
	cout << "Number of distinct rows: " << countDistinctRows(testData) << endl;
	cout << endl;

	testData = { {1, 0, 0},
				 {1, 1, 1},
				 {1, 0, 0},
				 {0, 1, 0} };
	cout << "Input matrix \n" << testData;
	cout << "Number of distinct rows: " << countDistinctRows(testData) << endl;
	cout << endl;
	return 0;
}