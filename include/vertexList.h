#ifndef VERTEXLIST_H
#define VERTEXLIST_H
#include "adjList.h"

typedef struct vertexL *vertexList;

vertexList new_VertexList();
void insert_VertexList(vertexList vl, Vertex src, Vertex dest, float w, int *n_E);
void remove_VertexList(vertexList vl, Vertex src, Vertex dest, int *n_E);
void free_VertexList(vertexList vl);
int n_vertex(vertexList vl);
Edge *get_Edges_Vl(Vertex v, vertexList vl, int *dim);
void print_VertexList(vertexList vl);


#endif