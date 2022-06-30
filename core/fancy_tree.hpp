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

// void    print_tree(Node *root)
// {
//     Node *tmp = root;
//     if (root == nullptr)
//         return;
//     std::cout << std::setw(20);
//     std::cout << root->_value << std::endl;

// }

// void tree_debug(const std::string &prefix, const Node *node, bool isLeft)
// {
//     if (node != NULL)
//     {
//         std::cout << prefix;
//         std::cout << (isLeft ? "├──" : "└──");
//         std::cout << "|" << node->_value << std::endl;
//         tree_debug(prefix + (isLeft ? "│   " : "    "), node->_left, true);
//         tree_debug(prefix + (isLeft ? "│   " : "    "), node->_right, false);
//     }
// }

// calculate an integer's lehn of digits
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

// void print_tree(const Node *root)
// {
//     // int level = 4;
//     std::cout << std::setw(4);
//     std::cout << root->_value;
//     std::cout << std::setw(3 - int_len(root->_value));
//     std::cout << std::setw(4);
//     // tree_debug("$", root, false);
// }


// insert tree to a vector level by level
// void insert_tree(const Node *root, std::vector<std::vector<int> > &vec)
// {
//     if (root == nullptr)
//         return;
//     std::vector<int> tmp;
//     tmp.push_back(root->_value);
//     vec.push_back(tmp);
//     insert_tree(root->_left, vec);
//     insert_tree(root->_right, vec);
// }

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

void    separator(int count, char c)
{
	for (int i = 0; i < count; i++)
		std::cout << c;
}

void    print_node(int value)
{
	std::cout << value;
	int len = 4 - int_len(value);
	separator(len, ' ');
}

void	print_left_branch(int len)
{
	std::cout << "┌";
	separator(len - 1, '-');
	std::cout << "┤";
}

void	print_right_branch(int len)
{
	std::cout << "├";
	separator(len - 1, '-');
	std::cout << "┐";
}

void	print_level(std::vector<Node *> vec, int level, int height, int factor, int branch_legth)
{
	bool is_first = true;
	// int number_of_leafs = pow(2, height);
	// std::cout << "factor: " << factor << std::endl;
	for (int i = 0; i < vec.size(); i++)
	{
		int ratio;
		if (level == height)
		{
			separator(pow(2.0, factor) - (is_first ? 1 : 2), ' ');
			std::cout << "|";
			print_node(vec[i]->_value);
			std::cout << "|";
			is_first = false;
		}
		else if (is_first && level != height)
		{
			separator(pow(2.0, factor) - 1 - branch_legth, ' ');
			print_left_branch(branch_legth);
			print_node(vec[i]->_value);
			print_right_branch(branch_legth);
			is_first = false;
		}
		else
		{
			separator((pow(2.0, factor + 1)) - 6 - (branch_legth * 2), ' ');
			print_left_branch(branch_legth);
			// std::cout << "|";
			print_node(vec[i]->_value);
			// std::cout << "|";
			print_right_branch(branch_legth);
		}
		// if (vec[i] != nullptr)
		//     print_node(vec[i]->_value, (height != level));
		// else
		//     std::cout << "|NULL|";
	}
}

void    print_tree(Node *root)
{
	int height = 4;
	std::vector<std::vector<Node *> > vec = master_vector_filler(root, height);
	for (int level = 0; level < vec.size(); level++)
	{
		int factor = height - level + 2;
		int branch_legth = (pow(2.0, factor) / 2) - 4;
		print_level(vec[level], level, height, factor, branch_legth == 0 ? 2 : branch_legth);
		std::cout << std::endl;
		std::cout << std::endl;
	}
}
