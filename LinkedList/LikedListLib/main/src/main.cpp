#include "linked_list.hpp"

int main(){

	linked_list::Node *head_ptr = NULL;
	linked_list::printList(head_ptr);

	std::cout << "\nInserting at beginning of linked list" << std::endl;
	head_ptr = linked_list::insert_at_begin(head_ptr, 30);
	head_ptr = linked_list::insert_at_begin(head_ptr, 20);
	head_ptr = linked_list::insert_at_begin(head_ptr, 10);
	linked_list::printList(head_ptr);

	std::cout << "\nInserting at end of linked list" << std::endl;
	head_ptr = linked_list::insert_at_end(head_ptr, 40);
	head_ptr = linked_list::insert_at_end(head_ptr, 50);
	head_ptr = linked_list::insert_at_end(head_ptr, 60);
	linked_list::printList(head_ptr);

	std::cout << "\nInserting at end of linked list when list is empty" << std::endl;
	linked_list::Node *temp_ptr = NULL;
	temp_ptr = linked_list::insert_at_end(temp_ptr, 90);
	linked_list::printList(temp_ptr);
	std::cout << "Deleting the fist node of the linked list with ";
	linked_list::printList(temp_ptr);
	temp_ptr = linked_list::delete_first_node(temp_ptr);
	std::cout << "Linked list after deleting first node: ";
	linked_list::printList(temp_ptr);

	std::cout << "\nDeleting the fist node of the linked list with ";
	linked_list::printList(head_ptr);
	head_ptr = linked_list::delete_first_node(head_ptr);
	std::cout << "Linked list after deleting first node" << std::endl;
	linked_list::printList(head_ptr);

	return EXIT_SUCCESS;
}