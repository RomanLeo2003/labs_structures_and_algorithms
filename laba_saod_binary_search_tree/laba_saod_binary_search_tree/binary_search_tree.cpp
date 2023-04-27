#include "binary_search_tree.h"

int get_number() {
	int n = rand() % 100;
	return n;
}

void find(TreeNode *&curr, int key) {
	while (curr != nullptr && curr->data != key) {
		if (key < curr->data) {
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}
	}
}

void in_order(const TreeNode *root, int level) {
	if (root == nullptr) return;

	std::cout << std::string(level, ' ') << root->data << '\n';
	in_order(root->left, level + 4);
	in_order(root->right, level + 4);

}

void pre_order(const TreeNode *root, int level) {
	if (root == nullptr) return;

	pre_order(root->left, level + 4);
	std::cout << std::string(level, ' ') << root->data << '\n';
	pre_order(root->right, level + 4);

}

void post_order(const TreeNode *root, int level) {
	if (root == nullptr) return;

	post_order(root->right, level + 4);
	std::cout << std::string(level, ' ') << root->data << '\n';
	post_order(root->left, level + 4);

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
		std::cout << "Элемент " << data << " уже в дереве, увеличиваем сетчик\n";
		root->count++;
	}
}

void iter_add_node(TreeNode *&root, int data) {
	TreeNode* parent{};
	TreeNode* current{ root };
	TreeNode* new_node{};

	while (current != nullptr) {
		parent = current;
		if (data < current->data)
			current = current->left;
		else if (data > current->data)
			current = current->right;
		else {
			std::cout << "Элемент " << data << " уже в дереве, увеличиваем сетчик\n";
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
	//root = new TreeNode;
	for (int i = 0; i < n; i++) {
		iter_add_node(root, get_number());
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
	TreeNode* curr{ root };
	find(curr, key);
	if (curr == nullptr) {
		std::cout << "Не найдено такого элемента" << std::endl;
		return;
	}
	TreeNode* parent { curr->parent };
    if (curr->left == nullptr && curr->right == nullptr) {
        if (curr != root) {
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
		curr->count--;
        delete curr;
    }
    else if (curr->left && curr->right) {
        TreeNode* successor = minimum(curr->right);
        int val = successor->data;
        remove(root, successor->data);
        curr->data = val;  ///
    }
    else {
        TreeNode* child = (curr->left) ? curr->left: curr->right;
        if (curr != root) {
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
		curr->count--;
        delete curr;
    }
}