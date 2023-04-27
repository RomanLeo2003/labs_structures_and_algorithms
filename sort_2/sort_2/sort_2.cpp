#include "sorts.h"

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	menu();
}

void menu() {
	std::vector<int> arr;
	int choice, qsort_n_comps{ 0 }, qsort_n_reeqs{ 0 };
	unsigned int start_time, end_time;
	fill_array(arr);
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
		std::vector<int> arr1 = arr;
		std::cin >> choice;
		switch (choice) {
		case 0:
			return;
			break;
		case 1:
			bubble_sort(arr1);
			arr1.clear();
			break;
		case 2:
			insertion_sort(arr1);
			arr1.clear();
			break;
		case 3:
			selection_sort(arr1);
			arr1.clear();
			break;
		case 4:
			arr.clear();
			fill_array(arr);
			break;
		case 5:
			quick_sort(arr1, 0, arr.size() - 1, qsort_n_comps, qsort_n_reeqs);
			std::cout << "Несортированный массив: ";
			output_array(arr);
			std::cout << "Количество сравнений: " << qsort_n_comps << std::endl;
			std::cout << "Количество переприсваиваний: " << qsort_n_reeqs << std::endl;
			std::cout << "Отсортированный массив: ";
			output_array(arr1);
			arr1.clear();
			break;

		case 6:
			shell_sort(arr1);
			break;

		case 7:
			heap_sort(arr1);
			break;
		}
	}
}
