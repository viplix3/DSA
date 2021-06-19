#include "linked_list.hpp"

int main(){

	int insertion_position, insertion_data, search_data, search_idx;

	linked_list::Node *head_ptr = NULL;
	linked_list::printList(head_ptr);

	// Insert at head
	std::cout << "\nInserting at beginning of linked list" << std::endl;
	head_ptr = linked_list::insert_at_begin(head_ptr, 30);
	head_ptr = linked_list::insert_at_begin(head_ptr, 20);
	head_ptr = linked_list::insert_at_begin(head_ptr, 10);
	linked_list::printList(head_ptr);

	// Insert at tail
	std::cout << "\nInserting at end of linked list" << std::endl;
	head_ptr = linked_list::insert_at_end(head_ptr, 40);
	head_ptr = linked_list::insert_at_end(head_ptr, 50);
	head_ptr = linked_list::insert_at_end(head_ptr, 60);
	linked_list::printList(head_ptr);

	// Delete at head
	std::cout << "\nDeleting the fist node of the linked list with ";
	linked_list::printList(head_ptr);
	head_ptr = linked_list::delete_head(head_ptr);
	std::cout << "Linked list after deleting first node" << std::endl;
	linked_list::printList(head_ptr);

	// Delete at tail
	std::cout << "\nDeleting the last node of the linked list with ";
	linked_list::printList(head_ptr);
	head_ptr = linked_list::delete_tail(head_ptr);
	std::cout << "Linked list after deleting last node" << std::endl;
	linked_list::printList(head_ptr);

	// Insert at pos
	insertion_position = 1;
	insertion_data = 10;
	std::cout << "\nInserting " << insertion_data << " at position " << insertion_position << std::endl;
	head_ptr = linked_list::insert_at_pos(head_ptr, insertion_data, insertion_position);
	std::cout << "Linked list after insertion" << std::endl;
	linked_list::printList(head_ptr);

	insertion_position = 4;
	insertion_data = 35;
	std::cout << "\nInserting " << insertion_data << " at position " << insertion_position << std::endl;
	head_ptr = linked_list::insert_at_pos(head_ptr, insertion_data, insertion_position);
	std::cout << "Linked list after insertion" << std::endl;
	linked_list::printList(head_ptr);

	insertion_position = 7;
	insertion_data = 55;
	std::cout << "\nInserting " << insertion_data << " at position " << insertion_position << std::endl;
	head_ptr = linked_list::insert_at_pos(head_ptr, insertion_data, insertion_position);
	std::cout << "Linked list after insertion" << std::endl;
	linked_list::printList(head_ptr);

	insertion_position = 10;
	insertion_data = 100;
	std::cout << "\nInserting " << insertion_data << " at position " << insertion_position << std::endl;
	head_ptr = linked_list::insert_at_pos(head_ptr, insertion_data, insertion_position);
	std::cout << "Linked list after insertion" << std::endl;
	linked_list::printList(head_ptr);

	// Key search
	std::cout << "\nSearching elements" << std::endl;
	search_data = 55;
	search_idx = linked_list::search_key(head_ptr, search_data);
	if(search_idx != -1)
		std::cout << "Element " << search_data << " is present at position " << search_idx << " in linked list" << std::endl;

	search_data = 10;
	search_idx = linked_list::search_key(head_ptr, search_data);
	if(search_idx != -1)
		std::cout << "Element " << search_data << " is present at position " << search_idx << " in linked list" << std::endl;

	search_data = 35;
	search_idx = linked_list::search_key(head_ptr, search_data);
	if(search_idx != -1)
		std::cout << "Element " << search_data << " is present at position " << search_idx << " in linked list" << std::endl;

	search_data = 100;
	search_idx = linked_list::search_key(head_ptr, search_data);
	if(search_idx != -1)
		std::cout << "Element " << search_data << " is present at position " << search_idx << " in linked list" << std::endl;

	// Edge-ish cases
	std::cout << "\nInserting at end of linked list when list is empty" << std::endl;
	linked_list::Node *temp_ptr = NULL;
	temp_ptr = linked_list::insert_at_end(temp_ptr, 90);
	linked_list::printList(temp_ptr);

	std::cout << "Deleting the fist node of the linked list with ";
	linked_list::printList(temp_ptr);
	temp_ptr = linked_list::delete_head(temp_ptr);
	std::cout << "Linked list after deleting first node: ";
	linked_list::printList(temp_ptr);

	std::cout << "Deleting the last node of the linked list with ";
	linked_list::printList(temp_ptr);
	temp_ptr = linked_list::delete_tail(temp_ptr);
	std::cout << "Linked list after deleting last node: ";
	linked_list::printList(temp_ptr);
	return EXIT_SUCCESS;
}