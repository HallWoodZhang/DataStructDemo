#include <iostream>

#include "sort_algorithm.h"

using namespace std;

template <typename T>
static inline void swap(T& lhs, T& rhs) {
    T tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

// measure the heap
template <typename T>
static void Sift(T heap[], int first, int last, bool (*cmp)(T const &, T const &)) {
    
    int i = first;
    int j = (i << 1) + 1;

    while(j <= last) {
        if(j < last && !cmp(heap[j], heap[j+1])) ++j;
        if(!cmp(heap[i], heap[j])) {
            swap(heap[i], heap[j]);
            i = j;
            j = (i << 1) + 1;
        } else break;
    }
}

template <typename T>
void HeapSort(T heap[], int len, bool (*cmp)(T const &, T const &)) {
    for(int i = (len >> 1) - 1; i > 0; --i)
        Sift(heap, i, len - 1, cmp);
    for(int i = len - 1; i > 0; --i) {
        swap(heap[0], heap[i]);
        Sift(heap, 0, i - 1, cmp);
    }
}