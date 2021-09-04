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

	// InOrder traversal based method
	bool pairSum(Node* root, int sum) {
		if(root == NULL)
			return false;
		
		// Iterative inOrder
		vector<Node*> inOrder;
		stack<Node*> prevNode;
		Node *curr = root;
		while(curr != NULL || prevNode.empty() == false) {
			while(curr != NULL) {
				prevNode.push(curr);
				curr = curr->left;
			}
			curr = prevNode.top();
			prevNode.pop();
			inOrder.push(curr);
			curr = curr->right;
		}

		int startIdx = 0, endIdx = inOrder.size()-1;
		while(startIdx < endIdx) {
			int beginData = inOrder[startIdx]->data;
			int endData = inOrder[endIdx]->data;

			if((beginData + endData) < sum)
				startIdx += 1;
			else if((beginData + endData) > sum)
				endIdx -= 1;
			else
				return true;
		}
		return false;
	}

	bool isPairSum(Node *root, int sum, unordered_set<int> &s) {
		if(root == NULL)
			return false;
		
		if(isPairSum(root->left, sum, s))
			return true;
			
		if(s.find(sum-root->data) != s.end())  
			return true;
		else
			s.insert(root->data);
		return isPairSum(root->right, sum, s);
	} 


}