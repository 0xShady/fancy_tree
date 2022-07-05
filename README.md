# Fancy Tree

## The right way to log a Binary search tree

![sample](./assets/sample.gif)

## How to use fancy tree

In `fancy_tree.hpp line:9` include the header file with the definition of your node (`test.hpp` in our case).

```c++
#include <string>
#include <iostream>
#include <vector>
#include <cmath>

//header file that contains Node definition
#include "test.hpp"
```
Replace the flowing macros definition according to your Node definition `fancy_tree.hpp line:20`

```c++
// Node class
#define NODE Node

// Node class attributes
#define LEFT _left
#define RIGHT _right
#define PARENT _parent
#define CONTENT _value
```

According to this defnition in our test file `test.hpp`

```c++
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
```

By running the following test `test.cpp` 

```c++
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