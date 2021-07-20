#include "graph2.h"

int main(int argc,char *argv) {
    struct Gnode *n1 = Gnode_init2(1);
    struct Gnode *n2 = Gnode_init2(2);
    struct Gnode *n3 = Gnode_init2(3);
    struct Gnode *n4 = Gnode_init2(4);
    struct Gnode *n5 = Gnode_init2(5);
    struct Gnode *n6 = Gnode_init2(6);
    struct Gnode *n7 = Gnode_init2(7);
    struct Graph *g = Graph_init();
    Graph_insert_vertex(g,n1);
    Graph_insert_vertex(g,n2);
    Graph_insert_vertex(g,n3);
    Graph_insert_vertex(g,n4);
    Graph_insert_vertex(g,n5);
    Graph_insert_vertex(g,n6);
    Graph_insert_vertex(g,n7);
    Graph_insert_edge(g,n1,n2,18);
    Graph_insert_edge(g,n1,n7,18);
    Graph_insert_edge(g,n1,n6,19);
    Graph_insert_edge(g,n2,n3,8);
    Graph_insert_edge(g,n2,n7,20);
    Graph_insert_edge(g,n3,n4,20);
    Graph_insert_edge(g,n4,n5,9);
    Graph_insert_edge(g,n4,n6,16);
    Graph_insert_edge(g,n4,n7,15);
    Graph_insert_edge(g,n5,n6,3);
    Graph_insert_edge(g,n6,n7,15);
    Graph_delete_edge(g,n6,n7);
    Graph_delete_edge(g,n1,n7);
    Graph_delete_edge(g,n7,n2);
    Graph_delete_edge(g,n7,n4);
    Graph_show(g);
    return 1;
}
