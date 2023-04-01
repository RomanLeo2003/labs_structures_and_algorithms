#pragma once
#pragma once
#include <iostream>
#include <string>
#include <ctime>


typedef struct TreeNode {
	int data{};
	TreeNode* left{ nullptr };
	TreeNode* right{ nullptr };
};

typedef struct Stack {
	int level = -1;
	TreeNode* data{};
	Stack *next{ nullptr };
};

void add_to_tree(TreeNode *&root, int new_data);
TreeNode* find(TreeNode *root, int search_data);
void menu();
int get_number();
void build_tree(TreeNode *&root, int n);
void iter_in_order(TreeNode *&root);
void in_order(TreeNode *root, int level);
void post_order(TreeNode *root, int level);
void pre_order(TreeNode *root, int level);
void destroy(TreeNode *&root);