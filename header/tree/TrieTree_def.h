#ifndef TRIETREE_DEF_H
#define TRIETREE_DEF_H

#define ALPHABETA_SZ (26 + 1)

class TrieNode {
public:
    TrieNode(): cnt(0) {}
    ~TrieNode() {
        for(int i = 0; i < ALPHABETA_SZ; ++i) {
            if(children[i]) delete children[i];
        }
    }
    int cnt;
    TrieNode* children[ALPHABETA_SZ];
};

#endif