#include <iostream>
#include <cstdio>

#include "TrieTree_algorithm.h"
#include "sort_algorithm.h"

using namespace std;

template<typename T>
bool larger(T const& l, T const& r) {
    return l > r;
}

static inline void test();
static inline void TrieTree_test();
static inline void heapSort_test();

int main(void) {
    cout << "This is a demo." << endl;
    cout << "---------------" << endl;
    test();
    return 0;
}

static inline void test() {
    // TrieTree_test();
    heapSort_test();
}

static inline void TrieTree_test(void) {
    // 关键字集合
    char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their", "their"};
    TrieNode *root = createTrieNode();
    int i;
    for (i = 0; i < 9; ++i){
        TrieTree::insertWord(root, keys[i]);
    }

    // 检索字符串
    char s[][32] = {"Present in trie", "Not present in trie"};

    printf("%s --- %s\n", "the", TrieTree::searchWord(root, "the")>0?s[0]:s[1]);
    printf("%s --- %s\n", "these", TrieTree::searchWord(root, "these")>0?s[0]:s[1]);
    printf("%s --- %s\n", "their", TrieTree::searchWord(root, "their")>0?s[0]:s[1]);
    printf("%s --- %s\n", "thaw", TrieTree::searchWord(root, "thaw")>0?s[0]:s[1]);
    printf("%s --- %d times\n", "their", TrieTree::searchWord(root, "their"));
    printf("TrieTree Test  Finished!\n");
    delete root;
    root = nullptr;
}

static inline void heapSort_test() {
    int arr[] = {10, 8, 9, 7, 6, 3, 4, 5, 1, 2, 0, 18, 22, 44};
    cout << "before heap sort: ";
    for(int i: arr) {
        cout << i << ' ';
    }
    cout << endl;

    // 设置一个大根堆
    HeapSort(arr, sizeof(arr) / sizeof(int), larger);

    cout << "after heap sort: ";
    for(int i : arr) {
        cout << i << ' ';
    }
    cout << endl;
}
