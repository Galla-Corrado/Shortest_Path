#include "graph.h"
#include "vertexList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXC 20

/**
 * definizione struttura del grafo
 */
struct graph{
    int n_Ver;
    int n_edge;
    vertexList list;
};

GRAPH graphInit(){

    GRAPH G = malloc(sizeof(GRAPH));
    G->n_Ver=0;
    G->n_edge=0;
    G->list = new_VertexList();
    return G;
}

GRAPH loadGRAPH(char *fileName){ 
    FILE *fp;
    GRAPH G = graphInit();
    Edge E;
    char buffer[MAXC];

    fp = fopen(fileName, "r");
    if(fp==NULL){
        perror("impossibile aprire il file!\n");
        exit(-1);
    }
    while (fgets(buffer, MAXC, fp) != NULL)
    {
        G->n_edge++;
        sscanf(buffer, "%d,%d,%f", &(E.src), &(E.dest), &(E.weight));
        insert_Edge(G, E);
    }
    G->n_Ver = n_vertex(G->list);
    return G;
    fclose(fp);
}

void insert_Edge(GRAPH G, Edge E){
    insert_VertexList(G->list, E.src, E.dest, E.weight, &(G->n_edge)); 
}

void remove_Edge(GRAPH G, Edge E){
    remove_VertexList(G->list, E.src, E.dest, &(G->n_edge));
    remove_VertexList(G->list, E.dest, E.src, &(G->n_edge));
}

int vertex_number(GRAPH G){
    return G->n_Ver;
}

int Edge_number(GRAPH G){
    return G->n_edge;
}