#include <linked_list.hpp>

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

	// Sorted Insert
	std::cout << "\nPerforming sorted insertions" << std::endl;
	temp_ptr = linked_list::sorted_insert(temp_ptr, 33);
	temp_ptr = linked_list::sorted_insert(temp_ptr, 10);
	temp_ptr = linked_list::sorted_insert(temp_ptr, -50);
	temp_ptr = linked_list::sorted_insert(temp_ptr, 107);
	temp_ptr = linked_list::sorted_insert(temp_ptr, 0);
	temp_ptr = linked_list::sorted_insert(temp_ptr, 33);
	std::cout << "Linked list after sorted insertions" << std::endl;
	linked_list::printList(temp_ptr);

	// Get-middle
	std::cout << "\nMiddle element" << std::endl;
	linked_list::printList(head_ptr);
	std::cout << "Middle element: " << linked_list::get_middle(head_ptr) << std::endl;

	linked_list::printList(temp_ptr);
	std::cout << "Middle element: " << linked_list::get_middle(temp_ptr) << std::endl;

	// Get Nth from end
	int pos_from_tail;
	std::cout << "\nPrinting Nth element from tail of linked list" << std::endl;
	linked_list::printList(head_ptr);
	pos_from_tail = 3;
	std::cout << "Item #" << pos_from_tail << " from the end of linked list by finding length: " <<
		linked_list::getNth_from_end(head_ptr, pos_from_tail, false) << std::endl;
	std::cout << "Item #" << pos_from_tail << " from the end of linked list: " <<
		linked_list::getNth_from_end(head_ptr, pos_from_tail, true) << std::endl;

	std::cout << std::endl;
	linked_list::printList(temp_ptr);
	pos_from_tail = 10;
	std::cout << "Item #" << pos_from_tail << " from the end of linked list by finding length: " <<
		linked_list::getNth_from_end(temp_ptr, pos_from_tail, false) << std::endl;
	std::cout << "Item #" << pos_from_tail << " from the end of linked list: " <<
		linked_list::getNth_from_end(temp_ptr, pos_from_tail, true) << std::endl;

	// Reversing linked list
	std::cout << "\nReversing Linked list" << std::endl;
	linked_list::printList(head_ptr);
	std::cout << "After reversing" << std::endl;
	head_ptr = linked_list::reverse(head_ptr);
	linked_list::printList(head_ptr);

	std::cout << std::endl;
	linked_list::printList(temp_ptr);
	std::cout << "After reversing" << std::endl;
	temp_ptr = linked_list::reverse(temp_ptr);
	linked_list::printList(temp_ptr);

	// Recursive reversing linked list
	std::cout << "\nRecursively reversing Linked list" << std::endl;
	linked_list::printList(head_ptr);
	std::cout << "After reversing" << std::endl;
	head_ptr = linked_list::recusive_reverse(NULL, head_ptr);
	linked_list::printList(head_ptr);

	std::cout << std::endl;
	linked_list::printList(temp_ptr);
	std::cout << "After reversing" << std::endl;
	temp_ptr = linked_list::recusive_reverse(temp_ptr);
	linked_list::printList(temp_ptr);

	// Removing duplicates from sorted list
	std::cout << "\nRemoving duplicated from sorted Linked list" << std::endl;
	linked_list::printList(head_ptr);
	std::cout << "After removal" << std::endl;
	linked_list::remove_duplicates_sorted(head_ptr);
	linked_list::printList(head_ptr);

	std::cout << std::endl;
	linked_list::printList(temp_ptr);
	std::cout << "After removal" << std::endl;
	linked_list::remove_duplicates_sorted(temp_ptr);
	linked_list::printList(temp_ptr);

	// Group reverse
	int group_size;
	std::cout << "\nReversing in groups of size k" << std::endl;
	group_size = 3;
	linked_list::printList(head_ptr);
	std::cout << "After reversing in groups of size " << group_size << std::endl;
	head_ptr = linked_list::reverse_in_groups(head_ptr, group_size);
	linked_list::printList(head_ptr);

	std::cout << "\nReversing in groups of size k" << std::endl;
	group_size = 4;
	linked_list::printList(temp_ptr);
	std::cout << "After reversing in groups of size " << group_size << std::endl;
	temp_ptr = linked_list::reverse_in_groups(temp_ptr, group_size);
	linked_list::printList(temp_ptr);

	// Delete without head
	std::cout << "\nDeleting node without head pointer from linked list" << std::endl;
	linked_list::printList(temp_ptr);
	linked_list::delete_node_without_head(temp_ptr->next->next);
	linked_list::printList(temp_ptr);

	// Even-Odd segeration
	std::cout << "\nSegregating even and odd entries of linked list" << std::endl;
	linked_list::printList(head_ptr);
	head_ptr = linked_list::segregate_even_odd(head_ptr);
	std::cout << "After segegration" << std::endl;
	linked_list::printList(head_ptr);

	std::cout << std::endl;
	linked_list::printList(temp_ptr);
	temp_ptr = linked_list::segregate_even_odd(temp_ptr);
	std::cout << "After segegration" << std::endl;
	linked_list::printList(temp_ptr);

	return EXIT_SUCCESS;
}