#include "test.hpp"
#include "fancy_tree.hpp"

int main()
{
    Node<int> *root = new Node<int>(38);
    root->_left = new Node<int>(26);
    root->_right = new Node<int>(70);
    root->_left->_left = new Node<int>(6);
    root->_left->_right = new Node<int>(15);
    root->_right->_left = new Node<int>(43);
    root->_right->_right = new Node<int>(88);
    root->_left->_left->_left = new Node<int>(3);
    root->_left->_left->_right = new Node<int>(15);
    root->_left->_right->_left = new Node<int>(27);
    root->_left->_right->_right = new Node<int>(36);
    root->_right->_left->_left = new Node<int>(40);
    root->_right->_right->_left = new Node<int>(85);
    root->_right->_right->_right = new Node<int>(89);
    root->_left->_left->_right->_left = new Node<int>(12);

    // construct and object of type FancyTree
    fancy_tree<int> tree; 
    // to print in a vrtical view (root on the top mid of the tree)
    tree.print_tree(root, V_VIEW);
    // to print in a horizontal view (root on the left mid of the tree)
    tree.print_tree(root, H_VIEW);
}