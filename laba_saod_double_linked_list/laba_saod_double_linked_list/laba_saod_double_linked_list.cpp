#include "double_linked_list.h"

int main() {
	setlocale(LC_ALL, "rus");
	menu();
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
	return 0;
}

int failure() {
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "\nОШИБКА ВВОДА. ПОВТОРИТЕ ВВОД \n" << std::endl;
	}
	return a;
}


void menu() {
	int command, choice;
	int search_data;
	List l;
	while (true) {
		std::cout << "\nВыберите команду из списка:\n";
		std::cout << "1. Вывод текущего состояния списка на экран (проход с начала списка)\n";
		std::cout << "2. Проверка пустоты списка\n";
		std::cout << "3. Вывод текущего состояния списка на экран (проход с конца списка)\n";
		std::cout << "4. Добавить элемент в список\n";
		std::cout << "5. Удалить элемент из списка\n";
		std::cout << "6. Поиск элемента с заданной информационной частью (с начала списка)\n";
		std::cout << "7. Поиск элемента с заданной информационной частью (с конца списка)\n";
		std::cout << "8. Очистить список\n";
		std::cout << "0. Завершить работу программы\n";
		std::cout << "Номер команды: ";
		command = failure();
		switch (command) {
		case 0:
			return;
			break;
		case 1:
			output_list(l);
			break;
		case 2:
			if (is_Empty(l)) std::cout << "Список пуст" << std::endl;
			else std::cout << "Список не пуст" << std::endl;
			break;
		case 3:
			routput_list(l);
			break;
		case 4:
			push(l);
			break;
		case 5:
			remove(l);
			break;
		case 6:
			std::cout << "Введите информационную часть искомого элемента: " << std::endl;
			std::cin >> search_data;
			find(l, search_data);
			break;
		case 7:
			std::cout << "Введите информационную часть искомого элемента: " << std::endl;
			std::cin >> search_data;
			rfind(l, search_data);
			break;
		case 8:
			if (!is_Empty(l)) {
				destroy(l);
			}
			else {
				std::cout << "Список пуст, удалять нечего";
			}
			break;
		default:
			std::cout << "Такой команды нет в меню, повторите ввод" << std::endl;
			break;
		}
	}
}
