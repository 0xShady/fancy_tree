#pragma once

#include <functional>
#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include "../test.hpp"

#define LEAFS_SPAN 2
#define NODE_WIDTH 6


int int_len(int n)
{
	int count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return count;
}

std::vector<Node *> childs_vectors_filler(std::vector<std::vector<Node *> > vec, int level)
{
	std::vector<Node *> childs;
	for (int i = 0; i < vec[level].size(); i++)
	{
		if (vec[level][i] == nullptr)
		{
			childs.push_back(nullptr);
			childs.push_back(nullptr);
			continue ;
		}
		if (vec[level][i]->_left != nullptr)
			childs.push_back(vec[level][i]->_left);
		else
			childs.push_back(nullptr);
		if (vec[level][i]->_right != nullptr)
			childs.push_back(vec[level][i]->_right);
		else
			childs.push_back(nullptr);
	}
	return childs;
}

std::vector<std::vector<Node *> >	master_vector_filler(Node *root, int height)
{
	std::vector<std::vector<Node *> > vec;
	std::vector<Node *> first;
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

void    separator(int count, std::string str)
{
	for (int i = 0; i < count; i++)
		std::cout << str;
}

void    print_node(Node *node)
{
	if (node == nullptr)
		std::cout << "NULL";
	else
	{
		std::cout << node->_value;
		int len = 4 - int_len(node->_value);
		separator(len, " ");
	}
}

void	print_left_branch(int len)
{
	std::cout << "┌";
	separator(len - 1, "─");
	std::cout << "┤";
}

void	print_right_branch(int len)
{
	std::cout << "├";
	separator(len - 1, "─");
	std::cout << "┐";
}

void	print_level(std::vector<Node *> vec, int level, int height, int factor, int branch_legth)
{
	bool is_first = true;
	for (int i = 0; i < vec.size(); i++)
	{
		int ratio;
		if (level == height)
		{
			separator(pow(2.0, factor) - (is_first ? 1 : 2), " ");
			if (vec[i] == nullptr)
			{
				separator(NODE_WIDTH, " ");
				continue;
			}
			std::cout << "│";
			print_node(vec[i]);
			std::cout << "│";
			is_first = false;
		}
		else if (is_first && level != height)
		{
			separator(pow(2.0, factor) - 1 - branch_legth, " ");
			if (vec[i] == nullptr)
			{
				separator(NODE_WIDTH, " ");
				continue;
			}
			if (vec[i]->_left != nullptr)
				print_left_branch(branch_legth);
			else
				separator(branch_legth + 1, " ");
			print_node(vec[i]);
			if (vec[i]->_right != nullptr)
				print_right_branch(branch_legth);
			else
				separator(branch_legth + 1, " ");
			is_first = false;
		}
		else
		{
			separator((pow(2.0, factor + 1)) - NODE_WIDTH - (branch_legth * 2), " ");
			if (vec[i] == nullptr)
			{
				separator(NODE_WIDTH + branch_legth * 2, " ");
				continue;
			}
			if (vec[i]->_left != nullptr)
				print_left_branch(branch_legth);
			else
			{
				separator(branch_legth, " ");
				std::cout << "│";
			}
			print_node(vec[i]);
			if (vec[i]->_right != nullptr)
				print_right_branch(branch_legth);
			else
			{
				std::cout << "│";
				separator(branch_legth, " ");
			}
		}
	}
}

void	branch_printer(int len, Node *node)
{
	if (node != nullptr && node->_left != nullptr)
	{
		std::cout << "┌";
		separator(3, "─");
		std::cout << "┴";
		std::cout << "┐";
	}
	else
		separator(NODE_WIDTH, " ");
	separator(len - 4, " ");
	if (node != nullptr && node->_right != nullptr)
	{
		std::cout << "┌";
		std::cout << "┴";
		separator(3, "─");
		std::cout << "┐";
	}
	else
		separator(NODE_WIDTH, " ");
}

void	branch_printer_before_last(int len, Node *node)
{
	if (node != nullptr && node->_left != nullptr)
	{
		std::cout << "┌";
		std::cout << "─";
		std::cout << "┴";
		separator(2, "─");
		std::cout << "┐";
	}
	else
		separator(NODE_WIDTH, " ");
	separator(2, " ");
	if (node != nullptr && node->_right != nullptr)
	{
		std::cout << "┌";
		separator(2, "─");
		std::cout << "┴";
		std::cout << "─";
		std::cout << "┐";
	}
	else
		separator(NODE_WIDTH, " ");
}

void	print_vertical_branches_mid(int branch_legth, int factor, std::vector<Node *> vec)
{
	bool is_first = true;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (is_first)
		{
			separator(pow(2.0, factor) - 1 - branch_legth, " ");
			if (vec[i] != nullptr && vec[i]->_left != nullptr)
				std::cout << "│";
			else
				std::cout << " ";
			separator((branch_legth * 2) + 4, " ");
			if (vec[i] != nullptr && vec[i]->_right != nullptr)
				std::cout << "│";
			else
				std::cout << " ";
			is_first = false;
		}
		else
		{
			separator((pow(2.0, factor + 1)) - NODE_WIDTH - (branch_legth * 2), " ");
			if (vec[i] != nullptr && vec[i]->_left != nullptr)
				std::cout << "│";
			else
				std::cout << " ";
			separator((branch_legth * 2) + 4, " ");
			if (vec[i] != nullptr && vec[i]->_right != nullptr)
				std::cout << "│";
			else
				std::cout << " ";
		}
	}
}

void	print_leafs_frame(std::vector<Node *> vec)
{
	bool is_first = true;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (is_first)
		{
			separator(3, " ");
			if (vec[i] != nullptr)
			{
				std::cout << "└";
				separator(4, "─");
				std::cout << "┘";
			}
			else
				separator(NODE_WIDTH, " ");
			is_first = false;
		}
		else
		{
			separator(2, " ");
			if (vec[i] != nullptr)
			{
				std::cout << "└";
				separator(4, "─");
				std::cout << "┘";
			}
			else
				separator(NODE_WIDTH, " ");
		}
	}
}

void	print_vertical_branches_top(int branch_legth, int factor, std::vector<Node *> vec, bool before_last)
{
	bool is_first = true;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (is_first)
		{
			separator(pow(2.0, factor) - 1 - branch_legth, " ");
			if (vec[i] != nullptr && vec[i]->_left != nullptr)
				std::cout << "│";
			else
				std::cout << " ";
			separator(branch_legth -  1, " ");
			if (vec[i] != nullptr && vec[i] != nullptr)
			{
				std::cout << "└";
				separator(4, "─");
				std::cout << "┘";
			}
			else
				separator(NODE_WIDTH, " ");
			separator(branch_legth - 1, " ");
			if (vec[i] != nullptr && vec[i]->_right != nullptr)
				std::cout << "│";
			else
				std::cout << " ";
			is_first = false;
		}
		else
		{
			separator((pow(2.0, factor + 1)) - NODE_WIDTH - (branch_legth * 2), " ");
			if (vec[i] != nullptr && vec[i]->_left != nullptr)
				std::cout << "│";
			else
				std::cout << " ";
			separator(branch_legth - 1, " ");
			if (vec[i] != nullptr && vec[i] != nullptr)
			{
				std::cout << "└";
				separator(4, "─");
				std::cout << "┘";
			}
			else
				separator(NODE_WIDTH, " ");
			separator(branch_legth - 1, " ");
			if (vec[i] != nullptr && vec[i]->_right != nullptr)
				std::cout << "│";
			else
				std::cout << " ";
		}
	}
}

void	print_vertical_branches_bottom(int branch_legth, int factor, std::vector<Node *> vec, bool before_last)
{
	bool is_first = true;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (is_first)
		{
			if (before_last)
			{
				separator(pow(2.0, factor) - 3 - branch_legth, " ");
				branch_printer_before_last((branch_legth * 2) + 2, vec[i]);
			}
			else
			{
				separator(pow(2.0, factor) - branch_legth - 5, " ");
				branch_printer((branch_legth * 2) + NODE_WIDTH, vec[i]);
			}
			is_first = false;
		}
		else
		{
			if (before_last)
			{
				separator(pow(2.0, factor + 1) - (branch_legth * 2) - 10, " ");
				branch_printer_before_last((branch_legth * 2) + 2, vec[i]);
			}
			else
			{
				separator(pow(2.0, factor + 1) - (branch_legth * 2) - 14, " ");
				branch_printer((branch_legth * 2) + NODE_WIDTH, vec[i]);
			}
		}
	}
}


void    print_tree(Node *root)
{
	int height = 5;
	std::vector<std::vector<Node *> > vec = master_vector_filler(root, height);
	// for (auto &i : vec)
	// {
	//     for (auto &j : i)
	//     {
	//         std::cout << j << " ";
	//     }
	//     std::cout << std::endl;
	// }
	// while (1)
	// {
	// 	/* code */
	// }
	
	for (int level = 0; level < vec.size(); level++)
	{
		int factor = height - level + 2;
		int branch_legth = ((pow(2.0, factor) / 2 - 4) == 0) ? 2 : (pow(2.0, factor) / 2) - 4;
		if (level == 0)
		{
			separator(pow(2.0, factor) - 1, " ");
			std::cout << "┌";
			separator(4, "─");
			std::cout << "┐";
			std::cout << std::endl;
		}
		print_level(vec[level], level, height, factor, branch_legth);
		std::cout << std::endl;
		if (level != height)
		{
			print_vertical_branches_top(branch_legth, factor, vec[level], (level == height - 1));
			std::cout << std::endl;
			print_vertical_branches_mid(branch_legth, factor, vec[level]);
			std::cout << std::endl;
			print_vertical_branches_bottom(branch_legth, factor, vec[level], (level == height - 1));
		}
		else
			print_leafs_frame(vec[height]);
		std::cout << std::endl;
	}
}
