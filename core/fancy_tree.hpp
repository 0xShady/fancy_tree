#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include "../test.hpp"

#define LEAFS_SPAN 2
#define NODE_WIDTH 6
#define CONTENT_LEN 4
#define LEFT _left
#define RIGHT _right
#define PARENT _parent
#define NODE Node
#define NEW_LINE std::cout << std::endl;
#define TOP_LEFT_FRAME "┌───┴┐"
#define TOP_RIGHT_FRAME "┌┴───┐"
#define RIGHT_LEAF_FRAME "┌──┴─┐"
#define LEFT_LEAF_FRAME "┌─┴──┐"
#define FRAME_BOTTOM "└────┘"
#define FRAME_TOP "┌────┐"

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
		std::cout << str;
}

// might get better
void    print_node(NODE *node)
{
	if (node == nullptr)
		std::cout << "NULL";
	else
	{
		std::cout << node->_value;
		int len = CONTENT_LEN - int_len(node->_value);
		set_width(len, " ");
	}
}

void	print_left_branch(int len)
{
	std::cout << "┌";
	set_width(len - 1, "─");
	std::cout << "┤";
}

void	print_right_branch(int len)
{
	std::cout << "├";
	set_width(len - 1, "─");
	std::cout << "┐";
}

void	print_level(std::vector<NODE *> vec, int level, int height, int factor, int branch_len)
{
	bool is_first = true;
	for (int i = 0; i < vec.size(); i++)
	{
		int ratio;
		if (level == height)
		{
			set_width(pow(2.0, factor) - (is_first ? 1 : 2), " ");
			if (vec[i] == nullptr)
			{
				set_width(NODE_WIDTH, " ");
				continue;
			}
			std::cout << "│";
			print_node(vec[i]);
			std::cout << "│";
			is_first = false;
		}
		else if (is_first && level != height)
		{
			set_width(pow(2.0, factor) - 1 - branch_len, " ");
			if (vec[i] == nullptr)
			{
				set_width(NODE_WIDTH, " ");
				continue;
			}
			if (vec[i]->LEFT != nullptr)
				print_left_branch(branch_len);
			else
				set_width(branch_len + 1, " ");
			print_node(vec[i]);
			if (vec[i]->RIGHT != nullptr)
				print_right_branch(branch_len);
			else
				set_width(branch_len + 1, " ");
			is_first = false;
		}
		else
		{
			set_width((pow(2.0, factor + 1)) - NODE_WIDTH - (branch_len * 2), " ");
			if (vec[i] == nullptr)
			{
				set_width(NODE_WIDTH + branch_len * 2, " ");
				continue;
			}
			if (vec[i]->LEFT != nullptr)
				print_left_branch(branch_len);
			else
			{
				set_width(branch_len, " ");
				std::cout << "│";
			}
			print_node(vec[i]);
			if (vec[i]->RIGHT != nullptr)
				print_right_branch(branch_len);
			else
			{
				std::cout << "│";
				set_width(branch_len, " ");
			}
		}
	}
	NEW_LINE;
}

void	branch_printer(int len, NODE *node)
{
	if (node != nullptr && node->LEFT != nullptr)
		std::cout << TOP_LEFT_FRAME;
	else
		set_width(NODE_WIDTH, " ");
	set_width(len - CONTENT_LEN, " ");
	if (node != nullptr && node->RIGHT != nullptr)
		std::cout << TOP_RIGHT_FRAME;
	else
		set_width(NODE_WIDTH, " ");
}

void	branch_printer_before_last(int len, NODE *node)
{
	if (node != nullptr && node->LEFT != nullptr)
		std::cout << LEFT_LEAF_FRAME;
	else
		set_width(NODE_WIDTH, " ");
	set_width(LEAFS_SPAN, " ");
	if (node != nullptr && node->RIGHT != nullptr)
		std::cout << RIGHT_LEAF_FRAME;
	else
		set_width(NODE_WIDTH, " ");
}

void	print_vertical_branches_mid(int branch_len, int factor, std::vector<NODE *> vec)
{
	bool is_first = true;

	for (size_t i = 0; i < vec.size(); i++)
	{
		if (is_first)
		{
			set_width(pow(2.0, factor) - 1 - branch_len, " ");
			std::cout << ((vec[i] != nullptr && vec[i]->LEFT != nullptr) ? "│" : " ");
			set_width((branch_len * 2) + CONTENT_LEN, " ");
			std::cout << ((vec[i] != nullptr && vec[i]->RIGHT != nullptr) ? "│" : " ");
			is_first = false;
		}
		else
		{
			set_width((pow(2.0, factor + 1)) - NODE_WIDTH - (branch_len * 2), " ");
			std::cout << ((vec[i] != nullptr && vec[i]->LEFT != nullptr) ? "│" : " ");
			set_width((branch_len * 2) + CONTENT_LEN, " ");
			std::cout << ((vec[i] != nullptr && vec[i]->RIGHT != nullptr) ? "│" : " ");
		}
	}
	NEW_LINE;
}

void	print_leafs_frame(std::vector<NODE *> vec)
{
	bool is_first = true;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (is_first)
		{
			set_width(LEAFS_SPAN + 1, " ");
			if (vec[i] != nullptr)
				std::cout << FRAME_BOTTOM;
			else
				set_width(NODE_WIDTH, " ");
			is_first = false;
		}
		else
		{
			set_width(LEAFS_SPAN, " ");
			if (vec[i] != nullptr)
				std::cout << FRAME_BOTTOM;
			else
				set_width(NODE_WIDTH, " ");
		}
	}
	NEW_LINE;
}

void	print_vertical_branches_top(int branch_len, int factor, std::vector<NODE *> vec)
{
	bool is_first = true;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (is_first)
		{
			set_width(pow(2.0, factor) - 1 - branch_len, " ");
			std::cout << ((vec[i] != nullptr && vec[i]->LEFT != nullptr) ? "│" : " ");
			set_width(branch_len - 1, " ");
			if (vec[i] != nullptr && vec[i] != nullptr)
				std::cout << FRAME_BOTTOM;
			else
				set_width(NODE_WIDTH, " ");
			set_width(branch_len - 1, " ");
			std::cout << ((vec[i] != nullptr && vec[i]->RIGHT != nullptr) ? "│" : " ");
			is_first = false;
		}
		else
		{
			set_width((pow(2.0, factor + 1)) - NODE_WIDTH - (branch_len * 2), " ");
			std::cout << ((vec[i] != nullptr && vec[i]->LEFT != nullptr) ? "│" : " ");
			set_width(branch_len - 1, " ");
			if (vec[i] != nullptr && vec[i] != nullptr)
				std::cout << FRAME_BOTTOM;
			else
				set_width(NODE_WIDTH, " ");
			set_width(branch_len - 1, " ");
			std::cout << ((vec[i] != nullptr && vec[i]->RIGHT != nullptr) ? "│" : " ");
		}
	}
	NEW_LINE;
}

void	print_vertical_branches_bottom(int branch_len, int factor, std::vector<NODE *> vec, bool before_last)
{
	bool is_first = true;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (is_first)
		{
			if (before_last)
			{
				set_width(pow(2.0, factor) - 3 - branch_len, " ");
				branch_printer_before_last((branch_len * 2) + 2, vec[i]);
			}
			else
			{
				set_width(pow(2.0, factor) - branch_len - 5, " ");
				branch_printer((branch_len * 2) + NODE_WIDTH, vec[i]);
			}
			is_first = false;
		}
		else
		{
			if (before_last)
			{
				set_width(pow(2.0, factor + 1) - (branch_len * 2) - 10, " ");
				branch_printer_before_last((branch_len * 2) + 2, vec[i]);
			}
			else
			{
				set_width(pow(2.0, factor + 1) - (branch_len * 2) - 14, " ");
				branch_printer((branch_len * 2) + NODE_WIDTH, vec[i]);
			}
		}
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
			std::cout << FRAME_TOP;
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
