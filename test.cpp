#include "core/fancy_tree.hpp"
#include "test.hpp"

int main()
{
    // Construct above tree
    Node *root = new Node(1);
    root->_left = new Node(2);
    root->_right = new Node(3);
    root->_left->_left = new Node(4);
    root->_left->_right = new Node(5);
    root->_right->_left = new Node(6);
    root->_right->_right = new Node(7);
    root->_left->_left->_left = new Node(8);
    root->_left->_left->_right = new Node(9);
    root->_left->_right->_left = new Node(10);
    root->_left->_right->_right = new Node(11);
    root->_right->_left->_left = new Node(12);
    root->_right->_left->_right = new Node(13);
    root->_right->_right->_left = new Node(14);
    root->_right->_right->_right = new Node(15);
    root->_left->_left->_left->_left = new Node(16);
    root->_left->_left->_left->_right = new Node(17);
    root->_left->_left->_right->_left = new Node(18);
    root->_left->_left->_right->_right = new Node(19);
    root->_left->_right->_left->_left = new Node(20);
    root->_left->_right->_left->_right = new Node(21);
    root->_left->_right->_right->_left = new Node(22);
    root->_left->_right->_right->_right = new Node(23);
    root->_right->_left->_left->_left = new Node(24);
    root->_right->_left->_left->_right = new Node(25);
    root->_right->_left->_right->_left = new Node(26);
    root->_right->_left->_right->_right = new Node(27);
    root->_right->_right->_left->_left = new Node(28);
    root->_right->_right->_left->_right = new Node(29);
    root->_right->_right->_right->_left = new Node(30);
    root->_right->_right->_right->_right = new Node(31);
    print_tree(root);

    // std::cout << ">>" << root->_left->_left->_left->_value << std::endl;
    // std::cout << ">>" << root->_right->_right->_right->_value << std::endl;

    // print_tree(root);
    // for (auto &i : res)
    // {
    //     for (auto &j : i)
    //     {
    //         std::cout << j << " ";
    //     }
    //     std::cout << std::endl;
    // }
}