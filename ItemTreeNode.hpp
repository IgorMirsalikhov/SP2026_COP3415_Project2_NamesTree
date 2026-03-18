#ifndef ITEM_TREE_NODE_HPP
#define ITEM_TREE_NODE_HPP

#include <string>
#include <iostream>

class ItemTreeNode {
public:
    std::string item_name;
    int count;

    bool operator<(const ItemTreeNode& other) {
        
    }
    bool operator>(const ItemTreeNode& other) {
        
    }
    bool operator==(const ItemTreeNode& other) {
        
    }

    friend std::ostream& operator<<(std::ostream& out, const ItemTreeNode& item) {
        
        return out;
    }
};

#endif
