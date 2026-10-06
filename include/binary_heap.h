#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H
#include"vertex_edge.h"

typedef struct bin_heap *BINARY_HEAP;

BINARY_HEAP binHeap_init(int capacity);
void binHeap_insert(BINARY_HEAP H, Vertex v, float w);
int is_present(BINARY_HEAP H, Vertex v);
int getHeap_size(BINARY_HEAP H);
Vertex getVertex_heap(BINARY_HEAP H, int i);
void printPath(BINARY_HEAP H, Vertex dest);
void printHeap(BINARY_HEAP H);


#endif