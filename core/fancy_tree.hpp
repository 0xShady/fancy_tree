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
			std::cout << "│";
			print_node(vec[i]);
			std::cout << "│";
			is_first = false;
		}
		else if (is_first && level != height)
		{
			separator(pow(2.0, factor) - 1 - branch_legth, " ");
			print_left_branch(branch_legth);
			print_node(vec[i]);
			print_right_branch(branch_legth);
			is_first = false;
		}
		else
		{
			separator((pow(2.0, factor + 1)) - 6 - (branch_legth * 2), " ");
			print_left_branch(branch_legth);
			print_node(vec[i]);
			print_right_branch(branch_legth);
		}
	}
}

void	branch_printer(int len)
{
	std::cout << "┌";
	separator(3, "─");
	std::cout << "┴";
	std::cout << "┐";
	separator(len - 4, " ");
	std::cout << "┌";
	std::cout << "┴";
	separator(3, "─");
	std::cout << "┐";
}

void	branch_printer_before_last(int len)
{
	std::cout << "┌";
	std::cout << "─";
	std::cout << "┴";
	separator(2, "─");
	std::cout << "┐";
	separator(2, " ");
	std::cout << "┌";
	separator(2, "─");
	std::cout << "┴";
	std::cout << "─";
	std::cout << "┐";
}

void print_vertical_branches_mid(int branch_legth, int factor, int num_of_branches, bool before_last)
{
	bool is_first = true;
	for (size_t i = 0; i < num_of_branches / 2; i++)
	{
		if (is_first)
		{
			separator(pow(2.0, factor) - 1 - branch_legth, " ");
			std::cout << "│";
			separator((branch_legth * 2) + 4, " ");
			std::cout << "│";
			is_first = false;
		}
		else
		{
			separator((pow(2.0, factor + 1)) - 6 - (branch_legth * 2), " ");
			std::cout << "│";
			separator((branch_legth * 2) + 4, " ");
			std::cout << "│";
		}
	}
}

void print_leafs_frame(int num_of_leafs)
{
	bool is_first = true;
	for (size_t i = 0; i < num_of_leafs / 2; i++)
	{
		if (is_first)
		{
			separator(3, " ");
			std::cout << "└";
			separator(4, "─");
			std::cout << "┘";
			separator(2, " ");
			std::cout << "└";
			separator(4, "─");
			std::cout << "┘";
			is_first = false;
		}
		else
		{
			separator(2, " ");
			std::cout << "└";
			separator(4, "─");
			std::cout << "┘";
			separator(2, " ");
			std::cout << "└";
			separator(4, "─");
			std::cout << "┘";
		}
	}
}

void print_vertical_branches_top(int branch_legth, int factor, int num_of_branches, bool before_last)
{
	bool is_first = true;
	for (size_t i = 0; i < num_of_branches / 2; i++)
	{
		if (is_first)
		{
			separator(pow(2.0, factor) - 1 - branch_legth, " ");
			std::cout << "│";
			separator(branch_legth -  1, " ");
			std::cout << "└";
			separator(4, "─");
			std::cout << "┘";
			separator(branch_legth - 1, " ");
			std::cout << "│";
			is_first = false;
		}
		else
		{
			separator((pow(2.0, factor + 1)) - 6 - (branch_legth * 2), " ");
			std::cout << "│";
			separator(branch_legth - 1, " ");
			std::cout << "└";
			separator(4, "─");
			std::cout << "┘";
			separator(branch_legth - 1, " ");
			std::cout << "│";
		}
	}
}

void	print_vertical_branches_bottom(int branch_legth, int factor, int num_of_branches, bool before_last)
{
	bool is_first = true;
	for (size_t i = 0; i < num_of_branches / 2; i++)
	{
		if (is_first)
		{
			if (before_last)
			{
				separator(pow(2.0, factor) - 3 - branch_legth, " ");
				branch_printer_before_last((branch_legth * 2) + 2);
			}
			else
			{
				separator(pow(2.0, factor) - branch_legth - 5, " ");
				branch_printer((branch_legth * 2) + 6);
			}
			is_first = false;
		}
		else
		{
			if (before_last)
			{
				separator(pow(2.0, factor + 1) - (branch_legth * 2) - 10, " ");
				branch_printer_before_last((branch_legth * 2) + 2);
			}
			else
			{
				separator(pow(2.0, factor + 1) - (branch_legth * 2) - 14, " ");
				branch_printer((branch_legth * 2) + 6);
			}
		}
	}
}


void    print_tree(Node *root)
{
	int height = 5;
	std::vector<std::vector<Node *> > vec = master_vector_filler(root, height);
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
			print_vertical_branches_top(branch_legth, factor, vec[level].size() * 2, (level == height - 1));
			std::cout << std::endl;
			print_vertical_branches_mid(branch_legth, factor, vec[level].size() * 2, (level == height - 1));
			std::cout << std::endl;
			print_vertical_branches_bottom(branch_legth, factor, vec[level].size() * 2, (level == height - 1));
		}
		else
			print_leafs_frame(vec[level].size());
		std::cout << std::endl;
	}
}
