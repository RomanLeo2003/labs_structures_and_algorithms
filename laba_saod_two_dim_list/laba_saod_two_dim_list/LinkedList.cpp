#include "LinkedList.h"
#include <iostream>

bool find_in_sublist(List &list, int data) {
	ListElem* cur{ list.head };
	int count = 0;
	if (is_Empty(list)) {
		std::cout << "Список пуст, искать нечего" << std::endl;
	}
	else {
		while (cur != nullptr && cur->data != data) {
			cur = cur->next;
			count++;
		}
		if (cur != nullptr) {
			std::cout << "Искомый элемент найден под индексом: " << count << std::endl;
			return true;
		}
		else std::cout << "Элемент не найден" << std::endl;
	}
	return false;
}

void rfind(List &list, int data) {
	ListElem* cur{ list.head->prev };
	int count{ 0 };

	if (is_Empty(list)) {
		std::cout << "Список пуст, искать нечего" << std::endl;
	}
	else {
		while (cur != nullptr && cur->data != data) {
			cur = cur->prev;
			count++;
		}
		if (cur != nullptr) std::cout << "Искомый элемент найден под индексом: " << list.count - count << std::endl;
		else std::cout << "Элемент не найден" << std::endl;
	}
}

void output_sublist(List &list) {
	if (is_Empty(list)) {
		std::cout << "Список пуст" << std::endl;
	}
	else {
		ListElem *cur{ list.head };
		do {
			std::cout << cur->data << "  ";
			cur = cur->next;
		} while (cur != nullptr && cur != list.head);
	}
}

void push_front(List &list, int data) {
	ListElem *node = new ListElem, *cur = list.head;
	node->data = data;
	if (is_Empty(list)) {
		list.head = node;
		list.head->next = list.head->prev = list.head;
	}
	else {
		ListElem *tail = list.head->prev;
		list.head->prev = node;
		list.head = node;
		list.head->next = cur;
		list.head->prev = tail;
		tail->next = list.head;
		if (list.count == 1) tail->prev = list.head;
	}
	list.count++;
}

void push_to_sublist(List &list) {
	int command;
	ListElem *cur{ list.head };
	int data, push_data;
	std::cout << "Введите элемент, который хотите добавить" << std::endl;
	std::cin >> push_data;
	if (is_Empty(list)) {
		push_front(list, push_data);
	}
	else {
		std::cout << "Введите элемент, относительно которого хотите выполнить добавление" << std::endl;
		std::cin >> data;
		std::cout << "Введите способ добавления:\n0. Вставить перед элементом\n1. Вставить после элемента" << std::endl;
		command = failure();
		if (command == 0) {
			if (list.head->data == data) {
				push_front(list, push_data);
			}
			else {
				if (cur != nullptr) cur = cur->next;
				while (cur != nullptr && cur->next != list.head  && cur->data != data) {
					cur = cur->next;
				}
				if (cur != list.head) {
					ListElem *new_node = new ListElem;
					new_node->data = push_data;
					new_node->next = cur;
					new_node->prev = cur->prev;
					cur->prev->next = new_node;
					cur->prev = new_node;
					list.count++;
				}
				else {
					std::cout << "Элемент не найден" << std::endl;
				}
			}
		}
		else if (command == 1) {
			if (list.head->data == data) {
				ListElem *new_node = new ListElem;
				new_node->data = push_data;
				new_node->next = list.head->next;
				new_node->prev = list.head;
				list.head->next = new_node;
				if (list.count == 1) list.head->prev = new_node;
				else list.head->next->prev = new_node;
				list.count++;
			}
			else {
				if (cur != nullptr) cur = cur->next;
				while (cur != nullptr && cur->next != list.head  && cur->data != data) {
					cur = cur->next;
				}
				if (cur != list.head) {
					ListElem *new_node = new ListElem;
					new_node->data = push_data;
					new_node->next = cur->next;
					new_node->prev = cur;
					cur->next->prev = new_node;
					cur->next = new_node;
					list.count++;
				}
				else {
					std::cout << "Элемент не найден" << std::endl;
				}
			}
		}

	}
}

void remove_from_sublist(List &list) {
	if (is_Empty(list)) {
		std::cout << "Список пуст, удалять нечего" << std::endl;
	}
	else {
		ListElem *cur = list.head;
		int data;
		std::cout << "Введите информационную часть удаляемого элемента" << std::endl;
		std::cin >> data;
		if (list.head->data == data) {
			ListElem *tail = list.head->prev;
			list.head = list.head->next;
			tail->next = list.head;
			list.head->prev = tail;
			delete cur;
			list.count--;
		}
		else {
			while (cur != nullptr && cur->next != list.head  && cur->data != data) {
				cur = cur->next;
			}
			if (cur != list.head) {
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
				delete cur;
				list.count--;
			}
			else {
				std::cout << "Элемент не найден" << std::endl;
			}
		}
		if (list.count == 0) list.head = nullptr;
	}
}

void routput_list(List &list) {
	if (is_Empty(list)) {
		std::cout << "Список пуст" << std::endl;
	}
	else {
		ListElem *cur{ list.head->prev };
		do {
			std::cout << cur->data << "  ";
			cur = cur->prev;
		} while (cur != nullptr && cur != list.head);
		std::cout << list.head->data << std::endl;
	}
}

void destroy_sublist(List &list) {
	if (!is_Empty(list)) {
		ListElem *cur{ list.head };
		do {
			list.head = list.head->next;
			delete cur;
			cur = list.head;
			list.count--;
		} while (list.count);
		if (list.count == 0) list.head = nullptr;
	}
}


void push_to_list(NodeList** head)
{
	int command{};
	std::cout << "Введите новый id списка: " << std::endl;
	int list_data{};
	list_data = failure();
	if (is_Empty_list((*head)))
	{
		(*head) = new NodeList;
		(*head)->next = nullptr;
		(*head)->list_data = list_data;
		(*head)->count++;
	}
	else {
		std::cout << "Введите способ добавления:\n0 - перед заданным элементом\n1 - после заданного элемента" << std::endl;
		command = failure();
		if (command == 1)
		{
			std::cout << "Введите элемент, относительно которого будет выполняться вставка: " << std::endl;
			int value{};
			std::cin >> value;
			NodeList* current{ (*head) };
			while (current != nullptr && current->list_data != value)
				current = current->next;

			if (current == nullptr)
			{
				std::cout << "Не найдено такого элемента" << std::endl;
				return;
			}
			NodeList* newList{ new NodeList{} };
			newList->next = current->next;
			newList->list_data = list_data;
			current->next = newList;
		}
		else if (command == 0 && (*head)->count > 1)
		{
			std::cout << "Введите элемент, относительно которого будет выполняться вставка: " << std::endl;
			int value{};
			std::cin >> value;
			NodeList* previous{ (*head) };
			NodeList* current{ (*head)->next };
			while (current != nullptr && current->list_data != value)
			{
				current = current->next;
				previous = previous->next;
			}

			if (current == nullptr && (*head)->count > 1)
			{
				std::cout << "Не найдено такого элемента" << std::endl;
				return;
			}
			else if (previous == (*head)) {
				(*head) = new NodeList;
				(*head)->next = previous;
				(*head)->list_data = list_data;
			}
			else {
				NodeList* newList{ new NodeList{} };
				newList->next = current;
				newList->list_data = list_data;
				previous->next = newList;
			}
			
		}
	}
	
	(*head)->count++;
	
}

void remove_from_list(NodeList** head, int listIdToRemove)
{
	if (is_Empty_list((*head)))
	{
		std::cout << "Список пуст, удалять нечего" << std::endl;
		return;
	}
	
	(*head)->count--;
	NodeList* current{(*head)->next };
	NodeList* previous{ (*head) };
	if ((*head)->list_data == listIdToRemove) {
		(*head) = current;
		destroy_sublist(previous->head);
		delete previous;
	}
	else {
		while (current != nullptr && current->list_data != listIdToRemove)
		{
			current = current->next;
			previous = previous->next;
		}
		if (current == nullptr)
		{
			std::cout << "Не найдено такого элемента" << std::endl;
			return;
		}
		previous->next = current->next;
		destroy_sublist(current->head);
		delete current;
	}
	
}

void output_list(NodeList* head)
{
	if (is_Empty_list(head))
	{
		std::cout << "Список пуст, выводить нечего" << std::endl;
		return;
	}
	NodeList* current{ head };
	while (current != nullptr)
	{
		std::cout << current->list_data << ": ";
		output_sublist(current->head);
		current = current->next;
		std::cout << '\n';
	}
	std::cout << "\n";
}

void destroy_list(NodeList* head) {
	head->count = 0;
	NodeList *current{head};
	while (head != nullptr) {
		current = head;
		head = head->next;
		destroy_sublist(current->head);
		delete current;
	}
}