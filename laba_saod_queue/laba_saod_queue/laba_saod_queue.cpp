#include "queue.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	menu();

	// для проверки на утечки памяти
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
	return 0;
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

void menu() {
	int command, data;
	queue q;
	while (true) {
		cout << "\nВведите номер команды:\n";
		cout << "1. Проверка пустоты очереди\n";
		cout << "2. Проверка заполненности очереди\n";
		cout << "3. Добавить элемент в конец очереди\n";
		cout << "4. Удалить элемент из начала очереди\n";
		cout << "5. Вывод текущего состояния очереди на экран\n";
		cout << "0. Завершить работу программы\n";
		cout << "Введите номер команды: ";
		command = failure_int();
		switch (command) {
		case 1:
			if (is_Empty(q)) cout << "Очередь пуста" << endl;
			else cout << "Очередь не пуста" << endl;
			break;
		case 2:
			if (is_Full(q)) cout << "Очередь заполнена" << endl;
			else cout << "Очередь не заполнена" << endl;
			break;
		case 3:
			if (!is_Full(q)) {
				cout << "Введите число, которое хотите добавить в очередь: " << endl;
				data = failure_int();
			}
			push_back(&q, data);
			break;
		case 4:
			pop(&q);
			break;
		case 5:
			output_queue(q);
			break;
		case 0:
			return;
			break;
		}
	}
}

