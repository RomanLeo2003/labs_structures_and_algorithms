#include "stack.h"

stack *init_with_no_data() {
	stack *new_stack = nullptr;
	return new_stack;
}

stack *init(int data) {
	stack *new_stack = new stack;
	new_stack->data = data;
	new_stack->Next = nullptr;
	return new_stack;
}

 stack *push(stack *head, int data) {
	stack *new_stack = init(data);
	new_stack->Next = head;
	head = new_stack;
	return head;
}

 bool is_Empty(stack *head) {
	 return head == nullptr;
 }

 void push_random(stack **head) {
	 std::cout << "Сколько случайных чисел добавить?\n";
	 int n = failure_int();
	 for (int i = 0; i < n; i++) {
		 (*head) = push((*head), rand() % 100);
	 }
	 std::cout << "Количество добавленных в главный стек элементов: " << n << std::endl;
 }

 void move_to_del_stack(stack **head, stack **del_stack) {
	 stack *cur;
	 int data = (*head)->data;
	 if ((*head) != nullptr) {
		 cur = (*head);
		 (*head) = (*head)->Next;
		 cur->Next = (*del_stack);
		 (*del_stack) = cur;
		 std::cout << "Удаленное число:" << cur->data << std::endl;
	 }
}

 int pop(stack **head) {
	 stack *cur;
	 int data = (*head)->data;
	 if ((*head) != nullptr) {
		 cur = (*head);
		 (*head) = (*head)->Next;
		 delete(cur);
	 }
	 return data;
 }

void destroy(struct stack **head) {
	if ((*head) != nullptr) {
		struct stack* to_del = (*head);
		while (to_del != nullptr && (*head) != nullptr) {
			(*head) = (*head)->Next;
			delete(to_del);
			to_del = (*head);
		}
	}
}

int len_stack(struct stack* head) {
	int len = 0;
	if (head != nullptr) {
		struct stack* cur = head;
		while (cur != nullptr) {
			len++;
			cur = cur->Next;
		}
	}
	return len;
}

void output_stack(struct stack *head) {
	struct stack *cur = head;
	std::cout << "Вывод содержания стека: " << std::endl;
	for (int i = 0; i < len_stack(head); i++) {
		std::cout << i << "-й элемерт стека: " << cur->data << std::endl;
		cur = cur->Next;
	}
}
