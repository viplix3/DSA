#include<bits/stdc++.h>
using namespace std;

namespace BST {
	int prevNodeData = INT_MIN;

	struct Node {
		int data;
		Node *left, *right;

		Node(int x)
			: data(x), left(NULL), right(NULL)
		{}
	};

	/*
		A BTree is BST iff its inOrder traversal is sorted.
		To make InOrder sorted check in constant time, we are keeping the prev
		node element in prevNodeData variable and updating it after checking with current root
	*/
	bool isBST(Node* root) { // InOrder traversal based BST check
		if(root == NULL)
			return true;

		if(isBST(root->left) == false)
			return false;
		
		if(root->data <= prevNodeData)
			return false;
		prevNodeData = root->data;

		return isBST(root->right);
	}
}