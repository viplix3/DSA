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

	void verticalSumHelper(Node* root, int curr_hDist, map<int, int>& vsum_map) {
		if(root == NULL)
			return;
		
		verticalSumHelper(root->left, curr_hDist-1, vsum_map);
		vsum_map[curr_hDist] += root->data;
		verticalSumHelper(root->right, curr_hDist+1, vsum_map);
	}

	vector<int> getVerticalDist(Node* root) {
		map<int, int> vertical_dist;
		vector<int> verticalDist_vector;

		verticalSumHelper(root, 0, vertical_dist);

		for(auto vsum: vertical_dist)
			verticalDist_vector.emplace_back(vsum.second);
		
		return verticalDist_vector;
	}
}