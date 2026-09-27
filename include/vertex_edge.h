#ifndef VERTEX_EDGE_H
#define VERTEX_EDGE_H

typedef int Vertex;

typedef struct edge{
    Vertex src;
    Vertex dest;
    float weight;
}Edge;

#endif