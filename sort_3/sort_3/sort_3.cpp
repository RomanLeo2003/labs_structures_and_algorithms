#include "sorts.h"

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	menu();
}

void menu() {
	std::vector<int> arr;
	int choice, qsort_n_comps{ 0 }, qsort_n_reeqs{ 0 };
	while (true) {
		std::cout << "Выберите пункт меню:" << std::endl;
		std::cout << "0 - выйти из программы" << std::endl;
		std::cout << "1 - пузырьковая сортировка" << std::endl;
		std::cout << "2 - сортировка вставками" << std::endl;
		std::cout << "3 - сортировка выбором" << std::endl;
		std::cout << "4 - заполнить массив новыми значениями" << std::endl;
		std::cout << "5 - быстрая сортировка" << std::endl;
		std::cout << "6 - сортировка Шелла" << std::endl;
		std::cout << "7 - пирамидальная сортировка" << std::endl;
		std::cout << "8 - простая карманная сортировка" << std::endl;
		std::cout << "9 - поразрядная сортировка" << std::endl;
		std::cout << "10 - обобщенная карманная сортировка" << std::endl;
		std::vector<double> arr2;
		std::cin >> choice;
		switch (choice) {
		case 0:
			return;
			break;
		case 1:
			fill_array(arr);
			bubble_sort(arr);
			arr.clear();
			break;
		case 2:
			fill_array(arr);
			insertion_sort(arr);
			arr.clear();
			break;
		case 3:
			fill_array(arr);
			selection_sort(arr);
			arr.clear();
			break;
		case 4:
			fill_array(arr);
			break;
		case 5:
			fill_array(arr);
			std::cout << "Несортированный массив: ";
			output_array(arr);
			quick_sort(arr, 0, arr.size() - 1, qsort_n_comps, qsort_n_reeqs);
			std::cout << "Количество сравнений: " << qsort_n_comps << std::endl;
			std::cout << "Количество переприсваиваний: " << qsort_n_reeqs << std::endl;
			std::cout << "Отсортированный массив: ";
			output_array(arr);
			// std::cout << "ВРЕМЯ СОРТИРОВКИ:" <<  << std::endl;
			arr.clear();
			break;

		case 6:
			fill_array(arr);
			shell_sort(arr);
			break;

		case 7:
			fill_array(arr);
			heap_sort(arr);
			break;

		case 8:
			fill_uniform_int_array(arr, 0);
			bucket_sort(arr);
			arr.clear();
			break;
		case 9:
			fill_uniform_int_array(arr, 1);
			radix_sort(arr);
			arr.clear();
			break;
		case 10:
			fill_uniform_int_array(arr, 1);
			generic_bucket_sort(arr);
			arr.clear();
			break;
		}
	}
}
