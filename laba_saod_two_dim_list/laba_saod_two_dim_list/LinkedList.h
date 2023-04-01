#pragma once


typedef struct ListElem {
	int data;
	ListElem* next;
	ListElem* prev;
};

typedef struct List {
	ListElem* head = nullptr;
	int count = 0;
};

struct NodeList
{
	int count = 0;
	int list_data{};
	List head;
	NodeList* next{ nullptr };
};

void menu();
int failure();
inline bool is_Empty(List &head) {
	return head.head == nullptr;
};
inline bool is_Empty_list(const NodeList* head) {
	return head == nullptr;
}
void push_to_sublist(List &list);
void push_to_list(NodeList** head);
void remove_from_sublist(List &list);
void remove_from_list(NodeList** head, int listIdToRemove);
bool find_in_sublist(List &list, int data);
void output_sublist(List &list);
void output_list(NodeList* head);
void destroy_sublist(List &list);
void destroy_list(NodeList* head);