#pragma once
#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <stdlib.h>
#include <crtdbg.h>
#include <ctime>

typedef struct stack {
	int data;
	struct stack *Next;
}stack;

int failure_int();
void menu();
stack *init_with_no_data();
stack *init(int data);
stack *push(stack *last, int data);
bool is_Empty(stack *head);
void move_to_del_stack(stack **head, stack **del_stack);
int pop(stack **head);
void destroy(stack **root);
int len_stack(stack* head);
void push_random(stack **head);
void output_stack(stack *head);


