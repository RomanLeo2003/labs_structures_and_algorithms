#include "queue.h"

bool is_Empty(queue q) {
	return q.count == 0;
}

bool is_Full(queue q) {
	return q.count >= QUEUE_SIZE;
}

void output_queue(queue q) {
	if (is_Empty(q)) { std::cout << "Очередь пуста" << std::endl; }
	else {
		std::cout << "Вывод элементов очереди: " << std::endl;
		int current = q.first;
		int  i = 0;
		do {
			std::cout << i << "-й элемент в очереди: " << q.q_array[current] << "\n";
			current = (current + 1) % QUEUE_SIZE;
			i++;
		} while (current != q.last);
	}
}

void push_back(queue *q, int data) {
	if (is_Full(*q)) {
		std::cout << "Очередь переполнена. Добавление элементов невозможно." << std::endl;
	}
	else {
		q->q_array[q->last] = data;
		q->last = (q->last + 1) % QUEUE_SIZE;
		q->count++;
		std::cout << "Число " << data << " добавлено в очередь" << std::endl;
	}
}

int pop(queue *q) {
	int del = -1;
	if (is_Empty(*q)) {
		std::cout << "Очередь пуста. Удалять нечего." << std::endl;
	}
	else {
		del = q->q_array[q->first];
		q->first = (q->first + 1) % QUEUE_SIZE;
		q->count--; // ?????????????????????????
		std::cout << "Удаленное число: " << del << std::endl;
	}
	return del;
}