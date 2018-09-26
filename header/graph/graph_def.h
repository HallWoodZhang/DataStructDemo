#ifndef GRAPH_DEF_H
#define GRAPH_DEF_H

#include <cstring>


#define MAXEDGENUM (255*255)
#define MAXVEXNUM 255
#define MAXINTVAL (~(unsigned int)0 >> 1)

// forward def
struct Graph;

template <typename T> class MatVex;
template <typename T> class MatGraph;

template <typename T> class ArcNode;
template <typename T> class ArcVex;
template <typename T> class ArcGraph;

struct Road;


struct Graph {
public:
    int vexNum;
    int edgeNum;

    Graph(int v, int e): vexNum(v), edgeNum(e) {}
};

template <typename T>
class MatVex {
public:
    friend class MatGraph<T>;
    T data;
};

template <typename T>
class MatGraph: public Graph {
public:
    int edges[MAXVEXNUM][MAXVEXNUM];
    MatVex<T> vexList[MAXVEXNUM];     

    MatGraph(int v = 0, int e = 0, MatVex<T>* vl = nullptr, int* edgs[] = nullptr): Graph(v, e) {
        if(edgs) {
            for(int i = 0; i < MAXVEXNUM; ++i) {
		        for(int j = 0; j < MAXVEXNUM; ++j) {
		            edges[i][j] = edgs[i][j];
		        }
	        }
        } else for(int i = 0; i < MAXVEXNUM; ++i) memset(edges[i], MAXINTVAL, MAXVEXNUM*sizeof(int));
        
	    if(vl) for(int i = 0; i < MAXVEXNUM; ++i) vexList[i] = vl[i];
        else memset(vexList, T(), sizeof(vexList));
    }
};

template <typename T>
class ArcVex {
public:
    friend class ArcGraph<T>;
    T data;
    ArcNode<T>* firstArcPtr;
};


template <typename T>
class ArcGraph: public Graph {
public:
    ArcVex<T> adjlist[MAXVEXNUM];

    ArcGraph(int v  = 0, int e = 0, ArcVex<T>* al = nullptr): Graph(v, e) {
	    if(al) {
	        for(int i = 0; i < MAXVEXNUM; ++i)
		        adjlist[i] = al[i]; 
        }
    }
};

template<typename T>
class ArcNode {
public:
    friend class ArcGraph<T>;
    int adjVexId;
    int weight;
    
    ArcNode<T>* next;
};

#endif