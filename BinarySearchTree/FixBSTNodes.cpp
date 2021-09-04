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

	int prevNodeData = INT_MIN;
	Node *swapNode = NULL;

	Node* fixBST(Node* root) {
		if(root == NULL)
			return NULL;
		
		vector<Node*> inOrder;

		// Iterative inOrder
		Node* curr = root;
		stack<Node*> treeNodes;
		while(curr != NULL || treeNodes.empty() == false) {
			while(curr != NULL) {
				treeNodes.push(curr);
				curr = curr->left;
			}
			curr = treeNodes.top();
			treeNodes.pop();
			inOrder.emplace_back(curr);
			curr = curr->right;
		}

		// Find sorting violation nodes and swap
		int firstIdx = -1, secondIdx = -1;
		for(int i=1; i<inOrder.size(); i++) {
			if(inOrder[i]->data < inOrder[i-1]->data) {
				if(firstIdx == -1)
					firstIdx = i-1;
				secondIdx = i;
			}
		}

		int swap_data = inOrder[secondIdx]->data;
		inOrder[secondIdx]->data = inOrder[firstIdx]->data;
		inOrder[firstIdx]->data = swap_data;

		return root;
	}
}