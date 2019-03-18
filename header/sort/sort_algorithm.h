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
void HeapSort(T heap[], int len, bool (*cmp)(T const&, T const&));

template <typename T>
void MergeSort(T* beg, T* end);

#endif