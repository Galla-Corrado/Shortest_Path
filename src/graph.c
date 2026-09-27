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
    Vertex src, dest;
    float weight;
    char buffer[MAXC];

    fp = fopen(fileName, "r");
    if(fp==NULL){
        perror("impossibile aprire il file!\n");
        exit(-1);
    }
    while (fgets(buffer, MAXC, fp) != NULL)
    {
        G->n_edge++;
        sscanf(buffer, "%d,%d,%f", &src, &dest, &weight);
        if(is_insert_VertexList(G->list, src, dest, weight)){
            G->n_Ver++;
        }
        if(is_insert_VertexList(G->list, dest, src, weight)){
            G->n_Ver++;
        }
    }
    return G;
    fclose(fp);
}
