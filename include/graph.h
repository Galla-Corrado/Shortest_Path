#ifndef GRAPH_H
#define GRAPH_H
#include "vertexList.h"
#include "binary_heap.h"



typedef struct graph *GRAPH;

GRAPH graphInit();
GRAPH loadGRAPH(char *fileName);
void insert_Edge(GRAPH G, Edge E);
void remove_Edge(GRAPH G, Edge E);
int vertex_number(GRAPH G);
int Edge_number(GRAPH G);
void free_graph(GRAPH G);
void shortPath(GRAPH G, Vertex src, Vertex dest);



#endif