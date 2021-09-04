#include<bits/stdc++.h>
using namespace std;

namespace BST {
	struct Node {
		int data;
		Node *left, *right;

		Node(int x)
			: data(x), left(NULL), right(NULL)
		{}
	};


	void findSwapNodes(Node* root, Node* &prevNode, Node* &firstSwapNode, Node* &secondSwapNode) {
		if(root == NULL)
			return;
		
		findSwapNodes(root->left, prevNode, firstSwapNode, secondSwapNode);

		if(prevNode != NULL && root->data < prevNode->data) {
			if(firstSwapNode == NULL)
				firstSwapNode = root;
			secondSwapNode = root;
		}
		prevNode = root;

		findSwapNodes(root->right, prevNode, firstSwapNode, secondSwapNode);
	}

	void fixBST(Node* root) {
		if(root == NULL)
			return;

		Node *prevNode = NULL;
		Node *firstSwapNode = NULL, *secondSwapNode = NULL;

		findSwapNodes(root, prevNode, firstSwapNode, secondSwapNode);

		int swapData = firstSwapNode->data;
		firstSwapNode->data = secondSwapNode->data;
		secondSwapNode->data = swapData;
	}
}