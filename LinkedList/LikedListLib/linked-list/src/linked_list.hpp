#pragma once 

#ifndef LINKED_LIST_HPP_
#define LINKED_LIST_HPP_

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

Node* insert_at_begin(Node*, int);
Node* insert_at_end(Node*, int);
Node* insert_at_pos(Node*, int, int);

Node* delete_head(Node*);
Node* delete_tail(Node*);

int search_key(Node*, int);

}

#endif