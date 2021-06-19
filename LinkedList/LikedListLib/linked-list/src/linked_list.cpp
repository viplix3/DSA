#include "linked_list.hpp"

void linked_list::printList(Node* head_ptr) {
	if(head_ptr != NULL){
		std::cout << "Linked list contents: ";

		std::cout << head_ptr->data;
		while(head_ptr->next != NULL){
			head_ptr = head_ptr -> next;
			std::cout << " -> " << head_ptr->data;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "Empty Linked list" << std::endl;
}

linked_list::Node* linked_list::insert_at_begin(Node* head_ptr, int data) {
	linked_list::Node *temp = new linked_list::Node(data);
	temp->next = head_ptr;
	return temp;
}

linked_list::Node* linked_list::insert_at_end(Node* head_ptr, int data) {
	linked_list::Node *temp = new linked_list::Node(data);

	if(head_ptr == NULL)
		return temp;
	
	linked_list::Node *curr_ptr = head_ptr;
	while(curr_ptr->next != NULL)
		curr_ptr = curr_ptr->next;

	curr_ptr->next = temp;
	return head_ptr;
}

linked_list::Node* linked_list::delete_head(Node* head_ptr) {
	if(head_ptr == NULL) {
		std::cerr << "List is empty" << std::endl;
		return head_ptr;
	}
	
	linked_list::Node *new_head = head_ptr->next;
	delete head_ptr;
	return new_head;
}

linked_list::Node* linked_list::delete_tail(Node* head_ptr) {
	if(head_ptr == NULL) {
		std::cerr << "List is empty" << std::endl;
		return head_ptr;
	}

	if(head_ptr->next == NULL) {
		delete head_ptr;
		return NULL;
	}

	linked_list::Node *curr_head = head_ptr;

	while(curr_head->next->next != NULL)
		curr_head = curr_head->next;

	linked_list::Node *deleted_node = curr_head->next;
	curr_head->next = NULL;
	delete deleted_node;

	return head_ptr;
}