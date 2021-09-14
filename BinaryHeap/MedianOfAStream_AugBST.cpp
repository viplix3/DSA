#include<bits/stdc++.h>
using namespace std;

namespace AugBST {
	struct Node {
		double data;
		int numLeftChild;
		Node *left, *right;

		Node(double x)
			: data(x), numLeftChild(0), left(NULL), right(NULL)
		{}
	};

	Node* insert(Node* root, double x) {
		if(root == NULL)
			return new Node(x);

		if(root->data < x)
			root->right = insert(root->right, x);
		else if(root->data > x) {
			root->left = insert(root->left, x);
			root->numLeftChild += 1;
		}
		return root;
	}

	Node* kthSmallest(Node* root, int k) {
		if(root == NULL || k <= 0)
			return root;
		
		int currNodeCount = root->numLeftChild + 1;
		if(currNodeCount == k)
			return root;
		if(currNodeCount > k)
			return kthSmallest(root->left, k);
		else
			return kthSmallest(root->right, k - currNodeCount);
	}
}

int main() {
	AugBST::Node* root = NULL;
	double keys[] = {25, 7, 10, 15, 20};
	int size = 0;

	for(double x : keys) {
		size += 1;
		root = AugBST::insert(root, x);

		double currMedian;
		if(size % 2 != 0)
			currMedian = (AugBST::kthSmallest(root, (size/2)+1))->data;
		else
			currMedian = (((AugBST::kthSmallest(root, (size/2)+1))->data) + \
					((AugBST::kthSmallest(root, (size/2)))->data)) / 2;

		cout << currMedian << " ";
	}

	cout << endl;
	return 0;
}