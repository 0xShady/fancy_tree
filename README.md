# Fancy Tree

## The right way to log a Binary search tree

![sample](./assets/sample.gif)

## How to use fancy tree

In `fancy_tree.hpp line:9` include the header file with the definition of your node (`test.hpp` in our case).

```c++
//header file that contains Node definition
#include "test.hpp"
```
Replace the flowing macros according to your Node definition `fancy_tree.hpp line:20`

```c++
// Node class
#define NODE Node<T>

// Node class attributes
#define LEFT _left				// left attribute
#define RIGHT _right			// right attribute
#define PARENT _parent			// parent attribute (can be ignnored)
#define CONTENT _value			// data attribute + element of pair(if exists)
```

According to this defnition in our test file `test.hpp`

```c++
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
```

By running the following test `test.cpp` 

```c++
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
```

### Output

* Vertical view `print_tree(root, V_VIEW);`

```log
                                                               ┌────┐
                                   ┌───────────────────────────┤ 38 ├───────────────────────────┐
                                   │                           └────┘                           │
                                   │                                                            │
                               ┌───┴┐                                                          ┌┴───┐
                   ┌───────────┤ 26 ├───────────┐                                  ┌───────────┤ 70 ├───────────┐
                   │           └────┘           │                                  │           └────┘           │
                   │                            │                                  │                            │
               ┌───┴┐                          ┌┴───┐                          ┌───┴┐                          ┌┴───┐
           ┌───┤ 6  ├───┐                  ┌───┤ 15 ├───┐                  ┌───┤ 43 │                      ┌───┤ 88 ├───┐
           │   └────┘   │                  │   └────┘   │                  │   └────┘                      │   └────┘   │
           │            │                  │            │                  │                               │            │
       ┌───┴┐          ┌┴───┐          ┌───┴┐          ┌┴───┐          ┌───┴┐                          ┌───┴┐          ┌┴───┐
       │ 3  │        ┌─┤ 15 │          │ 27 │          │ 36 │          │ 40 │                          │ 85 │          │ 89 │
       └────┘        │ └────┘          └────┘          └────┘          └────┘                          └────┘          └────┘
                     │
                   ┌─┴──┐
                   │ 12 │
                   └────┘
```

* Horizontal view `print_tree(root, H_VIEW);`

```log
            ┌──┤89
        ┌──┤88
        │   └──┤85
    ┌──┤70
    │   └──┤43
    │       └──┤40
──┤38
    │       ┌──┤36
    │   ┌──┤15
    │   │   └──┤27
    └──┤26
        │   ┌──┤15
        │   │   └──┤12
        └──┤6
            └──┤3
```