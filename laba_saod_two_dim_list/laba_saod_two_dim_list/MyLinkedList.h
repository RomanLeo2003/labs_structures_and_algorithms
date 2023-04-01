#pragma once
#include <iostream>

typedef struct Node {
	int data;
	Node *next{nullptr};
	Node *prev{ nullptr };
};

typedef struct SubList{
	int ind_data{};
	Node *first{nullptr};
	int count = 0;
};

typedef struct LinkedList {
	int count = 0;
	SubList *head{nullptr};
	SubList *next{nullptr};
};

inline bool is_Empty(LinkedList &list) {
	return list.head == nullptr;
}