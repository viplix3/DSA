#include "circular_linked_list.hpp"

int main() {

	circular_ll::Node *head_ptr = NULL;
	circular_ll::printList(head_ptr);

	head_ptr = circular_ll::insert_at_begin(head_ptr, 30);
	circular_ll::printList(head_ptr);
	head_ptr = circular_ll::insert_at_begin(head_ptr, 20);
	circular_ll::printList(head_ptr);
	head_ptr = circular_ll::insert_at_begin(head_ptr, 10);
	circular_ll::printList(head_ptr);


	return EXIT_SUCCESS;
}