#include "tree.h"
#include <climits>
#include <queue>
#include <math.h>

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

bool Tree::childrenSumProperty(Node* root) {
	if(root == NULL)
		return true;
	
	if(root->m_left == NULL && root->m_right == NULL)
		return true;

	int sum = root->m_data;

	if(root->m_left != NULL)
		sum -= root->m_left->m_data;
	if(root->m_right != NULL)
		sum -= root->m_right->m_data;
	
	return (
			sum == 0 &&
			childrenSumProperty(root->m_left) &&
			childrenSumProperty(root->m_right)
			);
}

int Tree::isHeightBalanced(Node* root) {
	if(root == NULL)
		return 0;

	int leftHeight = isHeightBalanced(root->m_left);
	if(leftHeight == -1)
		return -1;

	int rightHeight = isHeightBalanced(root->m_right);
	if(rightHeight == -1)
		return -1;

	if(abs(leftHeight - rightHeight) > 1)
		return -1;
	else
		return std::max(leftHeight, rightHeight) + 1;
}

int Tree::getMaxWidth(Node* root) {
	if(root == NULL)
		return 0;

	std::queue<Node*> treeLevelNodes;
	treeLevelNodes.push(root);
	int maxWidth = INT_MIN;

	while(treeLevelNodes.empty() == false) {
		int currLevelWidth = treeLevelNodes.size();
		maxWidth = std::max(maxWidth, currLevelWidth);

		for(int i=0; i<currLevelWidth; i++) {
			Tree::Node* curr_node = treeLevelNodes.front();
			treeLevelNodes.pop();

			if(curr_node->m_left != NULL)
				treeLevelNodes.push(curr_node->m_left);

			if(curr_node->m_right != NULL)
				treeLevelNodes.push(curr_node->m_right);
		}
	}
	return maxWidth;
}

void BTree2DLL(Tree::Node* root, Tree::Node** DLL_headRef, Tree::Node** DLL_tailRef) {
	if(root == NULL)
		return;


	BTree2DLL(root->m_left, DLL_headRef, DLL_tailRef);

	if(*DLL_headRef == NULL) {
		*DLL_headRef = *DLL_tailRef = root;
	}
	else {
		(*DLL_tailRef)->m_right = root;
		root->m_left = *DLL_tailRef;
		*DLL_tailRef = (*DLL_tailRef)->m_right;
	}

	BTree2DLL(root->m_right, DLL_headRef, DLL_tailRef);
}

Tree::Node* Tree::binaryTree2DLL(Node* root) {
	Tree::Node *DLL_head, *DLL_tail;
	DLL_head = DLL_tail = NULL;

	BTree2DLL(root, &DLL_head, &DLL_tail);
	return DLL_head;
}

Tree::Node* buildTree(int inOrder[], int preOrder[], int startIdx, int endIdx, int &currNodeIdx_preOrder) {
	if(startIdx > endIdx)
		return NULL;

	Tree::Node *currRoot = new Tree::Node(preOrder[currNodeIdx_preOrder]);
	currNodeIdx_preOrder += 1;

	int currNodeIdx_inOrder;
	for(int i=startIdx; i <= endIdx; i++) {
		if(inOrder[i] == currRoot->m_data) {
			currNodeIdx_inOrder = i;
			break;
		}
	}

	currRoot->m_left = buildTree(inOrder, preOrder, startIdx, currNodeIdx_inOrder-1, currNodeIdx_preOrder);
	currRoot->m_right = buildTree(inOrder, preOrder, currNodeIdx_inOrder+1, endIdx, currNodeIdx_preOrder);
	return currRoot;
}

Tree::Node* Tree::constructTree(int inOrder[], int preOrder[], int numNodes) {
	int currNodeIdx = 0;

	Tree::Node* tree_root = buildTree(inOrder, preOrder, 0, numNodes-1, currNodeIdx);
	return tree_root;
}

int getHeightForDiameter(Tree::Node* root, int &maxDiameter) {
	if(root == NULL)
		return 0;
	
	int leftHeight = getHeightForDiameter(root->m_left, maxDiameter);
	int rightHeight = getHeightForDiameter(root->m_right, maxDiameter);

	// Check and update max diameter considering current node
	maxDiameter = std::max(1+leftHeight+rightHeight, maxDiameter);
	// Return height from the function
	return 1 + std::max(leftHeight, rightHeight);
}

int Tree::getDiameter(Node* root) {
	if(root == NULL)
		return 0;
	
	int diameter = 0;
	return (getHeightForDiameter(root, diameter));
}

int burnTreeFromLeaf(Tree::Node* root, int nodeData, int &currDistance, int &maxTimeToBurn) {
	if(root == NULL)
		return 0;

	if(root->m_data == nodeData) {
		currDistance = 0;
		return 1;
	}
	
	int currLeftHeight = -1, currRightHeight = -1; // Assuming no branch contains the burning leaf node
	int leftHeight = burnTreeFromLeaf(root, nodeData, currLeftHeight, maxTimeToBurn); // +ve if left sub-tree contains burning leaf node
	int rightHeight = burnTreeFromLeaf(root, nodeData, currRightHeight, maxTimeToBurn); // +ve if right sub-tree contains burning leaf node

	// If left sub-tree contains the burning leaf node, currLeftHeight would be changed to the distance of burning
	// left node from current root node in the recursive call done to find height
	if(currLeftHeight != -1) {
		currDistance = currLeftHeight + 1;
		maxTimeToBurn = std::max(currDistance + rightHeight, maxTimeToBurn);
	}
	else if(currRightHeight != -1) { // If right sub-tree containins the burning leaf node, currRightHeight would be changed to the distance
		currDistance = currRightHeight + 1;
		maxTimeToBurn = std::max(currDistance + leftHeight, maxTimeToBurn);
	}

	return (std::max(leftHeight, rightHeight) + 1);
}

int Tree::timeToBurnTree(Node* root, int nodeData) {
	if(root == NULL)
		return -1;
	
	int timeToBurn = 0;
	int currDistance = -1;
	burnTreeFromLeaf(root, nodeData, currDistance, timeToBurn);
	return timeToBurn;
}

int Tree::countNodes_perfectBinaryTree(Node* root) {
	int leftHeight = 0, rightHeight = 0;

	// Get left height
	Tree::Node *curr = root;
	while(curr != NULL) {
		leftHeight += 1;
		curr = curr->m_left;
	}

	// Get right height
	curr = root;
	while(curr != NULL) {
		rightHeight += 1;
		curr = curr->m_right;
	}

	if(leftHeight == rightHeight)
		return pow(2, leftHeight) - 1;
	
	return (1 + countNodes_perfectBinaryTree(root->m_left) + 
			countNodes_perfectBinaryTree(root->m_right));
}