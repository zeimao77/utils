#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "inode.h"

struct Gnode{
    struct Node *data;
    struct Gnode *next;
    struct Gedge *firstin;
    struct Gedge *firstout;
};

struct Gedge{
    struct Gnode *tailvex;
    struct Gnode *headvex;
    int power;
    struct Gedge *hlink;
    struct Gedge *tlink;
};

struct Graph{
    struct Gnode *nodes;
    int length;
};

struct Gnode *Gnode_init2(long value);
struct Gnode *Gnode_init(struct Node *data);
struct Gedge *Gedge_init(struct Gnode *tailvex,struct Gnode *headvex,int power);
struct Graph *Graph_init();
void Gnode_destroy(struct Gnode *gnode);
void Gedge_destroy(struct Gedge *gedge);
void Graph_destroy(struct Graph *graph);
int Graph_adjacent(struct Graph *g,struct Gnode *n1,struct Gnode *n2);
int Graph_insert_vertex(struct Graph *g,struct Gnode *gnode);
int Graph_delete_vertex(struct Graph *g,struct Gnode *gnode);
int Graph_insert_edge(struct Graph *g,struct Gnode *n1,struct Gnode *n2,int power);
int Graph_delete_edge(struct Graph *g,struct Gnode *n1,struct Gnode *n2);
int Graph_get_power(struct Graph *g,struct Gnode *n1,struct Gnode *n2);
int Graph_set_power(struct Graph *g,struct Gnode *n1,struct Gnode *n2,int power);
struct Gnode *Graph_first_neighbor(struct Graph *g,struct Gnode *n1);
struct Gnode *Graph_next_neighbor(struct Graph *g,struct Gnode *n1,struct Gnode *n2);
int Graph_isempty(struct Graph *g);
int Graph_show_node(struct Gnode *gnode);
int Graph_show(struct Graph *g);

#endif
