#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

int main(){

    GRAPH G;

    G = loadGRAPH("data/graph.csv");
    printf("numero di vertici: %2d\nnumero di archi: %2d", vertex_number(G), Edge_number(G));

    
    return 0;
}