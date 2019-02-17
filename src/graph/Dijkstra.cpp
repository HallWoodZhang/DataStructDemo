#include <iostream>

#include "graph_def.h"
#include "graph_algorithm.h"

using namespace std;

static int dist[MAXVEXNUM];
static int path[MAXVEXNUM];
static bool set[MAXVEXNUM];

/**
 *  G: the mat graph 
 *  startVexId: the seed 
 *  
 *  return: the path about the result
 */
template <typename T>
int* Dijkstra(MatGraph<T>& G, int startVexId) {
    // init
    memset(set, false, sizeof(set));
    for(int i = 0; i < G.vexNum; ++i) {
        dist[i] = G.edges[startVexId][i];
        if(dist[i] < MAXINTVAL)
            path[i] = startVexId;
        else path[i] = -1; // unreachable
    }

    set[startVexId] = true;
    path[startVexId] = -1;

    // do the algorithm
    for(int i = 0; i < G.vexNum - 1; ++i) {
        // find out the cloest vex
        int min = MAXINTVAL;
        int newVexIdToSet = -1;
        for(int j = 0; j < G.vexNum; ++j) {
            if(!set[j] && dist[j] < min) {
                newVexIdToSet = j;
                min = dist[j];
            }
        }

        // update the distance array
        set[newVexIdToSet] = true;
        for(int j = 0; j < G.vexNum; ++j) {
            if(!set[j] && dist[j] > dist[newVexIdToSet] + G.edges[newVexIdToSet][j]) {
                dist[j] = dist[newVexIdToSet] + G.edges[newVexIdToSet][j];
                path[j] = newVexIdToSet;
            }
        }
    }

    return path;
}