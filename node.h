#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int value;
    Node *right;
    Node *left;

    Node(int v = 0);
};

#endif // NODE_H
