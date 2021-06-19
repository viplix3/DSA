#include <circular_linked_list.hpp>

void circular_ll::printList(Node* head_ptr) {
	if(head_ptr != NULL){

		circular_ll::Node *curr_head = head_ptr;
		std::cout << "Linked list contents: ";

		std::cout << "[begin]" << curr_head->data;
		while(curr_head->next != head_ptr){
			curr_head = curr_head -> next;
			std::cout << " -> " << curr_head->data;
		}
		std::cout << " ->[begin]" << std::endl;
	}
	else
		std::cout << "Empty Linked list" << std::endl;
}

circular_ll::Node* circular_ll::insert_at_begin(Node* head_ptr, int data) {
	circular_ll::Node *temp = new circular_ll::Node(data);

	if(head_ptr == NULL) {
		temp->next = temp;
		return temp;
	}

	circular_ll::Node *curr_head = head_ptr;
	temp->next = curr_head;
	while(curr_head->next != head_ptr)
		curr_head = curr_head->next;
	curr_head->next = temp;

	return temp;
}