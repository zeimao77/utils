#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "inode.h"

//队列表
struct Queue
{
    struct Node *nodes;
    int current_length;
};

//初始化队列表;
struct Queue *Queue_init(int size);

//追加元素节点;
int Queue_append(struct Queue *seq, struct Node *node);

//删除某个元素;
int Queue_delete(struct Queue *seq, int index);

//打印队列表
void Queue_print(char *title, struct Queue *seq);

//查找元素，返回下标，如果不存在返回-1;
int Queue_search(struct Queue *seq, struct Node node);

//比较获取对象，如果不存在返回NULL
struct Node *Queue_compare_get(struct Queue *seq, struct Node node);

//元素排序
void Queue_sort(struct Queue *seq);

#endif