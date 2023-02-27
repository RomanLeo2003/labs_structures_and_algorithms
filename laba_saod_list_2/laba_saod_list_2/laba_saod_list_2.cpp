#include "list_2.h"

int main() {
	setlocale(LC_ALL, "rus");
	menu();
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
	int command;
	type search_data;
	List l;
	init_list(l);
	while (true) {
		std::cout << "\nВыберите команду из списка:\n";
		std::cout << "1. Вывод текущего состояния списка на экран\n";
		std::cout << "2. Проверка пустоты списка\n";
		std::cout << "3. Проверка полноты списка\n";
		std::cout << "4. Добавить элемент в список\n";
		std::cout << "5. Удалить элемент из списка\n";
		std::cout << "6. Поиск элемента с заданной информационной частью\n";
		std::cout << "7. Очистить список\n";
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
			if (is_Full(l)) std::cout << "Список полон" << std::endl;
			else std::cout << "Список не полон" << std::endl;
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
			std::cout << "Индекс элемента в списке: " << find(l, search_data) << std::endl;
			break;
		case 7:
			if (!is_Empty(l)) {
				init_list(l);
				l.count = 0;
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
