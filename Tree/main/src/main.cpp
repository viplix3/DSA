#include <tree.h>
using namespace std;

int main() {
	Tree::Node *root_ptr = NULL;

	root_ptr = new Tree::Node(10);
	Tree::insert_left(root_ptr, new Tree::Node(20));
	Tree::insert_right(root_ptr, new Tree::Node(30));
	Tree::insert_left(root_ptr->m_right, new Tree::Node(40));
	Tree::insert_right(root_ptr->m_right, new Tree::Node(50));
	cout << "\nTree created" << endl;

	cout << "In-order traversal of tree:\t";
	Tree::inOrder_traversal(root_ptr);
	cout << endl;

	cout << "Pre-order traversal of tree:\t";
	Tree::preOrder_traversal(root_ptr);
	cout << endl;

	cout << "Post-order traversal of tree:\t";
	Tree::postOrder_traversal(root_ptr);
	cout << endl;

	cout << "Tree height: " << Tree::getTreeHeight(root_ptr);
	cout << endl;


	return EXIT_SUCCESS;
}