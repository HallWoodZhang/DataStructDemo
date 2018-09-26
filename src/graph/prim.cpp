#include <iostream>
#include <cstring>

#include "graph/graph_def.h"

#define TMP_VAL MAXINTVAL

using namespace std;

static bool visited[MAXVEXNUM];
static int lowcost[MAXVEXNUM];

template <typename T>
int Prim(MatGraph<T>* G, int startVexId = 0) {
    int sum = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < G->vexNum; ++i) {
        lowcost[i] = G->edges[startVexId][i];
    }

    visited[startVexId] = true;

    for(int i = 0; i < G->vexNum - 1; ++i) {
        
        int min = MAXINTVAL;
        int tmpVexId = TMP_VAL;

        // find next vex to the tree
        for(int j = 0; j < G->vexNum; ++j) {
            if(visited[j] && lowcost[j] < min) {
                min = lowcost[j];
                tmpVexId = j;
            }
        }


        // update the cost array for the graph
        if(tmpVexId != TMP_VAL) {
            visited[tmpVexId] = true;
            sum += lowcost[tmpVexId];

            for(int j = 0; j < G->vexNum; ++j) {
                if(!visited[j] && G->edges[tmpVexId][j] < lowcost[j]) {
                    lowcost[j] = G->edges[tmpVexId][j];
                }
            }
        }
    }

    return sum;
}
