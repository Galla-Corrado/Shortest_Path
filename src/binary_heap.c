#include "binary_heap.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct{
    Vertex v;
    float weight;
}node;

struct bin_heap{
    node *heap;
    int size;
    int capacity;
};

static void swap(node *a, node *b){
    node tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

BINARY_HEAP binHeap_init(int capacity){

    BINARY_HEAP H = malloc(sizeof(BINARY_HEAP));
    H->size = 0;
    H->capacity = capacity;
    H->heap = malloc(sizeof(capacity*sizeof(node)));
    return H;
}

void binHeap_insert(BINARY_HEAP H, Vertex v, float w){
    int i;
    node n;
    if(H->size == H->capacity){
        return;
    }
    n.v=v;
    n.weight=w;
    H->heap[H->size] = n;
    i=H->size;

    while(i!=0 && (H->heap[(i-1)/2].weight > H->heap[i].weight)){
        swap(&(H->heap[(i-1)/2]), &(H->heap[i]));
        i = (i-1)/2;
    }
    H->size++;
}

int is_present(BINARY_HEAP H, Vertex v){
    int i;
    for(i=0; i<H->size; i++){
        if(H->heap[i].v == v){
            return 1;
        }
    }
    return 0;
}

int getHeap_size(BINARY_HEAP H){
    return H->size;
}

Vertex getVertex_heap(BINARY_HEAP H, int i){
    return H->heap[i].v;
}

static void printPath_r(BINARY_HEAP H, Vertex dest){
    if(dest == 0){
        printf("%d->", H->heap[dest].v);
        return;
    }
    
    printPath_r(H, (dest-1)/2);
    printf("%d->", H->heap[dest].v);
}

void printPath(BINARY_HEAP H, Vertex dest){
    int i=0;

    while(i<H->size && H->heap[i].v!=dest){
        i++;
    }
    if(i<H->size && H->heap[i].v == dest){
        printf("ShortestPath:\n");
        printPath_r(H, i);
        printf("\ntotal weight:%.2f", H->heap[i].weight);
    }
    
}

void printHeap(BINARY_HEAP H){
    int i;

    for(i=0; i<H->size; i++){
        printf("(v:%d|w:%.2f) - ", H->heap[i].v, H->heap[i].weight);
    }
    printf("\n");
}