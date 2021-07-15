#include "graph.h"

struct Gnode *Gnode_init2(long value) {
    struct Node *data = Node_init(value);
    struct Gnode *gnode = Gnode_init(data);
    return gnode;
}

struct Gnode *Gnode_init(struct Node *data) {
    struct Gnode *node = (struct Gnode *)malloc(sizeof(struct Gnode));
    node -> data = data;
    node -> firstin = NULL;
    node -> firstout = NULL;
    node -> next = NULL;
    return node;
}

struct Gedge *Gedge_init(struct Gnode *tailvex,struct Gnode *headvex,int power) {
    struct Gedge *edge =(struct Gedge *)malloc(sizeof(struct Gedge));
    edge -> tailvex = tailvex;
    edge -> headvex = headvex;
    edge -> power = power;
    edge -> hlink = NULL;
    edge -> tlink = NULL;
    return edge;
}

struct Graph *Graph_init() {
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

int Graph_adjacent(struct Graph *g,struct Gnode *n1,struct Gnode *n2) {
    struct Gedge *fin = n1->firstout;
    while(fin != NULL) {
        if(fin -> tailvex == n2) {
            return 1;
        }
        fin = fin->hlink;
    }
    return 0;
}

int Graph_insert_vertex(struct Graph *g,struct Gnode *gnode) {
    gnode -> next = g -> nodes;
    g -> nodes = gnode;
    g -> length++;
    return 1;
}

int Graph_delete_vertex(struct Graph *g,struct Gnode *gnode) {
    if(gnode -> firstin == NULL && gnode -> firstout == NULL) {
        if(g -> nodes == gnode) {
            g -> nodes = gnode -> next;
            Gnode_destroy(gnode);
            g -> length--;
            return 1;
        }
        for(struct Gnode *pre = g -> nodes;pre != NULL;pre = pre -> next) {
            if(pre -> next == gnode) {
                pre -> next = gnode -> next;
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

int Graph_insert_edge(struct Graph *g,struct Gnode *n1,struct Gnode *n2,int power) {
    struct Gedge *edge = Gedge_init(n2,n1,power);
    if(Graph_adjacent(g,n1,n2) == 1) {
        return 0;
    }
    if(n1 -> firstout == NULL) {
        n1 -> firstout = edge;
    } else {
        edge -> hlink = n1 -> firstout;
        n1 -> firstout = edge;
    }
    if(n2 -> firstin == NULL) {
        n2 -> firstin = edge;
    } else {
        edge -> tlink = n2 -> firstin;
        n2 -> firstin = edge;
    }
    return 1;
}

int Graph_delete_edge(struct Graph *g,struct Gnode *n1,struct Gnode *n2) {
    struct Gedge *fout = n1->firstout;
    if(fout == NULL){return 0;}
    struct Gedge *preout = NULL;
    do {
        if(fout -> tailvex == n2) {
            if(preout != NULL) {
                preout -> hlink = fout -> hlink;
            } else {
                n1 -> firstout = fout -> hlink;
            }
        }
        preout = fout;
        fout = fout -> hlink;
    }while(fout != NULL);

    struct Gedge *fin = n2 -> firstin;
    if(fin == NULL) {return 0;}
    struct Gedge *prein = NULL;
    do {
        if(fin -> headvex == n1) {
            if(prein != NULL) {
                prein -> tlink = fin -> tlink;
            } else {
                n2 -> firstin = fin -> tlink;
            }
            Gedge_destroy(fin);
        }
        prein = fin;
        fin = fin -> tlink;
    }while(fin != NULL);

    return 1;
}

int Graph_get_power(struct Graph *g,struct Gnode *n1,struct Gnode *n2) {
    struct Gedge *fin = n1->firstout;
    while(fin != NULL) {
        if(fin -> tailvex == n2) {
            return fin -> power;
        }
        fin = fin->hlink;
    }
    return 0;
}

int Graph_set_power(struct Graph *g,struct Gnode *n1,struct Gnode *n2,int power) {
    struct Gedge *fin = n1->firstout;
    while(fin != NULL) {
        if(fin -> tailvex == n2) {
            fin -> power = power;
        }
        fin = fin->hlink;
    }
    return 0;
}

struct Gnode *Graph_first_neighbor(struct Graph *g,struct Gnode *n1) {
    return NULL;
}

struct Gnode *Graph_next_neighbor(struct Graph *g,struct Gnode *n1,struct Gnode *n2) {
    return NULL;
}

int Graph_isempty(struct Graph *g) {
    return g -> length == 0 ? 1 : 0;
}

int Graph_show_node(struct Gnode *gnode) {
    if(gnode == NULL){return 0;}
    printf("gnode.node.data=%ld\n",gnode -> data -> value);
    struct Gedge *gedge = gnode->firstout;
    if(gedge != NULL) {
        int j = 0;
        do {
            j++;
            printf("[out:%d]<%ld->%ld>\n",j,gedge -> headvex -> data -> value,gedge -> tailvex -> data -> value);
            gedge = gedge -> hlink;
        }while(gedge != NULL);
    }

    gedge = gnode -> firstin;
    if(gedge != NULL) {
        int j = 0;
        do {
            j++;
            printf("[in:%d]<%ld->%ld>\n",j,gedge -> headvex -> data -> value,gedge -> tailvex -> data -> value);
            gedge = gedge -> tlink;
        }while(gedge != NULL);
    }

    return 1;
}

int Graph_show(struct Graph *g) {
    printf("================\n");
    printf("graph node length = %d;\n",g -> length);
    for(struct Gnode *gnode = g -> nodes;gnode != NULL;gnode=gnode->next) {
        Graph_show_node(gnode);
    }    
    return 1;
}

