#include <iostream>

#include "graph/graph_def.h"
#include "graph/graph_algorithm.h"

using namespace std;

// indegree: the array about indegree of vertex
// return: if the function works well
template <typename T>
bool TopSort(const ArcGraph<T>& G, int indegree[MAXVEXNUM]) {
    int stack[MAXVEXNUM], top = -1;
    int counter = 0;
    for(int i = 0; i < G.vexNum; ++i) {
        if(indegree[i] == 0)
            stack[++top] = i;
    }

    while(top != -1) {
        int tmpVexId = stack[top--];
        ++counter;
        cout << tmpVexId << ' ';

        ArcNode<T>* tmpPtr = G.adjlist[tmpVexId].firstArcPtr;
        while(tmpPtr) {
            int nextVexId = tmpPtr->adjVexId;
            indegree[nextVexId] -= 1;
            if(indegree[nextVexId] == 0) stack[++top] = nextVexId;
            tmpPtr = tmpPtr->next;
        }
    }
    return counter == G.vexNum;
}