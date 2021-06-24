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

linked_list::Node* linked_list::insert_at_pos(Node* head_ptr, int data, int insert_pos) {
	if(insert_pos < 0) {
		std::cerr << "Invalid position" << std::endl;
		return head_ptr;
	}

	linked_list::Node *temp_node = new Node(data);

	if(insert_pos == 1) {
		temp_node->next = head_ptr;
		return temp_node;
	}

	linked_list::Node* curr_head = head_ptr;
	int curr_pos = 1;

	while((curr_pos+1 != insert_pos) && (curr_head->next != NULL)) {
		curr_head = curr_head->next;
		curr_pos += 1;
	}

	if(curr_pos+1 == insert_pos) {
		temp_node->next = curr_head->next;
		curr_head->next = temp_node;
	}
	else
		std::cerr << "Invalid position" << std::endl;

	return head_ptr;
}

linked_list::Node* linked_list::sorted_insert(Node* head_ptr, int data) {
	linked_list::Node *temp = new linked_list::Node(data);

	if(head_ptr == NULL)
		return temp;

	if(head_ptr->data > data) {
		temp->next = head_ptr;
		return temp;
	}

	linked_list::Node *curr_head = head_ptr;
	while((curr_head->next != NULL) && (curr_head->next->data < data)) {
		curr_head = curr_head->next;
	}

	temp->next = curr_head->next;
	curr_head->next = temp;
	return head_ptr;
}

linked_list::Node* linked_list::delete_head(Node* head_ptr) {
	if(head_ptr == NULL) {
		std::cerr << "List is empty" << std::endl;
		return head_ptr;
	}
	
	if(head_ptr->next == NULL) {
		delete head_ptr;
		return NULL;
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

int linked_list::search_key(Node* head_ptr, int key) {
	int res_idx = 1;

	while(head_ptr != NULL) {
		if(head_ptr -> data == key)
			return res_idx;
		
		res_idx += 1;
		head_ptr = head_ptr->next;
	}

	std::cerr << "Element " << key << " is not present in the given linked list" << std::endl;
	return -EXIT_FAILURE;
}

int linked_list::get_middle(Node* head_ptr) {
	linked_list::Node *slow_ptr = head_ptr, *fast_ptr = head_ptr;

	while(fast_ptr != NULL && fast_ptr->next != NULL) {
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
	}

	int data = slow_ptr->data;
	return data;
}

int linked_list::getNth_from_end(Node* head_ptr, int pos_from_tail) {
	int list_len = 0;
	linked_list::Node* curr_head = head_ptr;

	for(curr_head; curr_head != NULL; curr_head = curr_head->next)
		list_len += 1;

	if(list_len < pos_from_tail) {
		std::cerr << "Invalid position" << std::endl;
		return -EXIT_FAILURE;
	}

	int pos_from_head = list_len - pos_from_tail + 1;
	curr_head = head_ptr;

	for(int i=1; i<pos_from_head; i++)
		curr_head = curr_head->next;
	
	return curr_head->data;
}

int linked_list::getNth_from_end(Node* head_ptr, int pos_from_tail, bool two_pointer) {
	if(!two_pointer)
		return linked_list::getNth_from_end(head_ptr, pos_from_tail);
	
	linked_list::Node *leading_pointer = head_ptr, *position_pointer = head_ptr;

	while((leading_pointer->next != NULL) && (pos_from_tail != 0)) {
		leading_pointer = leading_pointer->next;
		pos_from_tail -= 1;
	}

	if(pos_from_tail != 0) {
		std::cerr << "Invalid position" << std::endl;
		return -EXIT_FAILURE;
	}

	while(leading_pointer != NULL) {
		leading_pointer = leading_pointer->next;
		position_pointer = position_pointer->next;
	}

	return position_pointer->data;
}

linked_list::Node* linked_list::reverse(Node* head_ptr) {
	if(head_ptr == NULL) {
		std::cerr << "Empty list" << std::endl;
		return NULL;
	}

	if(head_ptr->next == NULL)
		return head_ptr;

	linked_list::Node *prev_node, *curr_node;

	prev_node = NULL;
	curr_node = head_ptr;

	while(curr_node != NULL) {
		linked_list::Node *next_node = curr_node->next;
		curr_node->next = prev_node;
		prev_node = curr_node;
		curr_node = next_node;
	}

	return prev_node;
}

linked_list::Node* linked_list::recusive_reverse(Node* head_ptr) {
	if(head_ptr == NULL) {
		std::cerr << "Empty list" << std::endl;
		return NULL;
	}

	if(head_ptr->next == NULL)
		return head_ptr;

	linked_list::Node *reverse_head = linked_list::recusive_reverse(head_ptr->next);
	linked_list::Node *reverse_tail = head_ptr->next;
	reverse_tail->next = head_ptr;
	head_ptr->next = NULL;
	return reverse_head;
}

linked_list::Node* linked_list::recusive_reverse(Node* prev_node, Node* head_ptr) {
	if(head_ptr == NULL && prev_node == NULL) {
		std::cerr << "Empty list" << std::endl;
		return NULL;
	}

	if(head_ptr == NULL && prev_node != NULL)
		return prev_node;

	if(head_ptr->next == NULL && prev_node == NULL)
		return head_ptr;
	
	linked_list::Node *next_node = head_ptr->next;
	head_ptr->next = prev_node;
	prev_node = head_ptr;
	head_ptr = next_node;
	linked_list::recusive_reverse(prev_node, head_ptr);
}

void linked_list::remove_duplicates_sorted(Node* head_ptr) {

	linked_list::Node *curr_head = head_ptr;
	while(curr_head != NULL && curr_head->next != NULL) {
		if(curr_head->data == curr_head->next->data) {
			linked_list::Node *repeated_node = curr_head->next;
			curr_head->next = curr_head->next->next;
			delete repeated_node;
		}
		else
			curr_head = curr_head->next;
	}
}

linked_list::Node* linked_list::reverse_in_groups(Node* head_ptr, int group_size) {
	if(head_ptr == NULL) {
		std::cerr << "Empty list" << std::endl;
		return NULL;
	}

	if(head_ptr->next == NULL)
		return head_ptr;

	linked_list::Node *prev_node, *curr_node;

	curr_node = head_ptr;

	bool is_first_pass = true;
	linked_list::Node *last_group_tail, *curr_group_tail;

	while(curr_node != NULL) {
		curr_group_tail = curr_node;
		prev_node = NULL;
		int items_reversed = 0;

		while(curr_node != NULL && items_reversed < group_size) {
			linked_list::Node *next_node = curr_node->next;
			curr_node->next = prev_node;
			prev_node = curr_node;
			curr_node = next_node;
			items_reversed += 1;
		}

		if(is_first_pass) {
			head_ptr = prev_node; // prev_node is current group head, if it is first pass, this will be head of list
			is_first_pass = false;
		}
		else
			last_group_tail->next = prev_node; // prev_node is current group head

		last_group_tail = curr_group_tail;
	}
	return head_ptr;
}

bool linked_list::detect_loop(Node* head_ptr) {
	linked_list::Node *slow_ptr, *fast_ptr;
	slow_ptr = fast_ptr = head_ptr;

	while(fast_ptr != NULL && fast_ptr->next != NULL) {
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;

		if(slow_ptr == fast_ptr)
			return true;
	}
	return false;
}

void linked_list::detect_and_remove_loop(Node* head_ptr) {
	linked_list::Node *slow_ptr, *fast_ptr;
	slow_ptr = fast_ptr = head_ptr;

	while(fast_ptr != NULL && fast_ptr->next != NULL) {
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next;

		if(slow_ptr == fast_ptr)
			break;
	}

	if(slow_ptr != fast_ptr)
		return;

	fast_ptr = head_ptr;
	while(slow_ptr->next != fast_ptr->next) {
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next;
	}
	slow_ptr->next = NULL;
}

void linked_list::delete_node_without_head(Node* ptr) {
	linked_list::Node *deleted_node = ptr->next;
	ptr->data = deleted_node->data;
	ptr->next = deleted_node->next;
	delete deleted_node;
}

linked_list::Node* linked_list::segregate_even_odd(Node* head_ptr) {
	linked_list::Node *even_start, *even_end, *odd_start, *odd_end;
	even_start = even_end = odd_start = odd_end = NULL;

	for(linked_list::Node *curr_node = head_ptr; curr_node != NULL; curr_node = curr_node->next) {
		int data = curr_node->data;

		if(data % 2 == 0) {
			if(even_start == NULL) {
				even_start = curr_node;
				even_end = curr_node;
			}
			else {
				even_end->next = curr_node;
				even_end = even_end->next;
			}
		}
		else {
			if(odd_start == NULL) {
				odd_start = curr_node;
				odd_end = curr_node;
			}
			else {
				odd_end->next = curr_node;
				odd_end = odd_end->next;
			}
		}
	}

	if(even_start == NULL || odd_start == NULL) // List contains either all odd or all even numbers
		return head_ptr;
	
	even_end->next = odd_start;
	odd_end->next = NULL;
	return even_start;
}

linked_list::Node* linked_list::find_intersection(Node* head_ptr_1, Node* head_ptr_2) {
	int len_list_1, len_list_2;
	len_list_1 = len_list_2 = 0;

	for(linked_list::Node *curr_head = head_ptr_1; curr_head != NULL; curr_head = curr_head->next)
		len_list_1 += 1;

	for(linked_list::Node *curr_head = head_ptr_2; curr_head != NULL; curr_head = curr_head->next)
		len_list_2 += 1;

	int num_common = abs(len_list_1 - len_list_2);
	linked_list::Node *longer_list_head = (len_list_1 > len_list_2) ? head_ptr_1 : head_ptr_2;
	linked_list::Node *shorter_list_head = (len_list_1 > len_list_2) ? head_ptr_2 : head_ptr_1;
	
	for(int i=0; i < num_common; i++)
		longer_list_head = longer_list_head->next;

	while(longer_list_head != NULL && shorter_list_head != NULL) {
		if(longer_list_head == shorter_list_head)
			return longer_list_head;

		longer_list_head = longer_list_head->next;
		shorter_list_head = shorter_list_head->next;
	}
	return NULL;
}