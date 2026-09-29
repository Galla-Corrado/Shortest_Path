#ifndef ADJ_LIST_H
#define ADJ_LISI_H
#include "vertex_edge.h"

typedef struct adj *adj_list;

adj_list new_adjList();
void insert_adj_vertex(adj_list list, Vertex v, float weight, int *succes);
void remove_adj_vertex(adj_list list, Vertex v, int *succes);
Vertex adj_Head_Vertex_value(adj_list list);
void free_adjList(adj_list list);




#endif
