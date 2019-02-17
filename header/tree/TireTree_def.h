#ifndef TIRETREE_DEF_H
#define TIRETREE_DEF_H

#define ALPHABETA_SZ (26 + 1)

class TireNode {
public:
    TireNode(): cnt(0) {}
    ~TireNode() {
        for(int i = 0; i < ALPHABETA_SZ; ++i) {
            if(children[i]) delete children[i];
        }
    }
    int cnt;
    TireNode* children[ALPHABETA_SZ];
};

#endif