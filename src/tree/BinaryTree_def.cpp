#include <vector>
#include <string>
#include <queue>
#include <ciso646>

#include "BinaryTree_def.h"

template <typename T>
extern BinaryTreeNode<T>* buildBinaryTree(const T* arr, int sz, const T& nil) {
    if(arr == nullptr or sz <= 0) return nullptr;
    BinaryTreeNode<T>* root = new BinaryTreeNode<T>(*arr);
    std::queue<BinaryTreeNode<T>* > queue;
    int i = 1;
    queue.push(root);
    while(!queue.empty() and i < sz) {
        BinaryTreeNode<T>* curr = queue.front();
        if(curr != nullptr) {
            if(arr[i] == nil) curr->lchild = nullptr;
            else curr->lchild = new BinaryTreeNode<T>(arr[i]);
            queue.push(curr->lchild);

            if(arr[i + 1] == nil) curr->rchild = nullptr;
            else curr->rchild = new BinaryTreeNode<T>(arr[i + 1]);
            queue.push(curr->rchild);
        } else {
            queue.push(nullptr);
            queue.push(nullptr);
        }
        queue.pop();
        i += 2;
    }
    return root;
}

template <typename T>
extern BinaryTreeNode<T>* buildBinaryTree(const std::vector<T>& arr, const T& nil) {
    if(arr.size() == 0) return nullptr;
    BinaryTreeNode<T>* root = new BinaryTreeNode<T>(arr[0]);
    std::queue<BinaryTreeNode<T>* > queue;
    int i = 1;
    queue.push(root);
    while(!queue.empty() and i < arr.size()) {
        BinaryTreeNode<T>* curr = queue.front();
        if(curr != nullptr) {
            if(arr[i] == nil) curr->lchild = nullptr;
            else curr->lchild = new BinaryTreeNode<T>(arr[i]);
            queue.push(curr->lchild);

            if(arr[i + 1] == nil) curr->rchild = nullptr;
            else curr->rchild = new BinaryTreeNode<T>(arr[i + 1]);
            queue.push(curr->rchild);
        } else {
            queue.push(nullptr);
            queue.push(nullptr);
        }
        queue.pop();
        i += 2;
    }
    return root;
}

extern BinaryTreeNode<char>* buildBinaryTree(const std::string& bytes, const char nil) {
    return buildBinaryTree(bytes.c_str(), int(bytes.size()), '#');
}