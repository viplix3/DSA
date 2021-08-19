#include "tree.h"
#include <queue>
#include <stack>

void Tree::inOrder_traversal(Node* root)
{
	if(root == NULL)
		return;

	inOrder_traversal(root->m_left);
	std::cout << root->m_data << "\t";
	inOrder_traversal(root->m_right);
}

void Tree::preOrder_traversal(Node* root) {
	if(root == NULL)
		return;
	
	std::cout << root->m_data << "\t";
	preOrder_traversal(root->m_left);
	preOrder_traversal(root->m_right);
}

void Tree::postOrder_traversal(Node* root) {
	if(root == NULL)
		return;

	postOrder_traversal(root->m_left);
	postOrder_traversal(root->m_right);
	std::cout << root->m_data << "\t";
}

void Tree::levelOrder_traversal(Node* root) {
	if(root == NULL)
		return;
	
	std::queue<Node*> treeLevelNodes;
	treeLevelNodes.push(root);

	while(treeLevelNodes.empty() == false) {
		Node *currLevelNode = treeLevelNodes.front();
		treeLevelNodes.pop();
		std::cout << currLevelNode->m_data << "\t";

		if(currLevelNode->m_left != NULL)
			treeLevelNodes.push(currLevelNode->m_left);
		if(currLevelNode->m_right != NULL)
			treeLevelNodes.push(currLevelNode->m_right);
	}
}

void Tree::levelOrder_lineByLine(Node* root) {
	if(root == NULL)
		return;

	std::queue<Node*> treeLevelNodes;
	treeLevelNodes.push(root);
	treeLevelNodes.push(NULL);

	while(treeLevelNodes.empty() == false) {
		Node *currLevelNode = treeLevelNodes.front();
		treeLevelNodes.pop();

		if(currLevelNode == NULL)
			continue;

		std::cout << currLevelNode->m_data << "\t";

		if(currLevelNode->m_left != NULL)
			treeLevelNodes.push(currLevelNode->m_left);
		if(currLevelNode->m_right != NULL)
			treeLevelNodes.push(currLevelNode->m_right);

		if(treeLevelNodes.front() == NULL) {
			std::cout << std::endl;
			treeLevelNodes.pop();
			treeLevelNodes.push(NULL);
		}
	}
}

void Tree::levelOrder_lineByLine_method2(Node* root) {
	if(root == NULL)
		return;

	std::queue<Node*> treeLevelNodes;
	treeLevelNodes.push(root);

	while(treeLevelNodes.empty() == false) {
		int numLevelNodes = treeLevelNodes.size();

		for(int i=0; i<numLevelNodes; i++) {
			Node *currLevelNode = treeLevelNodes.front();
			treeLevelNodes.pop();

			std::cout << currLevelNode->m_data << "\t";

			if(currLevelNode->m_left != NULL)
				treeLevelNodes.push(currLevelNode->m_left);
			if(currLevelNode->m_right != NULL)
				treeLevelNodes.push(currLevelNode->m_right);
		}
		std::cout << std::endl;
	}
}

void Tree::printLeftView(Node* root) {
	if(root == NULL)
		return;
	
	std::queue<Node*> treeLevelNodes;
	treeLevelNodes.push(root);
	treeLevelNodes.push(NULL);

	Tree::Node *prev_node = NULL;

	while(treeLevelNodes.size() > 1) {
		Tree::Node *curr_node = treeLevelNodes.front();
		treeLevelNodes.pop();

		if(curr_node == NULL) {
			prev_node = curr_node;
			treeLevelNodes.push(NULL);
			continue;
		}

		if(prev_node == NULL)
			std::cout << curr_node->m_data << "\t";

		if(curr_node->m_left != NULL)
			treeLevelNodes.push(curr_node->m_left);
		if(curr_node->m_right != NULL)
			treeLevelNodes.push(curr_node->m_right);

		prev_node = curr_node;
	}
}

void Tree::spiralLevelOrder_traversal(Node* root) {
	if(root == NULL)
		return;
	
	std::queue<Tree::Node*> treeLevelNodes;
	std::stack<int> nodeData;
	bool reverse = false;

	treeLevelNodes.push(root);

	while(treeLevelNodes.empty() == false) {
		int currLevelNodes = treeLevelNodes.size();

		for(int i=0; i<currLevelNodes; i++) {
			Tree::Node *currNode = treeLevelNodes.front();
			treeLevelNodes.pop();

			if(reverse)
				nodeData.push(currNode->m_data);
			else
				std::cout << currNode->m_data << "\t";

			if(currNode->m_left != NULL)
				treeLevelNodes.push(currNode->m_left);
			if(currNode->m_right != NULL)
				treeLevelNodes.push(currNode->m_right);
		}

		if(reverse) {
			while(nodeData.empty() == false) {
				std::cout << nodeData.top() << "\t";
				nodeData.pop();
			}
		}
		reverse = !reverse;
		std::cout << std::endl;
	}
}

bool Tree::getNodePath(Node* root, int node_data, std::vector<Node*> &path) {
	if(root == NULL)
		return false;

	path.emplace_back(root);

	if(root->m_data == node_data)
		return true;

	if(Tree::getNodePath(root->m_left, node_data, path) || 
		Tree::getNodePath(root->m_right, node_data, path))
		return true;

	path.pop_back();
	return false;
}

Tree::Node* Tree::getLCA_pathTracingMethod(Node* root, int node1_data, int node2_data) {
	std::vector<Tree::Node*> node1_path, node2_path;
	
	if(getNodePath(root, node1_data, node1_path) == false ||
		getNodePath(root, node2_data, node2_path) == false)
		return NULL;
	
	for(int i=0; i < node1_path.size() && i < node2_path.size(); i++) {
		if(node1_path[i+1] != node2_path[i+1])
			return node1_path[i];
	}

	return NULL;
}

Tree::Node* Tree::getLCA_GFG(Node* root, int node1_data, int node2_data) {
	if(root == NULL)
		return NULL;

	if(root->m_data == node1_data || root->m_data == node2_data)
		return root;

	Tree::Node *LCA1 = getLCA_GFG(root->m_left, node1_data, node2_data);
	Tree::Node *LCA2 = getLCA_GFG(root->m_right, node1_data, node2_data);

	if(LCA1 != NULL && LCA2 != NULL) // Perfect LCA
		return root;

	if(LCA1 != NULL) // Both nodes in LCA1 (left of root)
		return LCA1;
	else // Either both nodes in LCA2 (right of root) or they doesn't exist
		return LCA2;
	return NULL;
}

void Tree::inOrder_traversalIterative(Node* root) {
	if(root == NULL)
		return;

	std::stack<Tree::Node*> prev_root;

	while(root != NULL || prev_root.empty() == false) {
		while(root != NULL) {
			prev_root.push(root);
			root = root->m_left;
		}
		root = prev_root.top();
		prev_root.pop();
		std::cout << root->m_data << "\t";
		root = root->m_right;
	}
}

void Tree::preOrder_traversalIterative(Node* root) {
	if(root == NULL)
		return;
	
	std::stack<Tree::Node*> prev_root;

	while(root != NULL || prev_root.empty() == false) {
		while(root != NULL) {
			std::cout << root->m_data << "\t";
			prev_root.push(root);
			root = root->m_left;
		}
		root = prev_root.top();
		prev_root.pop();
		root = root->m_right;
	}
}


void preOrder_traversalIterative_GFG(Tree::Node* root) {
	if(root == NULL)
		return;
	
	std::stack<Tree::Node*> prev_root;

	while(root != NULL || prev_root.empty() == false) {
		while(root != NULL) {
			std::cout << root->m_data << "\t";

			if(root->m_right != NULL)
				prev_root.push(root->m_right);

			root = root->m_left;
		}

		if(prev_root.empty() == false) {
			root = prev_root.top();
			prev_root.pop();
		}
	}
}