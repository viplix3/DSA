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

	// Swap the data of head and temp, now head is effectively the new node
	data = head_ptr->data;
	head_ptr->data = temp->data;
	temp->data = data;

	return head_ptr;
}

circular_ll::Node* circular_ll::insert_at_end(Node* head_ptr, int data) {
	circular_ll::Node *temp = new circular_ll::Node(data);

	if(head_ptr == NULL) {
		temp->next = temp;
		return temp;
	}

	// Insert after head
	temp->next = head_ptr->next;
	head_ptr->next = temp;

	// Swap the data of head and temp
	data = head_ptr->data;
	head_ptr->data = temp->data;
	temp->data = data;
	
	// Now if we start treating temp address as head, above insertion is effectively at end
	return temp;
}

circular_ll::Node* circular_ll::delete_head(Node* head_ptr) {
	if(head_ptr == NULL) {
		std::cerr << "Empty linked list" << std::endl;
		return NULL;
	}

	if(head_ptr->next == head_ptr) {
		delete head_ptr;
		return NULL;
	}

	head_ptr->data = head_ptr->next->data;
	circular_ll::Node *deleted_node = head_ptr->next;
	head_ptr->next = head_ptr->next->next;
	delete deleted_node;

	return head_ptr;
}

circular_ll::Node* circular_ll::delete_at_pos(Node* head_ptr, int del_pos) {
	if(del_pos < 0 || head_ptr == NULL) {
		std::cerr << "Invalid operation" << std::endl;
		return head_ptr;
	}

	if(del_pos == 1)
		return circular_ll::delete_head(head_ptr);

	circular_ll::Node *curr_head = head_ptr;
	int curr_pos = 1;

	while(curr_pos != del_pos-1) {
		curr_pos += 1;
		curr_head = curr_head->next;
	}

	circular_ll::Node *deleted_node = curr_head->next;
	curr_head->next = curr_head->next->next;

	if(deleted_node == head_ptr)
		head_ptr = head_ptr->next;

	delete deleted_node;

	return head_ptr;
}