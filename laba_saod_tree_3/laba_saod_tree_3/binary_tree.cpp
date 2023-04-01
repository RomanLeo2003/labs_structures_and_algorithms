#include "binary_tree.h"

int get_number() {
	int n = rand() % 100;
	return n;
}

TreeNode* find(TreeNode *root, int search_data) {
	if (root == nullptr) return nullptr;
	if (root->data == search_data) return root;
	find(root->right, search_data);
	find(root->left, search_data);
}

void add_to_tree(TreeNode *&root, int new_data) {
	TreeNode* new_node{ new TreeNode{} };
	new_node->data = new_data;
	if (root == nullptr) {
		root = new_node;
	}
	else {
		int search_data{};
		std::cout << "Введите элемент, относительно которого будет выполняться вставка" << std::endl;
		std::cin >> search_data;
		TreeNode *cur = find(root, search_data);
		if (cur == nullptr) {
			std::cout << "Не найдено такого элемента" << std::endl;
			return;
		}
		else if (cur->left != nullptr && cur->right != nullptr){
			std::cout << "Добавление невозможно, так как у элемента есть оба потомка" << std::endl;
		}
		else if (cur->left == nullptr && cur->right != nullptr) {
			cur->left = new_node;
			std::cout << "Новый элемент добавлен как левый потомок у элемента с инф. частью: " << cur->data << std::endl;
		}
		else if (cur->left != nullptr && cur->right == nullptr) {
			cur->right = new_node;
			std::cout << "Новый элемент добавлен как правый потомок у элемента с инф. частью: " << cur->data << std::endl;
		}
		else if (cur->left == nullptr && cur->right == nullptr) {
			int command{};
			std::cout << "0 - Вставить новый элемент как правого потомка\n1 - Вставить новый элемент как левого потомка" << std::endl;
			std::cin >> command;
			if (command == 0) {
				cur->right = new_node;
				std::cout << "Новый элемент добавлен как правый потомок у элемента с инф. частью: " << cur->data << std::endl;
			}
			else if (command == 1) {
				cur->left = new_node;
				std::cout << "Новый элемент добавлен как левый потомок у элемента с инф. частью: " << cur->data << std::endl;
			}
		}
	}
}

void build_tree(TreeNode *&root, int n) {
	if (n == 0) return;
	int n_left = n / 2;
	int n_right = n - n_left - 1;

	int new_data = get_number();
	TreeNode* new_node{ new TreeNode{} };
	new_node->data = new_data;
	std::cout << new_data << "  ";
	build_tree(new_node->left, n_left);
	build_tree(new_node->right, n_right);

	root = new_node;
}

void in_order(TreeNode *root, int level) {
	if (root == nullptr) return;

	std::cout << std::string(level, ' ') << root->data << '\n';
	in_order(root->left, level + 4);
	in_order(root->right, level + 4);

}

void pre_order(TreeNode *root, int level) {
	if (root == nullptr) return;

	pre_order(root->left, level + 4);
	std::cout << std::string(level, ' ') << root->data << '\n';
	pre_order(root->right, level + 4);

}

void post_order(TreeNode *root, int level) {
	if (root == nullptr) return;

	pre_order(root->right, level + 4);
	std::cout << std::string(level, ' ') << root->data << '\n';
	pre_order(root->left, level + 4);

}

void iter_in_order(TreeNode *&root) {
	if (!root) return;
	int level{ 0 };
	Stack *st{ new Stack };
	st->data = root;
	TreeNode* temp{ root };
	while (temp != nullptr || st->level >= 0) {
		while (temp) {
			Stack *cur{ new Stack };
			cur->next = st;
			cur->level = level;
			cur->data = temp;
			st = cur;
			temp = temp->left;
			level++;
		}
		level = st->level;
		temp = st->data;
		Stack* del{ st };
		st = st->next;
		delete del;


		std::cout << std::string(level * 4, ' ') << temp->data << '\n';

		temp = temp->right;
		level++;
	}
}

void destroy(TreeNode *&root) {
	if (root == nullptr)
		return;

	destroy(root->left);
	destroy(root->right);
	delete root;
}
