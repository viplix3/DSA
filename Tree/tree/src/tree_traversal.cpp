#include "tree.h"

void Tree::inOrder_traversal(Node* root)
{
	if(root == NULL)
		return;

	inOrder_traversal(root->m_left);
	std::cout << root->m_data << " ";
	inOrder_traversal(root->m_right);
}