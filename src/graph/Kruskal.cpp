#include <iostream>
#include <algorithm>

#include "graph/graph_def.h"
#include "graph/graph_algorithm.h"

using namespace std;

struct Road {
public:
    int fromVexId, toVexId;
    int weight;

    void operator=(const Road& rhs) {
        fromVexId = rhs.fromVexId;
        toVexId = rhs.toVexId;
        weight = rhs.weight;
    } 
};

static Road road[MAXEDGENUM];
static int vexSetChecker[MAXVEXNUM];

static inline int getVexSetRoot(int tag) {
    while(tag != vexSetChecker[tag]) tag = vexSetChecker[tag];
    return tag;
}

template <typename T>
static inline void initRoads(MatGraph<T>*G, Road*& roads) {
    if(!roads) {
        roads = road;
        int curr = -1;
        for(int i = 0; i < MAXVEXNUM; ++i)
            for(int j = 0; j <= i; ++j)
                if(G->edges[i][j] && G->edges[i][j] != MAXINTVAL)
                    road[++curr] = (Road){i, j, G->edges[i][j]};
        if(curr != G->edgeNum - 1)
            cout << "???" << endl;
    }
}

template <typename T>
int Kruskal(MatGraph<T>* G, Road* roads) {

    initRoads(G, roads);
    int from, to;
    int sum = 0;

    for(int i = 0; i < G->vexNum; ++i)
        vexSetChecker[i] = i;
    
    sort(roads, roads + G->edgeNum, [=](const Road& lhs, const Road& rhs){
        return lhs.weight < rhs.weight;
    });

    for(int i = 0; i < G->edgeNum; ++i) {
        from = getVexSetRoot(roads[i].fromVexId);
        to = getVexSetRoot(roads[i].toVexId);

        // check the if the to vex belong to the
        // same set 
        if(from != to) {
            // combine the set
            vexSetChecker[from] = to;
            sum += roads[i].weight;
        }
    }
    return sum;
}