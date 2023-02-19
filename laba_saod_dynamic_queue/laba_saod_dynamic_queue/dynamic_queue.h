#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include <ctime>
#include <time.h>
#include <Windows.h>

struct elem {
	char data;
	elem* Next;
};

struct queue {
	elem *first = nullptr;
	elem *last = nullptr;
	int count = 0;
};


void modeling(queue &q);
void menu(queue &q);
bool is_Empty(queue q);
char pop(queue &q);
void push_back(queue &q, char data);
bool is_Empty(queue q);
void output_queue(queue q);
void destroy(queue &q);