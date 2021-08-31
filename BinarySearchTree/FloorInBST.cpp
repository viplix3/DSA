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

	int getFloor(Node* root, int data) {
		int floor = -1;

		while(root != NULL) {
			if(root->data == data)
				return root->data;
			else if(root->data > data)
				root = root->left;
			else {
				floor = root->data;
				root = root->right;
			}
		}

		return floor;
	}
}

int main() {
	BST::Node *root = NULL;
	int search_data, floor_value;

	root = BST::insert(root, 10);
	root = BST::insert(root, 5);
	root = BST::insert(root, 15);
	root = BST::insert(root, 12);
	root = BST::insert(root, 30);

	search_data = 12;
	floor_value = BST::getFloor(root, search_data);
	if(floor_value == -1)
		cout << "Floor for value " << search_data << " doesn't exist" << endl;
	else
		cout << "Floor for value " << search_data << " in the provided BST: " << floor_value << endl;

	search_data = 4;
	floor_value = BST::getFloor(root, search_data);
	if(floor_value == -1)
		cout << "Floor for value " << search_data << " doesn't exist" << endl;
	else
		cout << "Floor for value " << search_data << " in the provided BST: " << floor_value << endl;

	search_data = 30;
	floor_value = BST::getFloor(root, search_data);
	if(floor_value == -1)
		cout << "Floor for value " << search_data << " doesn't exist" << endl;
	else
		cout << "Floor for value " << search_data << " in the provided BST: " << floor_value << endl;

	search_data = 100;
	floor_value = BST::getFloor(root, search_data);
	if(floor_value == -1)
		cout << "Floor for value " << search_data << " doesn't exist" << endl;
	else
		cout << "Floor for value " << search_data << " in the provided BST: " << floor_value << endl;

	return 0;
}