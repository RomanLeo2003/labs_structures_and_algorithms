#include "dynamic_queue.h"
using namespace std;


bool is_Empty(queue q) {
	return q.count == 0;
}

void push_back(queue &q, char data) {
	elem *new_elem = new elem;
	new_elem->data = data;
	new_elem->Next = nullptr;
	if (is_Empty(q)) {
		
		q.first = q.last = new_elem;
	}
	else {
		q.last->Next = new_elem;
		q.last = new_elem;
	}
	q.count++;
}

char pop(queue &q) {
	char del_data;
	if (is_Empty(q)) {
		std::cout << "Очередь пуста, удалять нечего" << std::endl;
	}
	else {
		elem *cur = q.first;
		del_data = q.first->data;
		q.first = q.first->Next;
		q.count--;
		delete cur;
	}
	return del_data;
}

void destroy(queue &q) {
	while (!is_Empty(q)) {
		pop(q);
	}
}

void output_queue(queue q) {
	if (!is_Empty(q)) {
		std::cout << "\n";
		elem *cur;
		cur = q.first;
		int  i = 0;
		while (cur != nullptr) {
			std::cout << i << ")" << cur->data << std::endl;
			cur = cur->Next;
			i++;
		}
	}
	else {
		std::cout << "Очередь пуста" << std::endl;
	}
}

