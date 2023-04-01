#include "LinkedList.h"
#include <iostream>
#include <optional>

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

void handle_remove_sublist(NodeList* head) {
	if (is_Empty_list(head)) {
		std::cout << "Главный список пуст, удалять нечего" << std::endl;
	} else{
		std::cout << "Введите значение id списка, из которого хотите выполнить удаление" << std::endl;
		int list_id{};
		std::cin >> list_id;

		NodeList* current{ head };
		while (current != nullptr && current->list_data != list_id)
			current = current->next;

		if (current == nullptr)
		{
			std::cout << "Не найдено такого элемента" << std::endl;
			return;
		}
		remove_from_sublist(current->head);
	}
}

void handle_push_sublist(NodeList* head) {
	if (is_Empty_list(head)) {
		std::cout << "Главный список пуст, для начала добавьте новый подсписок" << std::endl;
	}
	else {
		std::cout << "Введите значение id списка, в который хотите вставить значение" << std::endl;
		int list_id{};
		std::cin >> list_id;

		NodeList* current{ head };
		while (current != nullptr && current->list_data != list_id)
			current = current->next;

		if (current == nullptr)
		{
			std::cout << "Не найдено такого элемента" << std::endl;
			return;
		}
		push_to_sublist(current->head);
	}
}



void menu() {
	int search_data{}, choice{};
	NodeList* current{};
	NodeList* head{};
	int command{};
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
			destroy_list(head);
			return;
			break;
		case 1:
			output_list(head);
			break;
		case 2:
			if (is_Empty_list(head)) std::cout << "Список пуст" << std::endl;
			else std::cout << "Список не пуст" << std::endl;
			break;
		case 3:
			output_list(head);
			break;
		case 4:
			std::cout << "Введите 1 - если хотите добавить новый список\nВведите 2 - если хотите добавить новый элемент в существующий список" << std::endl;
			choice = failure();
			if (choice == 1) {
				push_to_list(&head);
			}
			else if (choice == 2) {
				handle_push_sublist(head);
			}
			break;
		case 5:
			std::cout << "Введите 1 - если хотите удалить подсписок главного списка\nВведите 2 - если хотите удалить элемент подсписка" << std::endl;
			choice = failure();
			if (choice == 2) {
				handle_remove_sublist(head);
			}
			else if (choice == 1) {
				std::cout << "Введите id удаляемого списка" << std::endl;
				search_data = failure();
				remove_from_list(&head, search_data);
			}
			break;
		case 6:
			std::cout << "Введите информационную часть искомого элемента: " << std::endl;
			search_data = failure();
			current = head;
			while (!find_in_sublist(current->head, search_data) && current != nullptr) {
				current = current->next;
			}
			break;
		case 7:
			if (!is_Empty_list(head)) {
				destroy_list(head);
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

