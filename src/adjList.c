#include <stdlib.h>
#include "adjList.h"

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
    x = l->head->next;
    free(l->head);
    return x;
}
void free_adjList(adj_list list){
    adj_node *x;

    for(x=list->head; x->next!=NULL; x=x->next){
        list->head = remove_head(list);
    }
    free(list->head);
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

