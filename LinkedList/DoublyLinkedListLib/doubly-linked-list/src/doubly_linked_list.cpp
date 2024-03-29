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

doubly_ll::Node* doubly_ll::insert_at_end(Node* head_ptr, int data){
	doubly_ll::Node *temp = new Node(data);

	if(head_ptr == NULL)
		return temp;

	doubly_ll::Node *curr_head = head_ptr;

	while(curr_head->next != NULL)
		curr_head = curr_head->next;

	temp->prev = curr_head;
	curr_head->next = temp;
	return head_ptr;
}

doubly_ll::Node* doubly_ll::reverse(Node* head_ptr) {
	if(head_ptr == NULL || head_ptr->next == NULL)
		return head_ptr;

	doubly_ll::Node *curr_head = head_ptr, *prev_node = NULL;
	while(curr_head != NULL){
		prev_node = curr_head->prev;
		curr_head->prev = curr_head->next;
		curr_head->next = prev_node;
		curr_head = curr_head->prev;
	}
	return prev_node->prev;
}

doubly_ll::Node* doubly_ll::delete_head(Node* head_ptr) {
	if(head_ptr == NULL) {
		std::cerr << "\nEmpty linked list" << std::endl;
		return head_ptr;
	}

	if(head_ptr->next == NULL){
		delete head_ptr;
		return NULL;
	}

	doubly_ll::Node *deleted_node = head_ptr;
	head_ptr = head_ptr->next;
	head_ptr->prev = NULL;
	delete deleted_node;
	return head_ptr;
}

doubly_ll::Node* doubly_ll::delete_tail(Node* head_ptr) {
	if(head_ptr == NULL) {
		std::cerr << "\nEmpty linked list" << std::endl;
		return head_ptr;
	}

	if(head_ptr->next == NULL){
		delete head_ptr;
		return NULL;
	}

	doubly_ll::Node *curr_head = head_ptr, *deleted_node = NULL;

	while(curr_head->next->next != NULL)
		curr_head = curr_head->next;
	
	deleted_node = curr_head->next;
	curr_head->next = NULL;
	delete deleted_node;
	return head_ptr;
}