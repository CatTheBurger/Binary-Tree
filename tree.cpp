#include "tree.h"
#include <QDebug>
#include <QList>
#include <iostream>

Tree::Tree() {
    root = nullptr;
}

void Tree::Add(int value) {
    if(root == nullptr){
        root = new Node(value);
    } else {
        Node *temp = root;

        while(temp != nullptr){
            if(value > temp->value){
                if(temp->right == nullptr){
                    temp->right = new Node(value);
                    return;
                } else {
                    temp = temp->right;
                   // temp->level++;
                }
            } else if(value <= temp->value) {
                if(temp->left == nullptr){
                    temp->left = new Node(value);
                    return;
                } else {
                    temp = temp->left;
                    //temp->level++;
                }
            }
        }
    }
}

void Tree::Search(int value) {
    Node *temp = root;
    bool flag = false;

    while(temp != nullptr){
        if(temp->value == value){
            //cout << value << ":yes" << endl;
            flag = true;
            break;
        }

        if(temp != nullptr){
            if(value > temp->value) temp = temp->right;
            else temp = temp->left;
        } else {
            //cout << value << ":no" << endl;
            break;
        }
    }

    //if(!flag) cout << value << ":no" << endl;
}

void Tree::traversal1(Node *node) {
    if (node == nullptr) {
        return;
    }
    //qDebug() << node->value;
    traversal1(node->right);
    traversal1(node->left);
}

void Tree::traversal2(Node *node) {
    if (node == nullptr) {
        return;
    }

   // qDebug() << node->value;

    if (node->left != nullptr)
         traversal2(node->left);
    if (node->right != nullptr)
         traversal2(node->right);

   // qDebug() << "=============";
}

void Tree::traversal3(Node *node) {
    if (node == nullptr)
        return;

    traversal3(node->left);
    traversal3(node->right);
   // qDebug() << node->value;
}
