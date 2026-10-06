#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

int main(){

    GRAPH G;

    G = loadGRAPH("data/graph.csv");
    printf("numero di vertici: %2d\nnumero di archi: %2d\n", vertex_number(G), Edge_number(G));

    shortPath(G, 1, 3);

    
    free_graph(G);
    return 0;
}