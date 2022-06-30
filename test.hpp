#pragma once

class Node {
    public:
        int     _value;
        Node*   _left;
        Node*   _right;
        Node*   _parent;

        Node(int value)
        {
            this->_value = value;
            this->_left = nullptr;
            this->_right = nullptr;
            this->_parent = nullptr;
        }
};