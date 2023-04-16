#include "../sorts.h"

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	menu();
}

void menu() {
	std::vector<int> arr;
	int choice;
	fill_array(arr);
	while (true) {
		std::cout << "Выберите пункт меню:" << std::endl;
		std::cout << "0 - выйти из программы" << std::endl;
		std::cout << "1 - пузырьковая сортировка" << std::endl;
		std::cout << "2 - сортировка вставками" << std::endl;
		std::cout << "3 - сортировка выбором" << std::endl;
		std::cout << "4 - заполнить массив новыми значениями" << std::endl;
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

		}
	}
}
