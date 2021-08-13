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