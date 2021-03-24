#pragma once
#include <string>

class BST
{
public:

    BST();
    ~BST();
    using KeyType = int;
    using ItemType = std::string;

    ItemType* lookup(KeyType);
    void insert(KeyType, ItemType);
    void remove(KeyType);
    void displayEntries();

private:

    struct Node;
    int treeSize = 0;
    Node* root = leaf();

    static Node* leaf();
    static bool isLeaf(Node*);
};

