#include "binary_search_tree.h"

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	menu();
	return 0;
}

void menu() {
	int command{}, n{}, choice{};
	TreeNode* root{};
	while (true) {
		std::cout << "Введите нужную вам команду:" << std::endl;
		std::cout << "1 - Добавить новый элемент в дерево" << std::endl;
		std::cout << "2 - Построчный вывод дерева на основе процедуры обхода в прямом порядке" << std::endl;
		std::cout << "3 - Построчный вывод дерева на основе процедуры обхода в симметричном порядке" << std::endl;
		std::cout << "4 - Построчный вывод дерева на основе процедуры обхода в обратно-симметричном порядке" << std::endl;
		std::cout << "5 - Создать дерево из случайных элементов" << std::endl;
		std::cout << "6 - Очистить дерево" << std::endl;
		std::cout << "7 - Вывести элементы дерева по возрастанию с их количеством" << std::endl;
		std::cout << "8 - Удалить элемент дерева" << std::endl;
		std::cout << "0 - Завершить программу" << std::endl;

		std::cin >> command;

		switch (command) {
		case 0:
			if (root != nullptr) {
				destroy(root);
				root = nullptr;
			}
			
			return;
			break;
		case 1:
			std::cout << "Введите информационную часть нового элемента:" << std::endl;
			std::cin >> n;
			std::cout << "0 - вставить рекурсивно\n1 - вставить итеративно" << std::endl;
			std::cin >> choice;
			if (choice == 0) {
				iter_add_node(root, n);
			}
			else {
				rec_add_node(root, n);
			}
			//std::cout << "\n";
			break;
		case 2:
			in_order(root, 0);
			break;
		case 3:
			pre_order(root, 0);
			break;
		case 4:
			post_order(root, 0);
			break;
		case 5:
			std::cout << "Введите количество элементов" << std::endl;
			std::cin >> n;
			build_tree(root, n);
			break;
		case 6:
			destroy(root);
			root = nullptr;
			break;
		case 7:
			pre_order_count(root);
			std::cout << "\n";
			break;
		case 8:
			std::cout << "Введите ключ удаляемого элемента:" << std::endl;
			std::cin >> n;
			if (root != nullptr) {
				remove(root, n);
			}
			
		}
	}

}
