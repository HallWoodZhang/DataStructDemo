#include <iostream>
#include <cstdio>

#include "TireTree_algorithm.h"

using namespace std;

static inline void test();
static inline void TireTree_test();

int main(void) {
    cout << "This is a demo." << endl;
    cout << "---------------" << endl;
    test();
    return 0;
}

static inline void test() {
    TireTree_test();
}

static inline void TireTree_test(void) {
    // 关键字集合
    char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their", "their"};
    TireNode *root = createTireNode();
    int i;
    for (i = 0; i < 9; ++i){
        TireTree::insertWord(root, keys[i]);
    }

    // 检索字符串
    char s[][32] = {"Present in trie", "Not present in trie"};

    printf("%s --- %s\n", "the", TireTree::searchWord(root, "the")>0?s[0]:s[1]);
    printf("%s --- %s\n", "these", TireTree::searchWord(root, "these")>0?s[0]:s[1]);
    printf("%s --- %s\n", "their", TireTree::searchWord(root, "their")>0?s[0]:s[1]);
    printf("%s --- %s\n", "thaw", TireTree::searchWord(root, "thaw")>0?s[0]:s[1]);
    printf("%s --- %d times\n", "their", TireTree::searchWord(root, "their"));
    printf("TireTree Test  Finished!\n");
    delete root;
    root = nullptr;
}
