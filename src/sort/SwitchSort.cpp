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
void BubbleSort(T* beg, T* end) {
    int size = end - beg;
    for(int i = 0; i < size - 1; ++i) {
        bool change = false;
        for(int j = i + 1; j < size; ++j)
            if(beg[j] > beg[j-1]) {
                swap(beg[j], beg[j-1]);
                change = true;
            }
        if(!change) break;
    }
}

template <typename T>
void QuickSort(T* beg, T* end) {
    int low = 0, high = (end - beg) - 1;
    if(low < high) {
        T tmp = beg[low];
        int i = low, j = high;
        while(i < j) {
            while(j > i && beg[j] >= tmp) --j;
            if(i < j) beg[i++] = beg[j];
            while(i < j && beg[i] <= tmp) ++i;
            if(i < j) beg[j--] = beg[i];
        }
        beg[i] = tmp;
        QuickSort(beg, beg + i);
        QuickSort(beg + i + 1, end);
    }
}