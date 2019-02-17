#ifndef GRAPH_ALGORITHM_H
#define GRAPH_ALGORITHM_H

#include "./graph_def.h"

template <typename T>
int* Dijkstra(MatGraph<T>& G, int startVexId = 0);

template <typename T>
int Kruskal(MatGraph<T>* G, Road* roads = nullptr);

template <typename T>
int Prim(MatGraph<T>* G, int startVexId = 0);

template <typename T>
bool TopSort(const ArcGraph<T>& G, int indegree[MAXVEXNUM]);

#endif