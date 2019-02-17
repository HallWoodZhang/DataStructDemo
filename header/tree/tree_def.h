#ifndef TREE_H
#define TREE_H

template <typename T>
class TreeNode {
public:
    TreeNode(): firstChild(nullptr), nextSibling(nullptr) {}
    TreeNode(const T& _val): firstChild(nullptr), nextSibling(nullptr), val(_val) {}
    ~TreeNode() {
        if(firstChild != nullptr) delete firstChild;
        if(nextSibling != nullptr) delete nextSibling;
    }
    TreeNode* firstChild;
    TreeNode* nextSibling;
    T val;
};

#endif