#include "tree.h"

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
	
	if(root->m_left == NULL && root->m_right == NULL) { // Leaf node
		std::cout << root->m_data << "\t";
		return;
	}

	int treeHeight = Tree::getTreeHeight(root);

	for(int i=0; i<treeHeight; i++)
		Tree::printKthLevel(root, i);
}