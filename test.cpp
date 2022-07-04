#include "core/fancy_tree.hpp"
#include "test.hpp"

int main()
{
    Node *root = new Node(1000);
    root->_left = new Node(2753);
    root->_right = new Node(3565);
    root->_left->_left = new Node(6774);
    root->_left->_right = new Node(5676);
    root->_right->_left = new Node(6344);
    root->_right->_right = new Node(6843);
    root->_left->_left->_left = new Node(6382);
    root->_left->_left->_right = new Node(9093);
    root->_left->_right->_left = new Node(1033);
    root->_left->_right->_right = new Node(1136);
    root->_right->_left->_left = new Node(1728);
    root->_right->_left->_right = new Node(1338);
    root->_right->_right->_left = new Node(1134);
    root->_right->_right->_right = new Node(1145);
    root->_left->_left->_left->_left = new Node(2216);
    root->_left->_left->_left->_right = new Node(1457);
    root->_left->_left->_right->_left = new Node(1853);
    root->_left->_left->_right->_right = new Node(1934);
    root->_left->_right->_left->_left = new Node(2034);
    root->_left->_right->_left->_right = new Node(2143);
    root->_left->_right->_right->_left = new Node(2275);
    root->_left->_right->_right->_right = new Node(2335);
    root->_right->_left->_left->_left = new Node(2443);
    root->_right->_left->_left->_right = new Node(2543);
    root->_right->_left->_right->_left = new Node(2633);
    root->_right->_left->_right->_right = new Node(2767);
    root->_right->_right->_left->_left = new Node(2879);
    root->_right->_right->_left->_right = new Node(2996);
    root->_right->_right->_right->_left = new Node(3067);
    root->_right->_right->_right->_right = new Node(3166);
    root->_left->_left->_left->_left->_left = new Node(3662);
    root->_left->_left->_left->_left->_right = new Node(3363);
    root->_left->_left->_left->_right->_left = new Node(3435);
    root->_left->_left->_left->_right->_right = new Node(3435);
    root->_left->_left->_right->_left->_left = new Node(7836);
    root->_left->_left->_right->_left->_right = new Node(3537);
    root->_left->_left->_right->_right->_left = new Node(1138);
    root->_left->_left->_right->_right->_right = new Node(9399);
    root->_left->_right->_left->_left->_left = new Node(4000);
    root->_left->_right->_left->_left->_right = new Node(4541);
    root->_left->_right->_left->_right->_left = new Node(4642);

    print_tree(root, V_VIEW);
    print_tree(root, H_VIEW);
}