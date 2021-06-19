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

	// Insert after head
	temp->next = head_ptr->next;
	head_ptr->next = temp;

	// Swap the data of head and temp, how head is effectively the new node
	data = head_ptr->data;
	head_ptr->data = temp->data;
	temp->data = data;

	return head_ptr;
}