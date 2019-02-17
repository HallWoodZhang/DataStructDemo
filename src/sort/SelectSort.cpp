#include <iostream>

#include "sort_algorithm.h"

using namespace std;

template <typename T>
static inline void swap(T& lhs, T& rhs) {
    T tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

template <typename T>
void SelectSort(T* beg, T* end) {
    int size = end - beg;
    for(int i = 0; i < size; ++i) {
        int k = i;
        for(int j = i + 1; j < size; ++j) {
            if(beg[k] > beg[j])
                k = j;
        }
        swap(beg[i], beg[k]);
    }
}