#pragma once

#include <iostream>

template <typename T>
class Node {

    public:
        T           _value;
        Node<T>     *_left;
        Node<T>     *_right;
        Node<T>     *_parent;

        Node(T value)
        {
            this->_value = value;
            this->_left = nullptr;
            this->_right = nullptr;
            this->_parent = nullptr;
        }
};
