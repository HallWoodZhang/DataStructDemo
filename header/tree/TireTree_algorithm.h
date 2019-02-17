#ifndef TIRETREE_ALGORITHM_H
#define TIRETREE_ALGORITHM_H

#include <string>
#include "TireTree_def.h"

extern inline TireNode* createTireNode();

namespace TireTree {
    extern void insertWord(TireNode* tree, const char* cstr);
    extern void insertWord(TireNode* tree, const std::string& str);
    extern int searchWord(TireNode* tree, const char* cstr);
    extern int searchWord(TireNode* tree, const std::string& str);
}

#endif

