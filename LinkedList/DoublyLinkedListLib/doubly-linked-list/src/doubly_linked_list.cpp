#include "doubly_linked_list.hpp"

void doubly_ll::printList(Node* head_ptr) {
	if(head_ptr != NULL){
		std::cout << "Linked list contents: ";

		std::cout << head_ptr->data;
		while(head_ptr->next != NULL){
			head_ptr = head_ptr -> next;
			std::cout << " <-> " << head_ptr->data;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "Empty Linked list" << std::endl;
}

doubly_ll::Node* doubly_ll::insert_at_begin(Node* head_ptr, int data) {
	doubly_ll::Node *temp = new Node(data);

	temp->next = head_ptr;
	if(head_ptr != NULL)
		head_ptr->prev = temp;

	return temp;
}