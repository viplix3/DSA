#include<bits/stdc++.h>
using namespace std;

namespace AVL {

	struct Node {
		int data;
		Node *left, *right;
		int height; 

		Node(int x) // new node is always added at leaf, so height is 1
			: data(x), left(NULL), right(NULL), height(1)
		{}
	};


	int height(Node *root) {
		if(root == NULL)
			return 0;
		return root->height;
	}


	int getBalanceFactor(Node* root) {
		if(root == NULL)
			return 0;
		return height(root->left) - height(root->right);
	}


	Node* leftRotate(Node *x) {
		// Get hold of child nodes to be used for rotation
		Node *y = x->right;
		Node *T2 = y->left;

		// Rotations
		y->left = x;
		x->right = T2;

		// Update the height with added new nodes
		x->height = std::max(height(x->left),
							height(x->right)) + 1;
		y->height = std::max(height(y->left),
							height(y->right)) + 1;
						
		// New node which is in the place of x now
		return y;
	}


	Node* rightRotate(Node *y) {
		// Get hold of child nodes to be used for rotation
		Node *x = y->left;
		Node *T2 = x->right;

		// Rotations
		x->right = y;
		y->left = T2;

		// Update the height with added new nodes
		x->height = std::max(height(x->left),
							height(x->right)) + 1;
		y->height = std::max(height(y->left),
							height(y->right)) + 1;
						
		// New node which is in the place of x now
		return x;
	}


	Node* insert(Node* root, int key) {
		if(root == NULL)
			return (new Node(key));
		
		if(root->data < key)
			root->right = insert(root->right, key);
		else if(root->data > key)
			root->left = insert(root->left, key);
		else
			return root;

		// Update height of the current node
		root->height = std::max(height(root->left),
								height(root->right)) + 1;

		int balance_factor = getBalanceFactor(root);

		// Left-Left case
		if(balance_factor > 1 && root->left->data > key)
			return rightRotate(root);

		// Right-Right case
		if(balance_factor < -1 && root->right->data < key)
			return leftRotate(root);

		// Left-Right case
		if(balance_factor > 1 && root->left->data < key) {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}

		// Right-Left case
		if(balance_factor < -1 && root->right->data > key) {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
	}


	bool search(Node* root, int key) { // Same as BST
		while(root != NULL) {
			if(root->data == key)
				return true;
			else if(root->data < key)
				root = root->right;
			else if(root->data > key)
				root = root->left;
		}
		return false;
	}


	void printInOrder(Node* root) { // Same as BST
		if(root == NULL)
			return;
		
		printInOrder(root->left);
		std::cout << root->data << "\t";
		printInOrder(root->right);
	}
}

int main() {
	AVL::Node *root = NULL;

	root = AVL::insert(root, 10);
	root = AVL::insert(root, 20);
	root = AVL::insert(root, 30);
	root = AVL::insert(root, 40);
	root = AVL::insert(root, 50);
	root = AVL::insert(root, 25);

	cout << "InOrder traversal of created AVL tree" << endl;
	AVL::printInOrder(root);
	cout << endl;

	return 0;
}