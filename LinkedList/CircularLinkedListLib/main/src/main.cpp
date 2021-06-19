#include "circular_linked_list.hpp"

int main() {

	circular_ll::Node *head_ptr = NULL;
	circular_ll::printList(head_ptr);

	// Insert at begin
	std::cout << "\nInserting at the starting of circular linked list" << std::endl;
	head_ptr = circular_ll::insert_at_begin(head_ptr, 30);
	head_ptr = circular_ll::insert_at_begin(head_ptr, 20);
	head_ptr = circular_ll::insert_at_begin(head_ptr, 10);
	circular_ll::printList(head_ptr);

	// Insert at end
	std::cout << "\nInserting at the ending of circular linked list" << std::endl;
	head_ptr = circular_ll::insert_at_end(head_ptr, 40);
	head_ptr = circular_ll::insert_at_end(head_ptr, 50);
	head_ptr = circular_ll::insert_at_end(head_ptr, 60);
	circular_ll::printList(head_ptr);

	return EXIT_SUCCESS;
}