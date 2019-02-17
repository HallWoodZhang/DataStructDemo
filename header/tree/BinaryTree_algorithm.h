#ifndef BINARYTREE_ALGORITHM_H
#define BINARYTREE_ALGORITHM_H

#include <iostream>
#include <cstdio>
#include "BinaryTree_def.h"

struct RecruTag {};
struct StackTag {};

template <typename T>
static void defaultVisitFunc(const BinaryTreeNode<T>* target) {
    std::cout << target->val << ' ';
}

template <typename T>
extern void preorderVisit(const BinaryTreeNode<T>* root,
    RecruTag, void (*visit)(const BinaryTreeNode<T>*) = defaultVisitFunc);

template <typename T>
extern void inorderVisit(const BinaryTreeNode<T>* root,
    RecruTag, void (*visit)(const BinaryTreeNode<T>*) = defaultVisitFunc);

template <typename T>
extern void postorderVisit(const BinaryTreeNode<T>* root, 
    RecruTag, void (*visit)(const BinaryTreeNode<T>*) = defaultVisitFunc);

template <typename T>
extern void preorderVisit(const BinaryTreeNode<T>* root, 
    StackTag, void (*visit)(const BinaryTreeNode<T>*) = defaultVisitFunc);

template <typename T>
extern void inorderVisit(const BinaryTreeNode<T>* root, 
    StackTag, void (*visit)(const BinaryTreeNode<T>*) = defaultVisitFunc);

template <typename T>
extern void postorderVisit(const BinaryTreeNode<T>* root, 
    StackTag, void (*visit)(const BinaryTreeNode<T>*) = defaultVisitFunc);


#endif
