#include "list_2.h"

void init_list(List &list) {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		list.arr[i].next = -1;
		list.arr[i].data = '\0';
	}
}

type remove(List &list) {
	type data, del_data = '\0';
	std::cout << "Введите информационную часть удаляемого эелмента" << std::endl;
	std::cin >> data;
	int ind = find(list, data);
	if (ind != -1) {
		if (ind == list.head) {
			int cur_head = list.head;
			list.head = list.arr[list.head].next;
			list.arr[cur_head].next = -1;
			list.count--;
		}
		else {
			int ind_prev = find_prev(list, data);
			del_data = list.arr[ind].data;
			list.arr[ind_prev].next = list.arr[ind].next;
			list.arr[ind].next = -1;
			list.count--;
		}
	}
	else {
		std::cout << "jopa" << std::endl;
	}
	
	return del_data;
}

int find(List &list, type data) {
	int cur_ind = list.head;
	ListElem cur = list.arr[list.head];
	while (cur_ind != -1) {
		if (cur.data == data)
			return cur_ind;
		cur_ind = cur.next;
		if (cur.next != -1) 
			cur = list.arr[cur.next];
		
	}
	return -1;
}

int find_prev(List &list, type data) {
	int cur_ind = 0, prev_ind = 0;
	ListElem cur = list.arr[list.head];
	ListElem prev = list.arr[list.head];
	if (list.arr[list.head].next != -1) { cur = list.arr[cur.next]; cur_ind = cur.next; }
	while (cur_ind != -1) {
		if (cur.data == data)
			return prev_ind;
		cur_ind = cur.next;
		if (cur.next != -1)
			cur = list.arr[cur.next];
		prev_ind = prev.next;
		if (prev.next != -1)
			prev = list.arr[prev.next];
		
	}
	return 0;
}

bool is_Full(List &list) {
	return list.count == ARRAY_SIZE;
}

bool is_Empty(List &list) {
	return list.count == 0;
}

void output_list(List &list) {
	int c = 0;
	if (!is_Empty(list)) {
		std::cout << "Вывод списка: " << std::endl;
		ListElem cur = list.arr[list.head];
		while (c < list.count && cur.data != 0) {
			std::cout << cur.data << "\t";
			if (cur.next != -1) {
				cur = list.arr[cur.next];
			}
			c++;
			
		}
	}
	else {
		std::cout << "Список пуст" << std::endl;
	}
}

void push(List &list) {
	ListElem cur = list.arr[list.head];
	int command, ind, cur_ind = 0, j = 0, ind_prev = 0;
	type data, data_push;
	if (is_Full(list)) {
		std::cout << "Список полон, новый элемент добавить нельзя" << std::endl;
	}
	else if (is_Empty(list)) {
		std::cout << "Список пуст, элемент будет добавлен в начало списка" << std::endl;
		std::cout << "Введите элемент, который хотите добавить" << std::endl;
		std::cin >> data;
		list.arr[list.head].data = data;
		list.count++;
	}
	else {
		std::cout << "Введите информационную часть элемента, относительно которого будет выполнятся вставка:" << std::endl;
		std::cin >> data;
		ind = find(list, data);
		if (ind != -1) {
			std::cout << "Введите способ добавления:\n0. Вставить перед элементом\n1. Вставить после элемента" << std::endl;
			command = failure();
			if (command == 1) {
				std::cout << "Введите данные которые хотите добавить" << std::endl;
				std::cin >> data_push;

				for (j = 1; j < ARRAY_SIZE; j++) if (list.arr[j - 1].next == -1) {  break; }

				list.arr[j].next = list.arr[ind].next; 
				list.arr[ind].next = j;
				list.arr[j].data = data_push;
				list.count++;
			}
			else if (command == 0) {
				if (ind == list.head) {
					int cur_head = list.head;
					for (j = 1; j < ARRAY_SIZE; j++) if (list.arr[j - 1].next == -1) break;
					list.head = j;
					list.arr[list.head].next = cur_head;
					std::cout << "Введите данные которые хотите добавить" << std::endl;
					std::cin >> data_push;
					list.arr[list.head].data = data_push;
					list.count++;
				}
				else {
					ind_prev = find_prev(list, data);
					std::cout << "Введите данные которые хотите добавить" << std::endl;
					std::cin >> data_push;
					j = list.arr[0].next;
					for (j = 1; j < ARRAY_SIZE; j++) if (list.arr[j - 1].next == -1) break;
					list.arr[j].next = ind;
					list.arr[ind_prev].next = j;
					list.arr[j].data = data_push;
					list.count++;
				}
			}
			else {
				std::cout << "Такой команды нет в меню, повторите ввод" << std::endl;
			}
		}
		else {
			std::cout << "Такого элемента нет в списке" << std::endl;
		}
	}
}