#include <iostream>
#include <cstdlib>

#include "sort_algorithm.h"

using namespace std;

template <typename T>
static void merge(T* beg1, T* end1, T* beg2, T* end2) {
    int size1 = end1 - beg1;
    int size2 = end2 - beg2;
    T* tmp = (T*)malloc((size1 + size2)*sizeof(T));
    int curr = 0;
    T* it1 = beg1, it2 = beg2;
    while(it1 != end1 && it2 != end2) 
        tmp[curr++] = *it1 < *it2 ? *it1++ : *it2++;
    if(curr < size1 + size2) {
        while(it1 != end1)
            tmp[curr++] = *it1++;
        while(it2 != end2)
            tmp[curr++] = *it2++;
    }

    for(int i = 0; i < size1; ++i)
        beg1[i] = tmp[i];
    for(int j = size1 + 0; j - size1 < size2; ++j)
        beg2[j - size1] = tmp[j];
    free(tmp);
    tmp = nullptr;
}

template <typename T>
void MergeSort(T* beg, T* end) {
    int size = end - beg;
    if(size > 0) {
        int mid = size >> 1;
        MergeSort(beg, beg + mid);
        MergeSort(beg + mid, end);
        merge(beg, beg + mid, beg + mid, end);
    }
}