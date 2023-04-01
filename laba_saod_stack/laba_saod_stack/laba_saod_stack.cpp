#include "stack.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(nullptr));
	menu();

	// для проверки на утечки памяти
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
	return 0;
}

void menu() {
	int command, data, command_push, command_pop;
	stack *head = init_with_no_data(), *del_stack = init_with_no_data();
	while (true) {
		cout << "\nВведите номер команды:\n";
		cout << "1. Вывести состояние главного стека\n";
		cout << "2. Добавить элемент в главный стек\n";
		cout << "3. Удалить элемент из главного стека\n";
		cout << "4. Добавить несколько рандомных чисел в главный стек\n";
		cout << "5. Вывести состояние вспомогательного стека\n";
		cout << "0. Завершить работу программы\n";
		cout << "Ваш выбор: \n";
		command = failure_int();

		switch (command) {
			case 1:
				if (is_Empty(head)) cout << "Стек пуст" << endl;
				else output_stack(head);
				break;
			case 2:
				cout << "Введите способ добавления элемента:\n" << endl;
				cout << "0. Добавить с вводом элемента с консоли" << endl;
				cout << "1. Добавить с вершины вспомогательного стека" << endl;
				command_push = failure_int();
				if (command_push == 0) {
					cout << "Введите число, которые хотите добавить в стек: " << endl;
					data = failure_int();
					head = push(head, data);
					cout << "Число " << data << " добавлено в стек" << endl;
				}
				else if (command_push == 1){
					move_to_del_stack(&del_stack, &head);
				}
				
				break;
			case 3:
				if (is_Empty(head)) { cout << "Стек пуст, нечего удалять" << endl; }
				else {
					cout << "Введите способ удаления элемента:\n" << endl;
					cout << "0. Удалить с освобождением памяти" << endl;
					cout << "1. Удалить элемент из главного стека и поместить его во вспомогательный стек" << endl;
					command_pop = failure_int();
					if (command_pop == 0) {
						cout << "Удаленное число: " << pop(&head) << endl;
					}
					else if (command_pop == 1){
						move_to_del_stack(&head, &del_stack);
					}
				}
				break;
			case 4:
				push_random(&head);
				break;
			case 5:
				if (is_Empty(del_stack)) cout << "Стек пуст" << endl;
				else output_stack(del_stack);
				break;
			case 0:
				destroy(&head);
				destroy(&del_stack);
				return;
				break;
		}
	}	
}

int failure_int() {
	int a;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\nОШИБКА ВВОДА. ПОВТОРИТЕ ВВОД \n" << endl;
	}
	return a;
}



