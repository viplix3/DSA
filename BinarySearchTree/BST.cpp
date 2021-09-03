#include <bits/stdc++.h>
using namespace std;

namespace BST {

	struct Node {
		int data;
		Node *left, *right;

		Node(int x)
			: data(x), left(NULL), right(NULL)
		{}
	};


	bool search(Node* root, int key) {
		while(root != NULL) {
			if(root->data == key)
				return true;

			else if (root->data > key)
				root = root->left;
			else
				root = root->right;
		}

		return false;
	}


	bool search_recursive(Node* root, int key) {
		if(root == NULL)
			return false;
		
		if(root->data == key)
			return true;
		
		if(root->data > key)
			search(root->left, key);
		else
			search(root->right, key);
	}


	Node* insert(Node* root, int data) {
		Node *new_node = new Node(data);

		if(root == NULL)
			return new_node;

		Node *curr = root, *prev = NULL;

		while(curr != NULL) {
			if(curr-> data == new_node->data)
				break;

			prev = curr;

			if(curr->data < new_node->data)
				curr = curr->right;
			else
				curr = curr->left;
		}

		if(prev == NULL)
			return root;
		
		else if(prev->data < new_node->data)
			prev->right = new_node;
		else
			prev->left = new_node;

		return root;
	}

	Node* get_successor(Node* root) {
		root = root->right;
		while(root != NULL && root->left != NULL)
			root = root->left;
		return root;
	}

	Node* delete_node(Node* root, int key) {
		if(root == NULL)
			return NULL;

		if(root->data > key)
			root->left = delete_node(root->left, key);
		else if(root->data < key)
			root->right = delete_node(root->right, key);
		else {
			if(root->left == NULL) { // Single child (right)
				Node *right_node = root->right;
				delete root;
				return right_node; // This will be linked to the parent of root which got deleted
			}
			else if(root->right == NULL) { // Single child (left)
				Node *left_node = root->left;
				delete root;
				return left_node; // This will be linked to the parent of root which got deleted
			}
			else { // Both left and right child of the node to be deleted exists
				// This will return the inOrder successor of the root node. This is leftmost child of the right node
				Node *successor = get_successor(root); 
				root->data = successor->data; // Replace root's data with successor's data
				root->right = delete_node(root->right, successor->data);
			}
		}
		return root;
	}

	void printInOrder(Node* root) {
		if(root == NULL)
			return;
		
		printInOrder(root->left);
		std::cout << root->data << "\t";
		printInOrder(root->right);
	}

}

int main() {
	BST::Node *root = NULL;
	int data;

	root = BST::insert(root, 10);
	root = BST::insert(root, 5);
	root = BST::insert(root, 15);
	root = BST::insert(root, 12);
	root = BST::insert(root, 18);

	cout << "Inorder traversal of created BST" << endl;
	BST::printInOrder(root);
	cout << endl;

	data = 10;
	if(BST::search(root, data))
		cout << data << " is present in given BST" << endl;
	else
		cout << data << " is not present in given BST" << endl;

	data = 20;
	if(BST::search_recursive(root, data))
		cout << data << " is not present in given BST" << endl;
	else
		cout << data << " is not present in given BST" << endl;

	data = 15;
	BST::delete_node(root, data);
	cout << "InOrder traversal of BST after deleting node " << data << endl;
	BST::printInOrder(root);
	cout << endl;

	return 0;
}