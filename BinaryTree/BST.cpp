#include "BST.h"
#include <map>
#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>

struct BST::Node
{
    KeyType key;
    ItemType item;
    Node* leftChild;
    Node* rightChild;

    Node(KeyType kt, ItemType it)
    {
        key = kt;
        item = it;
        leftChild = nullptr;
        rightChild = nullptr;

        //rightChild = leaf(); This gives error "Node* can't be assigned to Node*"
    }
};

BST::Node* BST::leaf()
{
    return nullptr;
}
bool BST::isLeaf(Node* n)
{
    return (n == nullptr);
}

BST::ItemType *BST::lookup(BST::KeyType keySought)
{
    Node* currentNode = root;

    while(true)
    {
        if(currentNode->key == keySought)
        {
            break;
        } else if (isLeaf(currentNode))
        {
            return nullptr;
        } else if(currentNode->key > keySought)
        {
            currentNode = currentNode->leftChild;
        } else if(currentNode->key < keySought)
        {
            currentNode = currentNode->rightChild;
        }
    }

    return &currentNode->item;
}

void BST::insert(BST::KeyType newKey, BST::ItemType newItem)
{
    Node* currentNode = root;
    Node* previousNode{};
    bool lastRight{};

    // Only triggered with first insert
    if(isLeaf(root))
    {
        root = new Node(newKey, newItem);
        ++treeSize;
        return;
    }

    while(true)
    {
        if (isLeaf(currentNode))
        {
            if (lastRight) {
                previousNode->rightChild = new Node(newKey, newItem);
            } else {
                previousNode->leftChild = new Node(newKey, newItem);
            }
            return;
        }
        else if (currentNode->key == newKey)
        {
            // Overwriting existing value
            currentNode = new Node(newKey, newItem);
            ++treeSize;
            return;
        }
        else if (currentNode->key > newKey)
        {
            previousNode = currentNode;
            currentNode = currentNode->leftChild;
            lastRight = false;
        }
        else if (currentNode->key < newKey)
        {
            previousNode = currentNode;
            currentNode = currentNode->rightChild;
            lastRight = true;
        }
    }
}

void BST::displayEntries()
{
    // Data structures required for traversing and sorting
    std::stack<Node*> elements;
    std::vector<std::pair <KeyType,ItemType>> sorted;

    // Add root
    elements.push(root);

    // Traverse
    while(!elements.empty())
    {
        auto* node = elements.top();

        // Store into vector to sort later
        sorted.emplace_back(std::make_pair(node->key, node->item));

        elements.pop();

        if (node->rightChild)
        {
            elements.push(node->rightChild);
        }
        if (node->leftChild)
        {
            elements.push(node->leftChild);
        }
    }

    // Sort vector
    std::sort(sorted.begin(), sorted.end());

    // Display
    for(auto& item : sorted)
    {
        std::cout << '(' << item.first << ", " << item.second << ')' << std::endl;
    }
}

BST::BST() = default;
BST::~BST()
{
    // Data structures required for traversing and storing values
    std::stack<Node*> elements;

    // Add root
    elements.push(root);

    // Traverse
    while (!elements.empty())
    {
        auto* node = elements.top();
        elements.pop();

        if (node->rightChild)
        {
            elements.push(node->rightChild);
        }
        if (node->leftChild)
        {
            elements.push(node->leftChild);
        }

        delete(node);
    }
}