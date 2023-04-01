#pragma once
#include <iostream>
#include <crtdbg.h>

typedef int type;

struct Node {
	type data;
	Node *next;
};

struct LinkedList {
	Node *first = nullptr;
	int count = 0;
};

//void search_with_prev(LinkedList &list, Node *cur, Node *prev, type data);
void push_front(LinkedList &list, Node *cur);
type remove(LinkedList &list);
void find(LinkedList &list, type data);
//int find_prev(LinkedList &list, type data);
bool is_Empty(LinkedList &list);
void push(LinkedList &list);
void output_list(LinkedList &list);
int failure();
void menu();
void destroy(LinkedList &list);
void move_to_del_list(LinkedList &list, LinkedList &del_list);