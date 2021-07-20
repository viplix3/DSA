#pragma once 

#include <iostream>
#include <stdlib.h>

namespace linked_list{

struct Node{
	int data;
	Node* next;

	Node(int data_){
		data = data_;
		next = NULL;
	}
};

void printList(Node*);

Node* insert_at_begin(Node* head_pointer, int data);
Node* insert_at_end(Node* head_pointer, int data);
Node* insert_at_pos(Node* head_pointer, int data, int position);
Node* sorted_insert(Node* head_pointer, int data);

Node* delete_head(Node* head_pointer);
Node* delete_tail(Node* head_pointer);

int search_key(Node* head_pointer, int search_key);
int get_middle(Node* hed_pointer);
int getNth_from_end(Node* head_pointer, int position_from_tail);
int getNth_from_end(Node* head_pointer, int position_from_tail, bool use_two_pointer_approach);

Node* reverse(Node* head_pointer);
Node* recusive_reverse(Node* head_pointer);
Node* recusive_reverse(Node* previous_node_pointer, Node* head_pointer);
Node* reverse_in_groups(Node* head_pointer, int group_size);
void remove_duplicates_sorted(Node* head_pointer);
bool detect_loop(Node* head_pointer);
void detect_and_remove_loop(Node* head_pointer);
void delete_node_without_head(Node* node_pointer);
Node* segregate_even_odd(Node* head_pointer);
Node* find_intersection(Node* list_1_head_pointer, Node* list_2_head_pointer);
Node* pairwise_swap(Node* head_pointer);
Node* merge_sorted_lists(Node* list_1_head_pointer, Node* list_2_head_pointer);
bool is_palindrome(Node* head_pointer);

// Overloaded for cout
std::ostream& operator<<(std::ostream&, const linked_list::Node*);

};