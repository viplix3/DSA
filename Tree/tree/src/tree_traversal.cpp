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