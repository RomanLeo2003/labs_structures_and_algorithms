#include "dynamic_queue.h"


int main()
{
	setlocale(LC_ALL, "rus");
	queue q;
	menu(q);
	destroy(q);

	// для проверки на утечки памяти
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
	return 0;
}

int failure_int() {
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "\nОШИБКА ВВОДА. ПОВТОРИТЕ ВВОД \n" << std::endl;
	}
	return a;
}

void modeling(queue &q) {
	int n, x;
	std::cout << "МОДЕЛИРОВАНИЕ ОЧЕРЕДИ" << std::endl;
	char key = '\0';
	char ch;
	std::cout << "Нажмите <q> или <Q> для выхода из режима моделирования очереди" << std::endl;
	while (true) {
		Sleep(2000);
		if (is_Empty(q)) x = 1;
		else x = (rand() % 2 == 0);

		if (x == 1) {
			n = rand() % 3 + 1;


			if (_kbhit()) key = _getch(); if ((key == 'q') || (key == 'Q')) { std::cout << "Завершение моделирования работы очереди..." << std::endl; break; }
			system("cls");
			std::cout << "Генерация и добавление " << n << " элемент(ов) в очередь..." << std::endl;
			Sleep(2000);
			for (int i = 0; i < n; i++) {
				ch = static_cast<char>(65 + rand() % 26);
				push_back(q, ch);
			}
		}
		else {
			n = rand() % 3 + 1; 
			if (_kbhit()) key = _getch(); if ((key == 'q') || (key == 'Q')) { std::cout << "Завершение моделирования работы очереди..." << std::endl; break; }
			system("cls");
			std::cout << "Извлечение " << n << " элемента(ов) из очереди..." << std::endl;
			Sleep(1000);
			for (int i = 0; i < n; i++)
				if (!is_Empty(q)) pop(q);
		}
		std::cout << "Нажмите <q> или <Q> для выхода из режима моделирования очереди" << std::endl;
		if (_kbhit()) key = _getch(); if ((key == 'q') || (key == 'Q')) { std::cout << "Завершение моделирования работы очереди..." << std::endl; break; }
		std::cout << "Состояние очереди: ";
		if (_kbhit()) key = _getch();
		output_queue(q);
	}
}

void menu(queue &q) {
	int command;
	char ch;
	while (true) {
		std::cout << "Введите номер команды:" << std::endl;
		std::cout << "1. Проверка пустоты очереди\n";
		std::cout << "2. Добавить элемент в конец очереди" << std::endl;
		std::cout << "3. Удалить элемент из начала очереди:" << std::endl;
		std::cout << "4. Запуск моделирования работы очереди" << std::endl;
		std::cout << "5. Вывод текущего состояния очереди на экран" << std::endl;
		std::cout << "0. Завершить работу программы" << std::endl;
		std::cout << "Введите номер команды: ";
		command = failure_int();

		switch (command) {
			case 1:
				if (is_Empty(q)) std::cout << "Очередь пуста" << std::endl;
				else std::cout << "Очередь не пуста" << std::endl;
				break;
			case 2:
				std::cout << "Введите элемент который хотите добавить:" << std::endl;
				std::cin >> ch;
				push_back(q, ch);
				break;
			case 3:
				std::cout << "Удаленный элемент: " << pop(q) << std::endl;
				break;
			case 4:
				modeling(q);
				break;
			case 5:
				output_queue(q);
				break;
			case 0:
				destroy(q);
				return;
				break;
		}
	}
}