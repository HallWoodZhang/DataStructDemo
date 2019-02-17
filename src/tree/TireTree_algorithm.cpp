#include <cstring>
#include <ciso646>

#include "TireTree_algorithm.h"

using namespace std;

static constexpr int NOT_FOUND = 0;
static constexpr int SEARCH_ERR = -1;

extern inline TireNode* createTireNode() {
    TireNode* node = new TireNode;
    memset(node->children, 0, ALPHABETA_SZ*sizeof(TireNode*));
    return node;
}

extern void TireTree::insertWord(TireNode* tree, const char* cstr) {
    TireNode* curr = tree;
    if(!curr) return ;
    const char* ch = cstr;
    while(*ch) {
        int offset = *ch - 'a';
        if(curr->children[offset] == nullptr) {
            curr->children[offset] = createTireNode();
        }
        curr = curr->children[offset];
        ++ch;
    }
    curr->cnt += 1;
}

extern void TireTree::insertWord(TireNode* tree, const std::string& str) {
    TireNode* curr = tree;
    if(!curr) return ;
    for(auto it = str.begin(); it != str.end(); ++it) {
        int offset = *it - 'a';
        if(curr->children[offset] == nullptr) {
            curr->children[offset] = createTireNode();
        }
        curr = curr->children[offset];
    }
    curr->cnt += 1;
}

extern int TireTree::searchWord(TireNode* tree, const char* cstr) {
    TireNode* curr = tree;
    if(!curr) return SEARCH_ERR;

    const char* ch = cstr;
    while(*ch and curr != nullptr) {
        int offset = *ch - 'a';
        curr = curr->children[offset];
        ++ch;
    }
    if(curr == nullptr) return NOT_FOUND;
    return curr->cnt;
}

extern int TireTree::searchWord(TireNode* tree, const std::string& str) {
    TireNode* curr = tree;
    if(!curr) return SEARCH_ERR;
    for(auto it = str.begin(); it != str.end() and curr != nullptr; ++it) {
        int offset = *it - 'a';
        curr = curr->children[offset];
    }
    if(curr == nullptr) return NOT_FOUND;
    return curr->cnt;
}