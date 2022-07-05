#include "fancy_tree.hpp"

int main()
{
    Node *root = new Node(38);
    root->_left = new Node(26);
    root->_right = new Node(70);
    root->_left->_left = new Node(6);
    root->_left->_right = new Node(15);
    root->_right->_left = new Node(43);
    root->_right->_right = new Node(88);
    root->_left->_left->_left = new Node(3);
    root->_left->_left->_right = new Node(15);
    root->_left->_right->_left = new Node(27);
    root->_left->_right->_right = new Node(36);
    root->_right->_left->_left = new Node(40);
    root->_right->_right->_left = new Node(85);
    root->_right->_right->_right = new Node(89);
    root->_left->_left->_right->_left = new Node(12);

    // to print in a vrtical view (root on the top mid of the tree)
    print_tree(root, V_VIEW);
    // to print in a horizontal view (root on the left mid of the tree)
    print_tree(root, H_VIEW);
}