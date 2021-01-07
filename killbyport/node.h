#ifndef __NODE_H__
#define __NODE_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SEQ_MAX_LENGTH 16

struct Node
{
    char str[8];
};

struct Node *Node_init(char *str);

//比较两个Node是否相同，如果相同则返回1否则返回0;
int Node_compare(struct Node node1, struct Node node2);

// 打印元素节点
void Node_print(struct Node node);



#endif
