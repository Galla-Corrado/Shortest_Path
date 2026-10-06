#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

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
        sscanf(buffer, "%d,%d,%f", &(E.src), &(E.dest), &(E.weight));
        insert_Edge(G, E);
    }
    G->n_Ver = n_vertex(G->list);
    fclose(fp);
    return G;
}

void insert_Edge(GRAPH G, Edge E){
    insert_VertexList(G->list, E.src, E.dest, E.weight, &(G->n_edge)); 
    insert_VertexList(G->list, E.dest, E.src, E.weight, &(G->n_edge));
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

void free_graph(GRAPH G){
    free_VertexList(G->list);
    free(G);
}

void shortPath(GRAPH G, Vertex src, Vertex dest){
    float *distance_array;
    int i, j, dim;
    Edge *e;
    BINARY_HEAP BH;

    distance_array = malloc(G->n_Ver*sizeof(float));
    BH = binHeap_init(G->n_Ver);

    //print_VertexList(G->list);

    
    for(i=0; i<G->n_Ver; i++){
        if(i==src){
            distance_array[i] = 0;
            binHeap_insert(BH, src, 0.0);
        }
        else{
            distance_array[i] = LLONG_MAX;
        }
    }
    
    for(i=0; i<G->n_Ver; i++){
        e = get_Edges_Vl(getVertex_heap(BH, i), G->list, &dim);
        if(e != NULL){
            for(j=0; j<dim; j++){
                printf("visit Edge:%d-%d\n", e[j].src, e[j].dest);
                if(distance_array[getVertex_heap(BH, i)]+e[j].weight < distance_array[e[j].dest]){
                    distance_array[e[j].dest] = distance_array[getVertex_heap(BH, i)]+e[j].weight;
                    binHeap_insert(BH, e[j].dest, distance_array[e[j].dest]);
                }
            }
        }
        free(e);
    }

    printHeap(BH);
    printPath(BH, dest);
}

