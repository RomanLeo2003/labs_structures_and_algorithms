#include "list_1.h"

bool is_Full(List &list) {
	return list.count == ARRAY_SIZE;
}


int find(List &list, type search) {
	int first = 0;
	int last = list.count - 1;
	int mid;
	while (first <= last) {
		mid = (first + last) / 2;
		if (list.arr[mid] == search) {
			return mid;
		}
		else if (list.arr[mid] > search) {
			last = mid - 1;
		}
		else {
			first = mid + 1;
		}
	}
	return -1;
}

bool is_Empty(List &list) {
	return list.count == 0;
}


void init_list(List &list) {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		list.arr[i] = '\0';
	}
}

void push(List &list) {
	int command, i; type data;
	if (is_Full(list)) {
		std::cout << "—писок полон, добавить новый элемент нельз€" << std::endl;
	}
	else {
		std::cout << "¬ведите элемент, который хотите вставить:" << std::endl;
		std::cin >> data;
		if (is_Empty(list)) {
			list.arr[0] = data;
		}
		else {
			for (i = 0; i < list.count; i++) {
				if (list.arr[i] > data) {
					for (int j = list.count; j > i; j--) {
						list.arr[j] = list.arr[j - 1];
					}
					list.arr[i] = data;
					break;
				}
			}
			if (i == list.count) {
				list.arr[i] = data;
			}
		}
		list.count++;
	}
}

void remove(List &list) {
	type data;
	int ind;
	if (is_Empty(list)) {
		std::cout << "—писок пуст, удал€ть нечего" << std::endl;
	}
	else {
		std::cout << "¬ведите информационную часть удал€емого элемента:" << std::endl;
		std::cin >> data;
		ind = find(list, data);
		if (ind != -1) {
			list.arr[ind] = '\0';
			for (int i = ind; i < list.count - 1; i++) {
				list.arr[i] = list.arr[i + 1];
			}
			list.count--;
		}
		else {
			std::cout << "Ёлемент в списке не найден" << std::endl;
		}
	}
}

void output_list(List list) {
	if (is_Empty(list)) {
		std::cout << "—писок пуст" << std::endl;
	}
	else {
		std::cout << "—писок: " << std::endl;
		for (int i = 0; i < list.count; i++) {
			std::cout << list.arr[i] << "\t";
		}
	}
}