#include<bits/stdc++.h>
using namespace std;

namespace Tree {
	struct Node {
		int data;
		Node *left, *right;

		Node(int x)
			: data(x), left(NULL), right(NULL)
		{}
	};

	void verticalTraversalHelper(Node* root, map<int, vector<int>>& vnode_map) {
		if(root == NULL)
			return;

		queue<pair<Node*, int>> treeLevelNodes;
		treeLevelNodes.push(make_pair(root, 0));

		while(treeLevelNodes.empty() == false) {
			auto curr_pair = treeLevelNodes.front();
			treeLevelNodes.pop();

			Node *curr = curr_pair.first;
			int curr_hDist = curr_pair.second;
			vnode_map[curr_hDist].emplace_back(curr->data);

			if(curr->left != NULL)
				treeLevelNodes.push(make_pair(curr->left, curr_hDist-1));
			if(curr->right != NULL)
				treeLevelNodes.push(make_pair(curr->right, curr_hDist+1));
		}
	}

	vector<int> verticalTraversal(Node* root) {
		map<int, vector<int>> vnode_map;
		vector<int> vTraversal;

		verticalTraversalHelper(root, vnode_map);

		for(auto vnodes: vnode_map) {
			for(auto data: vnodes.second)
				vTraversal.emplace_back(data);
		}

		return vTraversal;
	}
}