#include <tree.h>
using namespace std;

int main() {
	Tree::Node *root_ptr = NULL;

	root_ptr = new Tree::Node(10);
	Tree::insert_left(root_ptr, new Tree::Node(20));
	Tree::insert_right(root_ptr, new Tree::Node(30));
	Tree::insert_left(root_ptr->m_left, new Tree::Node(40));
	Tree::insert_right(root_ptr->m_left, new Tree::Node(50));
	Tree::insert_right(root_ptr->m_right, new Tree::Node(70));
	Tree::insert_right(root_ptr->m_right->m_right, new Tree::Node(80));
	cout << "\nTree created" << endl << endl;

	cout << "In-order traversal of tree:\t";
	Tree::inOrder_traversal(root_ptr);
	cout << endl;

	cout << "Pre-order traversal of tree:\t";
	Tree::preOrder_traversal(root_ptr);
	cout << endl;

	cout << "Post-order traversal of tree:\t";
	Tree::postOrder_traversal(root_ptr);
	cout << endl;

	cout << endl;
	cout << "Tree height: " << Tree::getTreeHeight(root_ptr);
	cout << endl;

	cout << endl;
	cout << "Level print" << endl;
	cout << "0th Level of tree:\t";
	Tree::printKthLevel(root_ptr, 0);
	cout << endl;
	cout << "1st Level of tree:\t";
	Tree::printKthLevel(root_ptr, 1);
	cout << endl;
	cout << "2nd Level of tree:\t";
	Tree::printKthLevel(root_ptr, 2);
	cout << endl;
	cout << "3rd Level of tree:\t";
	Tree::printKthLevel(root_ptr, 3);
	cout << endl;

	cout << endl;
	cout << "Lever order traversal (BFS):\t";
	Tree::levelOrder_traversal(root_ptr);
	cout << endl;

	cout << endl;
	cout << "Lever order traversal (BFS), level per line" << endl;
	Tree::levelOrder_lineByLine(root_ptr);
	cout << endl;

	return EXIT_SUCCESS;
}