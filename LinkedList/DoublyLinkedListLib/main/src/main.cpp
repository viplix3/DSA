#include "doubly_linked_list.hpp"

int main(){

	doubly_ll::Node *head_ptr = NULL;
	doubly_ll::printList(head_ptr);

	// Insert at head
	std::cout << "\nInserting at beginning of doubly linked list" << std::endl;
	head_ptr = doubly_ll::insert_at_begin(head_ptr, 30);
	head_ptr = doubly_ll::insert_at_begin(head_ptr, 20);
	head_ptr = doubly_ll::insert_at_begin(head_ptr, 10);
	doubly_ll::printList(head_ptr);

	return EXIT_SUCCESS;
}