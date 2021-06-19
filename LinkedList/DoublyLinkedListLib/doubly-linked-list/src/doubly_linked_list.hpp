#pragma once

#ifndef DOUBLY_LINKED_LIST_HPP_
#define DOUBLE_LINKED_LIST_HPP_

#include <iostream>
#include <stdlib.h>

namespace doubly_ll{

struct Node {
	int data;
	Node* prev;
	Node* next;

	Node(int data_) {
		data = data_;
		prev = NULL;
		next = NULL;
	}
};

void printList(Node*);

Node* insert_at_begin(Node*, int);
Node* insert_at_end(Node*, int);

Node* delete_head(Node*);
Node* delete_tail(Node*);

Node* reverse(Node*);

}

#endif