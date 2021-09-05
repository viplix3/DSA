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

	Node* getInOrderSuccessor(Node* root) {
		root = root->right;
		while(root != NULL && root->left != NULL)
			root = root->left;
		return root;
	}

	Node* delete_node(Node* root, int key) {
		if(root == NULL)
			return NULL;

		if(root->data < key)
			root->right = delete_node(root->right, key);
		else if(root->data > key) {
			if(root->leftNodeCount != 0)
				root->leftNodeCount -=1;
			root->left = delete_node(root->left, key);
		}
		else {
			if(root->right == NULL) {
				Node* left_node = root->left;
				if(left_node->leftNodeCount != 0)
					left_node->leftNodeCount -= 1;
				delete root;
				return left_node;
			}
			else if(root->left == NULL) {
				Node* right_node = root->right;
				delete root;
				return right_node;
			}
			else {
				Node* successor = getInOrderSuccessor(root);
				root->data = successor->data;
				root->right = delete_node(root->right, successor->data);
			}
		}
		return root;
	}

	Node* insert(Node* root, int x) {
		if(root == NULL)
			return new Node(x);
		
		if(root->data < x)
			root->right = insert(root->right, x);
		else if(root->data > x) {
			root->left = insert(root->left, x);
			root->leftNodeCount += 1;
		}
		else {
			root = delete_node(root, x);
			insert(root, x);
		}
		return root;
	}

	int getMaxLeftNodeCount(Node* root) {
		int maxLeftNode = INT_MIN;
		if(root == NULL)
			return 0;
		
		stack<Node*> prev_node;
		while(root != NULL || prev_node.empty() == false) {
			while(root != NULL) {
				prev_node.push(root);
				root = root->left;
			}

			root = prev_node.top();
			prev_node.pop();
			maxLeftNode = max(root->leftNodeCount, maxLeftNode);
			root = root->right;
		}

		return maxLeftNode;
	}
}

int main() {
	int numTestCases;
	cin >> numTestCases;

	while(numTestCases--) {
		int numElements;
		aug_BST::Node *root = NULL;
		int node_data;

		cin >> numElements;

		for(int i=0; i<numElements; i++) {
			cin >> node_data;
			root = aug_BST::insert(root, node_data);
		}

		cout << aug_BST::getMaxLeftNodeCount(root) << endl;
	}

	return 0;
}