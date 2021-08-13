#pragma once

#include <iostream>
#include <stdlib.h>

namespace Tree {

	struct Node {
		int m_data;
		Node *m_left, *m_right;

		Node(int data)
			:m_data(data), m_left(NULL), m_right(NULL)
		{}
	};

	// Data insertion
	void insert_left(Node* parent, Node* node);
	void insert_right(Node* parent, Node* node);

	// Tree traversals
	void inOrder_traversal(Node* root_ptr);

}