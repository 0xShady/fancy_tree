#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <cmath>

//header file that contains Node definition
#include "test.hpp"

// Constants values
#define LEAFS_SPAN 2
#define NODE_WIDTH 6
#define CONTENT_LEN 4

// parameter flags
#define H_VIEW 0x00
#define V_VIEW 0x01

// Node class
#define NODE Node

// Node class attributes
#define LEFT _left
#define RIGHT _right
#define PARENT _parent
#define CONTENT _value


// vertical view
#define TOP_LEFT_FRAME "┌───┴┐"
#define TOP_RIGHT_FRAME "┌┴───┐"
#define RIGHT_LEAF_FRAME "┌──┴─┐"
#define LEFT_LEAF_FRAME "┌─┴──┐"
#define FRAME_BOTTOM "└────┘"
#define FRAME_TOP "┌────┐"

// horizontal view
#define BIG_TRUNK "    │"
#define SMALL_TRUNK "   │"
#define LEFT_TRUNK "┌──┤"
#define RIGHT_TRUNK "└──┤"
#define BIG_SPAN "    "
#define SMALL_SPAN "   "
#define ROOT_TRUNK "──┤"

// frequently used
#define NEW_LINE std::endl
#define PRINT std::cout

// helper linked list
struct	Branch
{
	Branch		*prev;
	std::string	str;

	Branch(Branch *prev, std::string str)
	{
		this->prev = prev;
		this->str = str;
	}
};

// fill tree in vector
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
	int level = 0;
	std::vector<std::vector<NODE *> > vec;
	std::vector<NODE *> first;
	first.push_back(root);
	vec.push_back(first);
	while (level < height)
	{
		vec.push_back(childs_vectors_filler(vec, level));
		level++;
	}
	return vec;
}

// helper functions 
void    set_width(int count, std::string str)
{
	for (int i = 0; i < count; i++)
		PRINT << str;
}

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

void    print_node(NODE *node, bool left_child, bool right_child)
{
	if (!left_child)
		PRINT << "│";
	PRINT << " ";
	PRINT << node->CONTENT;
	int len = 3 - int_len(node->CONTENT);
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

// horizontal view
void	showbranches(Branch *p)
{
	if (p == nullptr)
		return;
	showbranches(p->prev);
    if (p->str == BIG_SPAN && p->prev && p->prev->str == BIG_TRUNK)
        PRINT << SMALL_SPAN;
    else if (p->str == BIG_TRUNK && p->prev && p->prev->str == BIG_TRUNK)
        PRINT << SMALL_TRUNK;
    else
    	PRINT << p->str;
}

void	print_tree_horizontal_view(NODE *root, Branch *prev, bool is_left)
{
	if (root == nullptr)
		return;

    std::string	prev_str = BIG_SPAN;
	Branch *branch = new Branch(prev, prev_str);

	print_tree_horizontal_view(root->RIGHT, branch, true);
	if (!prev)
		branch->str = ROOT_TRUNK;
	else if (is_left)
	{
		branch->str = LEFT_TRUNK;
		prev_str = BIG_TRUNK;
	}
	else
	{
		branch->str = RIGHT_TRUNK;
		prev->str = prev_str;
	}
	showbranches(branch);
	PRINT << root->CONTENT << std::endl;
	if (prev)
		prev->str = prev_str;
	branch->str = BIG_TRUNK;
	print_tree_horizontal_view(root->LEFT, branch, false);
}

// vertical view
void	print_level(std::vector<NODE *> vec, int level, int height, int factor, int branch_len)
{
	bool is_first = true;
	for (int i = 0; i < vec.size(); i++)
	{
		set_width(level == height ? (pow(2.0, factor) - (is_first ? 1 : LEAFS_SPAN)) : (is_first ? pow(2.0, factor) - 1 - branch_len : pow(2.0, factor + 1) - NODE_WIDTH - (branch_len * 2)), " ");
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
	PRINT << NEW_LINE;
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
	PRINT << NEW_LINE;
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
	PRINT << NEW_LINE;
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
	PRINT << NEW_LINE;
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
	PRINT << NEW_LINE;
}

void    print_tree_vertical_view(std::vector<std::vector<NODE *> > vec, int height)
{
	for (int level = 0; level < vec.size(); level++)
	{
		int factor = height - level + 2;
		int branch_len = ((pow(2.0, factor) / 2 - CONTENT_LEN) == 0) ? 2 : (pow(2.0, factor) / 2) - CONTENT_LEN;
		if (level == 0)
		{
			set_width(pow(2.0, factor) - 1, " ");
			PRINT << FRAME_TOP;
			PRINT << NEW_LINE;
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

void	print_tree(NODE *root, int flags)
{
	PRINT << NEW_LINE;
	int height = tree_height(root) - 1;
	std::vector<std::vector<NODE *> > vec = master_vector_filler(root, height);
	if (flags == V_VIEW)
		print_tree_vertical_view(vec, height);
	else if (flags == H_VIEW)
		print_tree_horizontal_view(root, nullptr, false);
	PRINT << NEW_LINE;
}