#include<bits/stdc++.h>
using namespace std;

/*
If we use self-balancing BST
	- Insert: O(log(N))
	- Search: O(log(N))
	- Delete: O(log(N))
	- Naive Kth smallest (inOrder traversal): O(H + K), H -> tree height

We need to make Kth smallest search O(log(N))
*/

namespace aug_BST {

	struct Node {
		int data;
		int leftNodeCount;
		Node *left, *right;

		Node(int x)
			: data(x), leftNodeCount(0), left(NULL), right(NULL)
		{}
	};

	Node* insert(Node* root, int x) {
		if(root == NULL)
			return new Node(x);
		
		if(root->data < x)
			root->right = insert(root->right, x);
		else if(root->data > x) {
			root->left = insert(root->left, x);
			root->leftNodeCount += 1;
		}
		else
			return root;
		return root;
	}

	Node* getSuccessor(Node* root) { // Returns the inOrder successfor of provided node
		root = root->right; // InOrder successfor will be leftmost leaf node of right child
		while(root != NULL && root->left != NULL)
			root = root->left;
		return root;
	}

	Node* delete_node(Node* root, int key) {
		if(root == NULL)
			return NULL;
		
		if(root->data > key) { // Node to be deleted is in the right sub-tree
			root->left = delete_node(root->left, key); // Connect right sub-tree to current root after deletion
			if(root->leftNodeCount != 0)
				root->leftNodeCount -= 1;
		}
		else if(root->data < key) // Node to be deleted is in the left sub-tree
			root->right = delete_node(root->right, key); // Connect left sub-tree to current root after deletion
		else { // Root is the current node to be deleted
			if(root->left == NULL) { // Root is having a single child
				Node *right_node = root->right;
				delete root;
				return right_node; // For connecting to the ancestor
			}
			else if(root->right == NULL) { // Root is having a single child
				Node *left_node = root->left;
				if(left_node->leftNodeCount != 0)
					left_node->leftNodeCount -= 1;
				delete root;
				return left_node; // For conncting to th ancestor
			}
			else { // Root is having multiple children
				Node *root_succeessor = getSuccessor(root); // Get the inOrder successor of the current root
				root->data = root_succeessor->data; // Swap the data with root
				root->right = delete_node(root->right, root_succeessor->data); // Delete the successor
			}
		}
		return root;
	}

	bool search(Node* root, int key) {
		if(root == NULL)
			return false;
		
		while(root != NULL) {
			if(root->data == key)
				return true;
			if(root->data < key)
				root = root->right;
			else
				root = root->left;
		}
		return false;
	}

	Node* getKthLargest(Node* root, int K) {
		if(root == NULL)
			return NULL;
		
		if(K == (root->leftNodeCount + 1)) // Root is the kth largest element
			return root;
		if(K < (root->leftNodeCount + 1))
			getKthLargest(root->left, K);
		else
			getKthLargest(root->right, (K - root->leftNodeCount - 1));
	}

	void printInOrder(Node* root) {
		if(root == NULL)
			return;
		
		printInOrder(root->left);
		std::cout << "Data:  " << root->data << "\tLeft node count: " << root->leftNodeCount << endl;
		printInOrder(root->right);
	}
}

int main() {
	aug_BST::Node *root = NULL;
	root = aug_BST::insert(root, 50);
	root = aug_BST::insert(root, 20);
	root = aug_BST::insert(root, 100);
	root = aug_BST::insert(root, 10);
	root = aug_BST::insert(root, 40);
	root = aug_BST::insert(root, 70);
	root = aug_BST::insert(root, 120);
	root = aug_BST::insert(root, 4);
	root = aug_BST::insert(root, 60);
	root = aug_BST::insert(root, 80);

	std::cout << "InOrder traversal of created BST" << std::endl;
	aug_BST::printInOrder(root);

	int data = 60;
	std::cout << "\nDeleting node " << data << endl;
	aug_BST::delete_node(root, data);
	std::cout << "InOrder traversal of BST after deleting" << std::endl;
	aug_BST::printInOrder(root);

	std::cout << "\n7th smallest element in BST: " << aug_BST::getKthLargest(root, 7)->data << endl;


	return 0;
}