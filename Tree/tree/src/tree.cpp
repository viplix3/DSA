#include "tree.h"
#include <climits>

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


void Tree::printKthLevel(Node* root, int level) {
	if(root == NULL)
		return;

	if(level == 0) {
		std::cout << root->m_data << "\t";
		return;
	}

	printKthLevel(root->m_left, level-1);
	printKthLevel(root->m_right, level-1);
}

int Tree::getSize(Node* root) {
	if(root == NULL)
		return 0;
	
	return (1 + getSize(root->m_left)
				 + getSize(root->m_right));
}

int Tree::getMax(Node* root) {
	if(root == NULL)
		return INT_MIN;
	
	return std::max(root->m_data,
				std::max(getMax(root->m_left),
							getMax(root->m_right)));
}