#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include "../test.hpp"

// Constants values
#define LEAFS_SPAN 2
#define NODE_WIDTH 6
#define CONTENT_LEN 4

// Node class attributes
#define LEFT _left
#define RIGHT _right
#define PARENT _parent
#define CONTENT _value

// Node class
#define NODE Node

#define TOP_LEFT_FRAME "┌───┴┐"
#define TOP_RIGHT_FRAME "┌┴───┐"
#define RIGHT_LEAF_FRAME "┌──┴─┐"
#define LEFT_LEAF_FRAME "┌─┴──┐"
#define FRAME_BOTTOM "└────┘"
#define FRAME_TOP "┌────┐"
#define NEW_LINE std::cout << std::endl
#define PRINT std::cout

int		tree_height(NODE *root)
{
	if (root == nullptr)
		return 0;
	else
	{
		int l_height = tree_height(root->LEFT);
		int r_height = tree_height(root->RIGHT);
		if (l_height > r_height)
			return (l_height + 1);
		else
			return (r_height + 1);
	}
}

int		int_len(int n)
{
	int count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return count;
}

struct Trunk
{
	Trunk *prev;
	std::string str;

	Trunk(Trunk *prev, std::string str)
	{
		this->prev = prev;
		this->str = str;
	}
};

// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
	if (p == nullptr)
	{
		return;
	}

	showTrunks(p->prev);
	std::cout << p->str;
}

void printTree(Node *root, Trunk *prev, bool isLeft)
{
	if (root == nullptr)
	{
		return;
	}

	std::string prev_str = "    ";
	Trunk *trunk = new Trunk(prev, prev_str);

	printTree(root->_right, trunk, true);

	if (!prev)
	{
		trunk->str = "───";
	}
	else if (isLeft)
	{
		trunk->str = "┌────┤";
		prev_str = "    │";
	}
	else
	{
		trunk->str = "└────┤";
		prev->str = prev_str;
	}

	showTrunks(trunk);
	std::cout << " " << root->_value << std::endl;

	if (prev)
	{
		prev->str = prev_str;
	}
	trunk->str = "    │";

	printTree(root->_left, trunk, false);
}

std::vector<NODE *>	childs_vectors_filler(std::vector<std::vector<NODE *> > vec, int level)
{
	std::vector<NODE *> childs;
	for (int i = 0; i < vec[level].size(); i++)
	{
		if (vec[level][i] == nullptr)
		{
			childs.push_back(nullptr);
			childs.push_back(nullptr);
			continue ;
		}
		if (vec[level][i]->LEFT != nullptr)
			childs.push_back(vec[level][i]->LEFT);
		else
			childs.push_back(nullptr);
		if (vec[level][i]->RIGHT != nullptr)
			childs.push_back(vec[level][i]->RIGHT);
		else
			childs.push_back(nullptr);
	}
	return childs;
}

std::vector<std::vector<NODE *> >	master_vector_filler(NODE *root, int height)
{
	std::vector<std::vector<NODE *> > vec;
	std::vector<NODE *> first;
	first.push_back(root);
	int level = 0;
	vec.push_back(first);
	while (level < height)
	{
		vec.push_back(childs_vectors_filler(vec, level));
		level++;
	}
	return vec;
}

void    set_width(int count, std::string str)
{
	for (int i = 0; i < count; i++)
		PRINT << str;
}

// might get better
void    print_node(NODE *node, bool left_child, bool right_child)
{
	if (!left_child)
		PRINT << "│";
	PRINT << node->_value;
	int len = CONTENT_LEN - int_len(node->_value);
	set_width(len, " ");
	if (!right_child)
		PRINT << "│";
}

void	print_left_branch(int len)
{
	PRINT << "┌";
	set_width(len - 1, "─");
	PRINT << "┤";
}

void	print_right_branch(int len)
{
	PRINT << "├";
	set_width(len - 1, "─");
	PRINT << "┐";
}

void	print_level(std::vector<NODE *> vec, int level, int height, int factor, int branch_len)
{
	bool is_first = true;
	for (int i = 0; i < vec.size(); i++)
	{
		int tmp = (level == height) ? (pow(2.0, factor) - (is_first ? 1 : LEAFS_SPAN)) : (is_first ? pow(2.0, factor) - 1 - branch_len : pow(2.0, factor + 1) - NODE_WIDTH - (branch_len * 2));
		set_width(tmp, " ");
		if (is_first)
			is_first = false;
		if (vec[i] == nullptr)
		{
			set_width(level == height ? NODE_WIDTH : NODE_WIDTH + branch_len * 2, " ");
			continue;
		}
		if (vec[i]->LEFT != nullptr)
			print_left_branch(branch_len);
		else
			set_width(level != height ? branch_len : 0, " ");
		print_node(vec[i], (vec[i]->LEFT != nullptr), (vec[i]->RIGHT != nullptr));
		if (vec[i]->RIGHT != nullptr)
			print_right_branch(branch_len);
		else
			set_width(level != height ? branch_len : 0, " ");
		}
	NEW_LINE;
}

void	branch_printer(int len, NODE *node)
{
	if (node != nullptr && node->LEFT != nullptr)
		PRINT << TOP_LEFT_FRAME;
	else
		set_width(NODE_WIDTH, " ");
	set_width(len - CONTENT_LEN, " ");
	if (node != nullptr && node->RIGHT != nullptr)
		PRINT << TOP_RIGHT_FRAME;
	else
		set_width(NODE_WIDTH, " ");
}

void	branch_printer_before_last(int len, NODE *node)
{
	if (node != nullptr && node->LEFT != nullptr)
		PRINT << LEFT_LEAF_FRAME;
	else
		set_width(NODE_WIDTH, " ");
	set_width(LEAFS_SPAN, " ");
	if (node != nullptr && node->RIGHT != nullptr)
		PRINT << RIGHT_LEAF_FRAME;
	else
		set_width(NODE_WIDTH, " ");
}

void	print_vertical_branches_mid(int branch_len, int factor, std::vector<NODE *> vec)
{
	bool is_first = true;
	for (size_t i = 0; i < vec.size(); i++)
	{
		set_width(is_first ? pow(2.0, factor) - 1 - branch_len : pow(2.0, factor + 1) - NODE_WIDTH - (branch_len * 2), " ");
		PRINT << ((vec[i] != nullptr && vec[i]->LEFT != nullptr) ? "│" : " ");
		set_width((branch_len * 2) + CONTENT_LEN, " ");
		PRINT << ((vec[i] != nullptr && vec[i]->RIGHT != nullptr) ? "│" : " ");
		if (is_first)
			is_first = false;
	}
	NEW_LINE;
}

void	print_leafs_frame(std::vector<NODE *> vec)
{
	bool is_first = true;
	for (size_t i = 0; i < vec.size(); i++)
	{
		set_width(is_first ? LEAFS_SPAN + 1 : LEAFS_SPAN, " ");
		if (vec[i] != nullptr)
			PRINT << FRAME_BOTTOM;
		else
			set_width(NODE_WIDTH, " ");
		if (is_first)
			is_first = false;
	}
	NEW_LINE;
}

void	print_vertical_branches_top(int branch_len, int factor, std::vector<NODE *> vec)
{
	bool is_first = true;
	for (size_t i = 0; i < vec.size(); i++)
	{
		set_width(is_first ? pow(2.0, factor) - 1 - branch_len : pow(2.0, factor + 1) - NODE_WIDTH - (branch_len * 2), " ");
		PRINT << ((vec[i] != nullptr && vec[i]->LEFT != nullptr) ? "│" : " ");
		set_width(branch_len - 1, " ");
		if (vec[i] != nullptr && vec[i] != nullptr)
			PRINT << FRAME_BOTTOM;
		else
			set_width(NODE_WIDTH, " ");
		set_width(branch_len - 1, " ");
		PRINT << ((vec[i] != nullptr && vec[i]->RIGHT != nullptr) ? "│" : " ");
		if (is_first)
			is_first = false;
	}
	NEW_LINE;
}

void	print_vertical_branches_bottom(int branch_len, int factor, std::vector<NODE *> vec, bool before_last)
{
	bool is_first = true;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (before_last)
		{
			set_width(is_first ? pow(2.0, factor) - 3 - branch_len : pow(2.0, factor + 1) - (branch_len * 2) - 10, " ");
			branch_printer_before_last((branch_len * 2) + LEAFS_SPAN, vec[i]);
		}
		else
		{
			set_width(is_first ? pow(2.0, factor) - branch_len - 5 : pow(2.0, factor + 1) - (branch_len * 2) - 14, " ");
			branch_printer((branch_len * 2) + NODE_WIDTH, vec[i]);
		}
		if (is_first)
			is_first = false;
	}
	NEW_LINE;
}

void    print_tree(NODE *root)
{
	int height = tree_height(root) - 1;
	std::vector<std::vector<NODE *> > vec = master_vector_filler(root, height);
	for (int level = 0; level < vec.size(); level++)
	{
		int factor = height - level + 2;
		int branch_len = ((pow(2.0, factor) / 2 - CONTENT_LEN) == 0) ? 2 : (pow(2.0, factor) / 2) - CONTENT_LEN;
		if (level == 0)
		{
			set_width(pow(2.0, factor) - 1, " ");
			PRINT << FRAME_TOP;
			NEW_LINE;
		}
		print_level(vec[level], level, height, factor, branch_len);
		if (level != height)
		{
			print_vertical_branches_top(branch_len, factor, vec[level]);
			print_vertical_branches_mid(branch_len, factor, vec[level]);
			print_vertical_branches_bottom(branch_len, factor, vec[level], (level == height - 1));
		}
		else
			print_leafs_frame(vec[height]);
	}
}
