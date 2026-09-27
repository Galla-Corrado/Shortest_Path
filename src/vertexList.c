#include "vertexList.h"
#include "adjList.h"
#include "vertex_edge.h"
#include <stdlib.h>

/**
 * definizione e creazione del nodo della lista dei vertici.
 * Il primo elemento della lista indica il vertice di partenza, mentre gli elementi successivi sono gli elementi a lui connessi
 */
typedef struct v_node{
    adj_list adj_v;
    struct v_node *next;

}v_node;

static v_node *new_vnode(){
    v_node *newV = malloc(sizeof(v_node));
    newV->adj_v = new_adjList();
    newV->next = NULL;
    return newV;
}
/**
 * definizione e creazione della lista dei vertici
 */
struct vertexL{
    v_node *head;
};

vertexList new_VertexList(){
    vertexList vL = malloc(sizeof(vertexList));
    vL->head = NULL;
    return vL;
}
/**
 * inserimento di un arco in una lista
 */
void insert_VertexList(vertexList vl, Vertex src, Vertex dest, float w){
    v_node *x;
    int trovato =0;

    if(vl->head == NULL){
        vl->head = new_vnode();
        insert_adj_vertex(vl->head->adj_v, src, 0);
        insert_adj_vertex(vl->head->adj_v, dest, w);
    }
    else{
        for(x=vl->head; x->next!=NULL && !trovato; x = x->next){
            if(adj_Head_Vertex_value(x->adj_v) == src){
                trovato = 1;
                insert_adj_vertex(x->adj_v, dest, w);
            }
        }
        if(trovato == 0){
            x->next = new_vnode();
            insert_adj_vertex(x->next->adj_v, src, 0);
            insert_adj_vertex(x->next->adj_v, dest, w);
        }
    }
    return !trovato;
}
/**
 * cancellazione della lista dei vertici
 */
static v_node *remove_head(vertexList vl){
    v_node *x;
    x = vl->head->next;
    free_adjList(vl->head->adj_v);
    free(vl->head);
    return x;
}
void free_VertexList(vertexList vl){
    v_node *x;

    for(x=vl->head; x->next!=NULL; x=x->next){
        vl->head = remove_head(vl);
    }
    free(vl->head);
    free(vl);
}
/**
 * conta il numero di vertici
 */
int n_vertex(vertexList vl){
    int cnt=0;
    v_node *x;

    for(x=vl->head; x!=NULL; x=x->next){
        cnt++;
    }
    return cnt;
}
