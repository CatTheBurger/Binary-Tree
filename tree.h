#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <QList>

class Tree
{
public:
    Node *root;

    Tree();

    void Add(int value);
    void Search(int value);
    void traversal1(Node *node);
    void traversal2(Node *node);
    void traversal3(Node *node);
};

#endif // TREE_H
