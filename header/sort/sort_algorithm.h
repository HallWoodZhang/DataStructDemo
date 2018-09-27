#ifndef SORT_ALGORITHM_H
#define SORT_ALGORITHM_H

template <typename T>
void InsertSort(T* beg, T* end);

template <typename T>
void OptimizedInsertSort(T* beg, T* end);

template <typename T>
void BubbleSort(T* beg, T* end);

template <typename T>
void QuickSort(T* beg, T* end);

template <typename T>
void SelectSort(T* beg, T* end);

template <typename T>
void heapSort(int heap[], int lastHeapId, bool (*cmp)(const T&, const T&));

#endif