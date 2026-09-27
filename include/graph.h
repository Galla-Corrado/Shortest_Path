#ifndef GRAPH_H
#define GRAPH_H
#include "vertex_edge.h"



typedef struct graph *GRAPH;

GRAPH graphInit();
GRAPH loadGRAPH(char *fileName);



#endif