#pragma once

#include <iostream>
#include <string>
#define ARRAY_SIZE 5

typedef std::string type;

template <typename T>
struct List {
	T arr[ARRAY_SIZE];
	int count = 0;
};

void menu();
int failure();
bool is_Full(List<type> list);
bool is_Empty(List<type> list);
int find(List<type> list, type search);
void init_list(List<type> &list);
void push(List<type> &list);
void output_list(List<type> list);
void remove(List<type> &list);

