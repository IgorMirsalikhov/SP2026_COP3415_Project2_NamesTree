#ifndef NAMES_TREE_NODE_HPP
#define NAMES_TREE_NODE_HPP

#include "BST.hpp"
#include "ItemTreeNode.hpp"
#include <string>

class NamesTreeNode {
public:
    std::string name;
    BST<ItemTreeNode> items;
};


#endif
