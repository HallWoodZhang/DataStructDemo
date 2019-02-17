#ifndef BINARYTREE_DEF_H
#define BINARYTREE_DEF_H

template <typename T>
class BinaryTreeNode {
public:
    BinaryTreeNode(): lchild(nullptr), rchild(nullptr) {}
    BinaryTreeNode(const T& _val): lchild(nullptr), rchild(nullptr), val(_val) {}

    BinaryTreeNode(const BinaryTreeNode& obj): val(obj.val) {
        lchild = obj.lchild;
        rchild = obj.rchild;
    }

    BinaryTreeNode(BinaryTreeNode* lptr, BinaryTreeNode* rptr, const T& _val):
        lchild(lptr), rchild(rptr), val(_val) {}

    ~BinaryTreeNode() {
        if(lchild != nullptr) delete lchild;
        if(rchild != nullptr) delete rchild;
    }

    BinaryTreeNode* lchild;
    BinaryTreeNode* rchild;
    T val;
};

#endif