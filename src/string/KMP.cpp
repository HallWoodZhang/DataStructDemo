#include <string>
#include <cstring>
#include <ciso646>

#include "string_algorithm.h"

static constexpr int NOT_MATCH = -1;

static inline int* __getNextArr(int sz) {
    int* next = new int[sz + 1];
    memset(next, 0, sizeof(int)*(sz + 1));
    return next;
}

static inline void __initNextArr(const char* pattern, int* next) {
    next[0] = -1;
    int i = 0;
    int j = -1;
    while( i < strlen(pattern)) {
        if(j == -1 or pattern[i] == pattern[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

static inline void __initNextArr(const std::string& pattern, int* next) {
    next[0] = -1;
    int i = 0;
    int j = -1;
    while( i < pattern.size()) {
        if(j == -1 or pattern[i] == pattern[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

extern int KMP(const char* cstr, const char* pattern) {
    if(!cstr or !pattern or strlen(cstr) < strlen(pattern)) 
        return NOT_MATCH;
    if(strlen(pattern) == 0) return 0;

    int i = 0;
    int offset = 0;
    int* next = __getNextArr(strlen(pattern));
    __initNextArr(pattern, next);

    while(i < strlen(cstr)) {
        if(offset == -1 or cstr[i] == pattern[offset]) {
            ++i;
            ++offset;
            next[i] = offset;
        } else {
            offset = next[offset];
        }
    }
    delete next;
    if(offset == strlen(pattern))
        return i;
    else
        return NOT_MATCH;
}

extern int KMP(const std::string& str, const std::string& pattern) {
    if(!str.size() or !pattern.size() > str.size()) 
        return NOT_MATCH;
    if(pattern.size() == 0) return 0;

    int i = 0;
    int offset = 0;
    int* next = __getNextArr(pattern.size());
    __initNextArr(pattern, next);

    while(i < str.size() and offset < pattern.size()) {
        if(offset == -1 or str[i] == pattern[offset]) {
            ++i;
            ++offset;
            next[i] = offset;
        } else {
            offset = next[offset];
        }
    }
    delete next;
    if(offset == pattern.size())
        return i;
    else
        return NOT_MATCH;
}