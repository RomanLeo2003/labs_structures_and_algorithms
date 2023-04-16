#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <random>
#include <algorithm>

struct Node
{
	int data{ -1 };
	Node* next{ nullptr };
};

void menu();
void fill_array(std::vector<int>& arr);
void bubble_sort(std::vector<int>& arr);
void insertion_sort(std::vector<int>& arr);
void selection_sort(std::vector<int>& arr);
void output_array(std::vector<int>& arr);
void quick_sort(std::vector<int>& arr, int start, int end, int& n_comps, int& n_reeqs);
int partition(std::vector<int>& arr, int start, int end, int& n_comps, int& n_reeqs);
void shell_sort(std::vector<int>& arr);
void heap_sort(std::vector<int> & arr);
// void fill_uniform_array(std::vector<double>& arr);
void fill_uniform_int_array(std::vector<int>& arr, int opt);
void bucket_sort(std::vector<int>& arr);
void radix_sort(std::vector<int>& arr);
void fill_array_for_radix(std::vector<int>& arr);
void generic_bucket_sort(std::vector<int> &numbers);
