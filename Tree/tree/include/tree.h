#pragma once

#include <iostream>
#include <stdlib.h>
#include <vector>

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
	void preOrder_traversal(Node* root_ptr);
	void postOrder_traversal(Node* root_ptr);
	void levelOrder_traversal(Node* root_ptr);
	void spiralLevelOrder_traversal(Node* root_ptr);
	bool getNodePath(Node* root_ptr, int node_data, std::vector<Node*> &path);

	// Tree Properties
	int getTreeHeight(Node* root_ptr);
	int getSize(Node* root_ptr);
	int getMax(Node* root_ptr);
	bool childrenSumProperty(Node* root_ptr);
	int isHeightBalanced(Node* root_ptr);
	int getMaxWidth(Node* root_ptr);
	int getDiameter(Node* root_ptr);
	Node* getLCA_pathTracingMethod(Node* root_ptr, int node1_data, int node2_data);

	// Misc.
	void printKthLevel(Node* root_ptr, int level);
	void levelOrder_lineByLine(Node* root_ptr);
	void levelOrder_lineByLine_method2(Node* root_ptr);
	void printLeftView(Node* root_ptr);
	void printLeftView_recursive(Node* root_ptr);
	Node* binaryTree2DLL(Node* root_ptr); // DLL will be in inOrder traversal format
	Node* constructTree(int inOrder[], int preOrder[], int numNodes);

}