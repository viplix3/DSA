#pragma once

#ifndef CIRCULAR_LINKED_LIST_HPP_
#define CIRCULAR_LINKED_LIST_HPP_

#include <iostream>
#include <stdlib.h>

namespace circular_ll {

struct Node {
	int data;
	Node* next;

	Node(int data_) {
		data = data_;
		next = NULL;
	}
};

void printList(Node*);

Node* insert_at_begin(Node*, int);
Node* insert_at_end(Node*, int);

Node* delete_head(Node*);
Node* delete_at_pos(Node*, int);

}

#endif