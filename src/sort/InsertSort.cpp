#include <iostream>

#include "sort/sort_algorithm.h"

using namespace std;

template <typename T>
void InsertSort(T* beg, T* end) {
    int size = end - beg;
    for(int i = 1; i < size; ++i) {
        T tmp = beg[i];
        int j = 0;
        for(j = i - 1; j >= 0 && tmp < beg[j]; --j)
            beg[j+1] = beg[j];
        beg[j+1] = tmp;
    }
}

template <typename T>
void OptimizedInsertSort(T* beg, T* end) {
    int size = end - beg;
    for(int i = 1; i < size; ++i) {
        T tmp = beg[i];
        int high = i - 1;
        int low = 0;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(beg[mid] < tmp)
                high = mid - 1;
            else
                low = mid + 1;
        }
        for(int j = i - 1; j >= high; --j) {
            beg[j+1] = beg[j];
        }
        beg[high + 1] = tmp;
    }
}