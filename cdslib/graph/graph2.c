#include "graph2.h"

struct Gnode *Gnode_init2(long value){
    struct Node *data = Node_init(value);
    struct Gnode *gnode = Gnode_init(data);
    return gnode;
}

struct Gnode *Gnode_init(struct Node *data){
    struct Gnode *node = (struct Gnode *)malloc(sizeof(struct Gnode));
    node -> data = data;
    node -> firstin = NULL;
    node -> next = NULL;
    return node;
}

struct Gedge *Gedge_init(struct Gnode *tailvex,struct Gnode *headvex,int power){
    struct Gedge *edge =(struct Gedge *)malloc(sizeof(struct Gedge));
    edge -> tailvex = tailvex;
    edge -> headvex = headvex;
    edge -> power = power;
    edge -> hlink = NULL;
    edge -> tlink = NULL;
    return edge;
}

struct Graph *Graph_init(){
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph -> nodes = NULL;
    graph -> length = 0;
    return graph;
}

void Gnode_destroy(struct Gnode *gnode) {
    Node_destroy(gnode -> data);
    free(gnode);
    gnode = NULL;
}

void Gedge_destroy(struct Gedge *gedge) {
    free(gedge);
    gedge = NULL;
}

void Graph_destroy(struct Graph *graph) {

}

int Graph_adjacent(struct Graph *g,struct Gnode *n1,struct Gnode *n2){
    struct Gedge *fin = n1 -> firstin;
    while(fin != NULL){
        if(fin -> tailvex == n2 && fin -> headvex == n1) {
            return 1;
        }
        if(fin -> tailvex == n1 && fin -> headvex == n2) {
            return 1;
        }
        fin = fin -> hlink;
    }
    return 0;
}

int Graph_insert_vertex(struct Graph *g,struct Gnode *gnode){
    gnode -> next = g -> nodes;
    g -> nodes = gnode;
    g -> length++;
    return 1;
}

int Graph_delete_vertex(struct Graph *g,struct Gnode *gnode){
    if(gnode -> firstin == NULL) {
        if(g -> nodes == gnode) {
            g -> nodes = gnode -> next;
            Gnode_destroy(gnode);
            g -> length--;
            return 1;
        }
        for(struct Gnode *pre = g -> nodes;pre != NULL;pre = pre -> next) {
            if(pre -> next == gnode) {
                pre ->next = gnode -> next;
                Gnode_destroy(gnode);
                g -> length--;
                return 1;
            }
        }
    } else {
        perror("the graph nodes cannot be deleted!\n");
        Graph_show_node(gnode);
    }
    return 0;
}

int Graph_insert_edge(struct Graph *g,struct Gnode *n1,struct Gnode *n2,int power){
    struct Gedge *edge = Gedge_init(n1,n2,power);
    if(n1 -> firstin == NULL) {
        n1 -> firstin = edge;
    } else {
        edge -> tlink = n1 -> firstin;
        n1 -> firstin = edge;
    }
    if(n2 -> firstin == NULL) {
        n2 -> firstin = edge;
    } else {
        edge -> hlink = n2 -> firstin;
        n2 -> firstin = edge;
    }
    return 1;
}

int Graph_delete_edge(struct Graph *g,struct Gnode *n1,struct Gnode *n2){

}

int Graph_get_power(struct Graph *g,struct Gnode *n1,struct Gnode *n2){
}

int Graph_set_power(struct Graph *g,struct Gnode *n1,struct Gnode *n2,int power){
}

int Graph_isempty(struct Graph *g){
    return g -> length == 0 ? 1 : 0;
}

int Graph_show_node(struct Gnode *gnode){
    printf("gnode.node.data=%ld\n",gnode -> data -> value);
    struct Gedge *gedge = gnode -> firstin;
    if(gedge != NULL) {
        int j = 0;
        do {
            j++;
            if(gedge -> headvex == gnode) {
                printf("[%d]<%ld-%ld:%d>\n",j,gedge -> tailvex -> data -> value,gnode -> data -> value,gedge -> power);
                gedge = gedge -> hlink;
            } else if(gedge -> tailvex == gnode) {
                printf("[%d]<%ld-%ld:%d>\n",j,gedge -> headvex -> data -> value,gnode -> data -> value,gedge -> power);
                gedge = gedge -> tlink;
            }
        }while(gedge != NULL);
    }

    return 1;
}

int Graph_show(struct Graph *g){
    printf("================\n");
    printf("graph node length = %d;\n",g -> length);
    for(struct Gnode *gnode = g -> nodes;gnode != NULL;gnode=gnode->next) {
        Graph_show_node(gnode);
    }    
    return 1;
}


