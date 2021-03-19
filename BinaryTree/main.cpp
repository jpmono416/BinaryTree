#include <iostream>
#include "BST.h"

int main()
{
    BST newTree;

    newTree.insert(3, "s");
    newTree.insert(5, "a");
    newTree.insert(16, "ass");
    newTree.insert(2, "rt");
    newTree.insert(4, "rtsss");

    newTree.displayEntries();
}
