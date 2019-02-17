#ifndef TRIETREE_ALGORITHM_H
#define TRIETREE_ALGORITHM_H

#include <string>
#include "TrieTree_def.h"

extern TrieNode* createTrieNode();

namespace TrieTree {
    extern void insertWord(TrieNode* tree, const char* cstr);
    extern void insertWord(TrieNode* tree, const std::string& str);
    extern int searchWord(TrieNode* tree, const char* cstr);
    extern int searchWord(TrieNode* tree, const std::string& str);
}

#endif

