#ifndef VERTEXLIST_H
#define VERTEXLIST_H
#include "vertex_edge.h"

typedef struct vertexL *vertexList;

vertexList new_VertexList();
void insert_VertexList(vertexList vl, Vertex src, Vertex dest, float w);
void free_VertexList(vertexList vl);
int n_vertex(vertexList vl);


#endif