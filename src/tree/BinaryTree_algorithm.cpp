#include <stack>
#include <ciso646>

#include "BinaryTree_def.h"
#include "BinaryTree_algorithm.h"

template <typename T>
extern void preorderVisit(const BinaryTreeNode<T>* root, 
    RecruTag tag, void (*visit)(const BinaryTreeNode<T>*)) {
    if(!root) return ;
    visit(root);
    preorderVisit(root->lchild, tag, visit);
    preorderVisit(root->rchild, tag, visit);
}

template <typename T>
extern void inorderVisit(const BinaryTreeNode<T>* root,
    RecruTag tag, void (*visit)(const BinaryTreeNode<T>*)) {
    if(!root) return ;
    inorderVisit(root->lchild, tag, visit);
    visit(root);
    inorderVisit(root->rchild, tag, visit);
}

template <typename T>
extern void postorderVisit(const BinaryTreeNode<T>* root, 
    RecruTag tag, void (*visit)(const BinaryTreeNode<T>*)) {
    if(!root) return ;
    postorderVisit(root->lchild, tag, visit);
    postorderVisit(root->rchild, tag, visit);
    visit(root);
}

template <typename T>
extern void preorderVisit(const BinaryTreeNode<T>* root, 
    StackTag, void (*visit)(const BinaryTreeNode<T>*)) {
    if(!root) return ;
    std::stack<BinaryTreeNode<T>* > stk;
    stk.push(root);
    while(!stk.empty()) {
        BinaryTreeNode<T>* curr = stk.top();
       1 stk.pop();
        visit(curr);
        if(curr->rchild != nullptr) stk.push(curr->rchild);
        if(curr->lchild != nullptr) stk.push(curr->lchild);
    }
}

template <typename T>
extern void inorderVisit(const BinaryTreeNode<T>* root, 
    StackTag, void (*visit)(const BinaryTreeNode<T>*)) {
    if(!root) return ;
    std::stack<BinaryTreeNode<T>* > stk;
    BinaryTreeNode<T>* curr = root;
    while(curr != nullptr or !stk.empty()) {
        if(curr != nullptr) {
            stk.push(curr);
            curr = curr->lchild;
        } else {
            curr = stk.top();
            stk.pop();
            visit(curr);
            curr = curr->rchild;
        }
    }
}

template <typename T>
extern void postorderVisit(const BinaryTreeNode<T>* root, 
    StackTag, void (*visit)(const BinaryTreeNode<T>*)) {
    if(!root) return ;
    BinaryTreeNode<T>* curr = root;
    stack<BinaryTreeNode<T>* > stk;
    do {
        while(curr != nullprt) {
            stk.push(curr);
            curr = curr->lchild;
        }
        bool lchild_visited = true;
        BinaryTreeNode<T>* pre = nullptr;
        while(!stk.empty() and lchild_visited) {
            curr = stk.top();
            if(curr->rchild == pre) {
                stk.pop();
                visit(pre);
                pre = curr;
            } else {
                curr = curr->rchild;
                lchild_visited = true;
            }
        }
    } while(!stk.empty())
}
