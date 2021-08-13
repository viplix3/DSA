#include "tree.h"

void Tree::insert_left(Node* parent, Node* node) {
	if(parent == NULL)
		return;

	while(parent->m_left != NULL)
		parent = parent->m_left;

	parent->m_left = node;
}

void Tree::insert_right(Node* parent, Node* node) {
	if(parent == NULL)
		return;
	
	while(parent->m_right != NULL)
		parent = parent->m_right;

	parent->m_right = node;
}

int Tree::getTreeHeight(Node* root) {
	if(root == NULL)
		return 0;
	
	return std::max(getTreeHeight(root->m_left),
				getTreeHeight(root->m_right))+1;
}