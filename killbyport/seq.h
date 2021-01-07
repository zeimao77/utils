#ifndef __SEQ_H__
#define __SEQ_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node.h"

struct Seq
{
    struct Node *nodes;
    int current_length;
};

//初始化队列表;
struct Seq *Seq_init(int size);

//追加元素节点;
int Seq_append(struct Seq *seq, struct Node *node);

//删除某个元素;
int Seq_delete(struct Seq *seq, int index);

//打印队列表
void Seq_print(char *title, struct Seq *seq);

//查找元素，返回下标，如果不存在返回-1;
int Seq_search(struct Seq *seq, struct Node node);

//比较获取对象，如果不存在返回NULL
struct Node Seq_compare_get(struct Seq *seq, struct Node node);

#endif

