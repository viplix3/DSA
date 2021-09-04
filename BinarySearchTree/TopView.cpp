#include<bits/stdc++.h>
using namespace std;

namespace Tree{
	struct Node {
		int data;
		Node *left, *right;

		Node(int x)
			: data(x), left(NULL), right(NULL)
		{}
	};

	map<int, int> getTopView(Node* root) {
		map<int, int> topViewMap;

		if(root == NULL)
			return topViewMap;
		
		queue<pair<int, Node*>> treeLevelNodes;

		treeLevelNodes.push(make_pair(0, root));
		
		while(treeLevelNodes.empty() == false) {
			auto curr_pair = treeLevelNodes.front();
			treeLevelNodes.pop();

			int curr_hDist = curr_pair.first;
			Node* curr_node = curr_pair.second;

			if(topViewMap.find(curr_hDist) == topViewMap.end())
				topViewMap[curr_hDist] = curr_node->data;
			
			if(curr_node->left != NULL)
				treeLevelNodes.push(make_pair(curr_hDist-1, curr_node->left));
			if(curr_node->right != NULL)
				treeLevelNodes.push(make_pair(curr_hDist+1, curr_node->right));
		}

		return topViewMap;
	}

	vector<int> topViewTraversal(Node* root) {
		vector<int> traversedOutput;

		if(root == NULL)
			return traversedOutput;

		map<int, int> topView = getTopView(root);

		for(auto vnode_pair : topView)
			traversedOutput.emplace_back(vnode_pair.second);

		return traversedOutput;
	}

}