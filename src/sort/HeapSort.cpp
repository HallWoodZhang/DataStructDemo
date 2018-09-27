#include <iostream>

#include "sort/sort_algorithm.h"

using namespace std;

template <typename T>
static inline void swap(T& lhs, T& rhs) {
    T tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

// measure the heap
template <typename T>
static void Sift(T heap[], int first, int last, bool (*cmp)(const T&, const T&)) {
    
    int i = first;
    int j = i << 1;

    T tmp = heap[i];
    while(j <= last) {
        if(j < last && cmp(heap[j], heap[j+1])) ++j;
        if(cmp(heap[i], heap[j])) {
            heap[i] = heap[j];
            i = j;
            j = i << 1;
        } else break;
    }
    heap[i] = tmp;
}

// common sense: heap[0] is useless
template <typename T>
void heapSort(T heap[], int lastHeapId, bool (*cmp)(const T&, const T&)) {
    for(int i = lastHeapId >> 1; i >= 1; --i)
        Sift(heap, i, lastHeapId, cmp);
    for(int i = lastHeapId; i >= 2; --i) {
        swap(heap[1], heap[i]);
        Sift(heap, 1, i - 1, cmp);
    }
}