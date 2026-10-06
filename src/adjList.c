#include <stdlib.h>
#include "adjList.h"
#include <stdio.h>

/**
 * definizione del nodo di una lista di adiacenze
 */
typedef struct node{
    Vertex v;
    float weight;
    struct node *next;
}adj_node;;
/**
 * definizione della lista di adiacenze
 */
struct adj{
    adj_node *head;
};

static adj_node *new_adj_node(Vertex v, float weight){
    adj_node *adjN = malloc(sizeof(adj_node));
    adjN->v = v;
    adjN->weight = weight;
    adjN->next = NULL;
    return adjN;
}

adj_list new_adjList(){
    adj_list adjL = malloc(sizeof(adj_list));
    adjL->head = NULL;
    return adjL;
}

void insert_adj_vertex(adj_list list, Vertex v, float weight, int *succes){
    adj_node *x;
    int trovato=0;

    if(list->head == NULL){
        list->head = new_adj_node(v, weight);
        *succes = 1;
    }
    else{
        for(x=list->head; x->next!=NULL && !trovato; x=x->next){
            if(x->v==v){
                x->weight = weight;
                *succes = 0;
                trovato = 1;
            }
        }
        if(trovato == 0){
            x->next = new_adj_node(v, weight);
            *succes = 1;
        }
    }
}

Vertex adj_Head_Vertex_value(adj_list list){
    return list->head->v;
}

static adj_node *remove_head(adj_list l){
    adj_node *x;
    
    x = l->head;
    
    l->head = x->next;
    free(x);
    
    return l->head;
}
void free_adjList(adj_list list){
    adj_node *x;

    x= list->head;
    while(x->next != NULL){
        x = remove_head(list);
    }
    free(x);
    free(list);
}

void remove_adj_vertex(adj_list list, Vertex v, int *succes){
    adj_node *prev, *x;
    int trovato = 0;

    prev = list->head;
    x = prev->next;
    if(prev->v == v){
        list->head = remove_head(list);
        *succes = 1;
        trovato =1;
    }
    while(!trovato && x!=NULL){
        if(x->v == v){
            trovato = 1;
            prev->next = x->next;
            *succes = 1;
            free(x);
            return;
        }
        prev = x;
        x = x->next;
    }
    *succes = 0;
}

static int List_size(adj_list adjl){
    adj_node *x;
    int size=0;

    for(x=adjl->head->next; x!=NULL; x = x->next){
        size++;
    }
    return size;
}

Edge *getEdges(adj_list adjl, int *dim){
    Edge *e;
    int i;
    adj_node *x = adjl->head->next;

    *dim = List_size(adjl);
    e = malloc(*dim*sizeof(Edge));
    for(i=0; i<*dim; i++){
        e[i].src = adj_Head_Vertex_value(adjl);
        e[i].dest = x->v;
        e[i].weight = x->weight;
        x = x->next;
    }
    return e;
}

void print_adjL(adj_list adjl){
    adj_node *x;

    for(x=adjl->head->next; x!=NULL; x = x->next){
        printf("(v:%d|w:%.2f)-", x->v, x->weight);
    }
    printf("\n");
}


