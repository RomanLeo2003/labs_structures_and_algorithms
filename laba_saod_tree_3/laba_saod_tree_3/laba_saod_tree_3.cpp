#include "binary_tree.h"

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	menu();
	return 0;
}

void menu() {
	int command{}, n{};
	TreeNode* root{};
	n = get_number();
	while (true) {
		std::cout << "Введите нужную вам команду:" << std::endl;
		std::cout << "1 - Добавить новый элемент в дерево" << std::endl;
		std::cout << "2 - Построчный вывод дерева на основе процедуры обхода в прямом порядке" << std::endl;
		std::cout << "3 - Построчный вывод дерева на основе процедуры обхода в симметричном порядке" << std::endl;
		std::cout << "4 - Построчный вывод дерева на основе процедуры обхода в обратно-симметричном порядке" << std::endl;
		std::cout << "5 - Построчный вывод дерева на основе процедуры обхода в симметричном порядке (итеративно)" << std::endl;
		std::cout << "6 - Очистить дерево" << std::endl;
		std::cout << "0 - Завершить программу" << std::endl;

		std::cin >> command;

		switch (command) {
		case 0:
			destroy(root);
			root = nullptr;
			return;
			break;
		case 1:
			std::cout << "Информационную часть нового элемента:" << std::endl;
			std::cin >> n;
			add_to_tree(root, n);
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
			iter_in_order(root);
			break;
		case 6:
			destroy(root);
			root = nullptr;
			break;

		}
	}

}


