// https://practice.geeksforgeeks.org/problems/smaller-on-right/0/

#include<bits/stdc++.h>
using namespace std;

namespace aug_BST {
	struct Node {
		int data;
		int leftNodeCount;
		Node *left, *right;

		Node(int x)
			: data(x), leftNodeCount(0), left(NULL), right(NULL)
		{}
	};

	bool count_and_insert(Node* root, int x, int& curr_count) {
		if(root->data > x) { // Node will be inserted on the left of root
			root->leftNodeCount += 1;

			if(root->left == NULL) { // If current root node is having no left child
				root->left = new Node(x); // Insert neew node
				return true;
			}
			else {
				if(!count_and_insert(root->left, x, curr_count)) { // If inserting node on root wasn't possible
					root->leftNodeCount -= 1; // Nullify the left node count increased earlier
					return false;
				}
				else
					return true;
			}
		}
		else if(root->data < x) {
			curr_count = (root->leftNodeCount + curr_count + 1);

			if(root->right == NULL) { // If current node is having no right child
				root->right = new Node(x);
				return true;
			}
			else {
				if(!count_and_insert(root->right, x, curr_count))
					return false;
				else
					return true;
			}
		}
		else { // The value to be inserted is already present in the BST
			curr_count = (curr_count + root->leftNodeCount);
			return false;
		}
	}
}

int main() {
	int numTestCases;
	cin >> numTestCases;

	while(numTestCases--) {
		int numElements, maxSmallCount = INT_MIN;

		cin >> numElements;
		int arr[numElements];

		for(int i=0; i<numElements; i++)
			cin >> arr[i];

		aug_BST::Node *root = new aug_BST::Node(arr[numElements-1]);
		for(int i=numElements-2; i>=0; i--) {
			int curr_small_count = 0;
			aug_BST::count_and_insert(root, arr[i], curr_small_count);
			maxSmallCount = max(curr_small_count, maxSmallCount);
		}

		maxSmallCount = max(0, maxSmallCount);
		cout << maxSmallCount << endl;
	}

	return 0;
}