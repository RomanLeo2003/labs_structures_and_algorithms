#pragma once
#include <iostream>
#define QUEUE_SIZE 4

typedef struct queue {
	int q_array[QUEUE_SIZE];
	int count = 0, first = 0, last = 0;
}queue;

void menu();
int failure_int();
bool is_Full(queue q);
bool is_Empty(queue q);
void output_queue(queue q);
void push_back(queue *q, int data);
int pop(queue *q);