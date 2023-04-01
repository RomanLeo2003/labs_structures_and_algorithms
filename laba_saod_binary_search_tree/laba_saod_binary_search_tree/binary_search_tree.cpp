#include "binary_search_tree.h"

int get_number() {
	int n = rand() % 100;
	return n;
}

void find(TreeNode *&curr, int key) {
	while (curr != nullptr && curr->data != key)
	{
		if (key < curr->data) {
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}
	}
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
void destroy(TreeNode *&root) {
	if (root == nullptr)
		return;

	destroy(root->left);
	destroy(root->right);
	delete root;
}

void rec_add_node(TreeNode *&root, int data) {
	if (root == nullptr) return;
	TreeNode* new_node{ new TreeNode{} };
	new_node->data = data;
	new_node->count = 1;
	if (data < root->data) {
		if (!root->left) {
			root->left = new_node;
			new_node->parent = root->left;
		}
		else {
			rec_add_node(root->left, data);
		}
	}
	else if (data > root->data) {
		if (!root->right) {
			root->right = new_node;
			new_node->parent = root->right;
		}
		else {
			rec_add_node(root->right, data);
		}
	}
	else {
		std::cout << "Ёлемент " << data << " уже в дереве, увеличиваем сетчик\n";
		root->count++;
	}
}

void iter_add_node(TreeNode *&root, int data) {
	TreeNode* parent{};
	TreeNode* current{ root };
	TreeNode* new_node{};

	while (current != nullptr)
	{
		parent = current;
		if (data < current->data)
			current = current->left;
		else if (data > current->data)
			current = current->right;
		else
		{
			std::cout << "Ёлемент " << data << " уже в дереве, увеличиваем сетчик\n";
			current->count++;
			return;
		}
	}

	new_node = new TreeNode{};
	new_node->parent = parent;
	new_node->data = data;
	new_node->count = 1;

	if (parent == nullptr)
		root = new_node;
	else if (new_node->data < parent->data)
		parent->left = new_node;
	else
		parent->right = new_node;
}

void pre_order_count(const TreeNode* root) {
	if (root == nullptr)
		return;

	pre_order_count(root->left);
	std::cout << root->data << '(' << root->count << ") ";
	pre_order_count(root->right);
}

void build_tree(TreeNode *&root, int n) {
	for (int i = 0; i < n; i++) {
		int data = get_number();
		iter_add_node(root, data);
	}
}

void insert(TreeNode *&cur, TreeNode *new_node) {
	if (cur->data > new_node->data) {
		cur->left = new_node;
	}
	else if (cur->data < new_node->data) {
		cur->right = new_node;
	}
	else {
		return; ////
	}
}

TreeNode* minimum(TreeNode* cur) {
	while (cur->left != nullptr) {
		cur = cur->left;
	}
	return cur;
}

void remove(TreeNode *&root, int key)
{
	// указатель дл€ хранени€ родител€ текущего узла

	TreeNode* curr{ root };
	find(curr, key);
	TreeNode* parent { curr->parent };
 
    // возвращаем, если ключ не найден в дереве
    if (curr == nullptr) {
		std::cout << "Ќе найдено такого элемента" << std::endl;
        return;
    }
 
    // —лучай 1: удал€емый узел не имеет дочерних элементов, т. е. €вл€етс€ листовым узлом
    if (curr->left == nullptr && curr->right == nullptr)
    {
        // если удал€емый узел не €вл€етс€ корневым узлом, то устанавливаем его
        // родительский левый/правый дочерний элемент в null
        if (curr != root)
        {
            if (parent->left == curr) {
                parent->left = nullptr;
            }
            else {
                parent->right = nullptr;
            }
        }
        else {
            root = nullptr;
        }
 
        // освобождаем пам€ть
        delete curr;        // или delete curr;
    }
 
    // —лучай 2: удал€емый узел имеет двух потомков
    else if (curr->left && curr->right)
    {
        // найти его неупор€доченный узел-преемник
        TreeNode* successor = minimum(curr->right);
 
        // сохран€ем последующее значение
        int val = successor->data;
 
        // рекурсивно удал€ем преемника. ќбратите внимание, что преемник
        // будет иметь не более одного потомка (правого потомка)
        remove(root, successor->data);
 
        // копируем значение преемника в текущий узел
        curr->data = val;
    }
 
    // —лучай 3: удал€емый узел имеет только одного потомка
    else {
        // выбираем дочерний узел
        TreeNode* child = (curr->left) ? curr->left: curr->right;
 
        // если удал€емый узел не €вл€етс€ корневым узлом, устанавливаем его родител€
        // своему потомку
        if (curr != root)
        {
            if (curr == parent->left) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
        }
        else {
            root = child;
        }
        delete curr;
    }
}

/*
void remove(TreeNode *&root, int del_data) {
	TreeNode *to_del{ find(root, del_data) };
	TreeNode *current{};
	if (to_del == nullptr) {
		std::cout << "Ќе найдено такого элемента" << std::endl;
	}
	else {
		if (to_del->right == nullptr && to_del->left != nullptr) {
			current = to_del->left;
			current->parent = to_del->parent;
			insert(current->parent, current);
			delete to_del;
		}
		else if (to_del->right != nullptr && to_del->left == nullptr) {
			current = to_del->right;
			current->parent = to_del->parent;
			insert(current->parent, current);
			delete to_del;
		}
		else if (to_del->left != nullptr && to_del->right != nullptr) {  ////
			TreeNode* successor = minimum(to_del->right);

			// сохран€ем последующее значение
			int val = successor->data;

			// рекурсивно удал€ем преемника. ќбратите внимание, что преемник
			// будет иметь не более одного потомка (правого потомка)
			remove(root, successor->data);

			// копируем значение преемника в текущий узел
			to_del->data = val;
		}
		else {
			delete to_del;
		}
		// to_del = find(root, del_data);
		// if (to_del != nullptr) to_del->count--;
	}
}*/