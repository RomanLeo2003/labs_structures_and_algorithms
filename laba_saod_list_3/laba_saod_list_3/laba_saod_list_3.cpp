#include "list_3.h"

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
	type search_data;
	LinkedList l, del_l;
	while (true) {
		std::cout << "\nВыберите команду из списка:\n";
		std::cout << "1. Вывод текущего состояния списка на экран\n";
		std::cout << "2. Проверка пустоты списка\n";
		std::cout << "3. Вывод текущего состояния вспомогательного списка на экран\n";
		std::cout << "4. Добавить элемент в список\n";
		std::cout << "5. Удалить элемент из списка\n";
		std::cout << "6. Поиск элемента с заданной информационной частью\n";
		std::cout << "7. Очистить список\n";
		std::cout << "0. Завершить работу программы\n";
		std::cout << "Номер команды: ";
		command = failure();
		switch (command) {
		case 0:
			destroy(l);
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
			output_list(del_l);
			break;
		case 4:
			push(l);
			break;
		case 5:
			if (is_Empty(l)) {
				std::cout << "Список пуст, удалять нечего" << std::endl;
			}
			else {
				std::cout << "Как выполнить удаление элемента?\n0. Удалить с освобождением памяти\n1. Добавить элемент в конец вспомогательного списка" << std::endl;
				choice = failure();
				if (choice == 0) {
					remove(l);
				}
				else if (choice == 1) {
					move_to_del_list(l, del_l);
				}
				else {
					std::cout << "Такой команды нет в меню" << std::endl;
				}
			}
			break;
		case 6:
			std::cout << "Введите информационную часть искомого элемента: " << std::endl;
			std::cin >> search_data;
			find(l, search_data);
			break;
		case 7:
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
