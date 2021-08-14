#include "tree.h"
#include <queue>

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