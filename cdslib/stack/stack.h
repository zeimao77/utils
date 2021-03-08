#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "inode.h"

//栈结构
struct Stack
{
    struct Node *nodes;
    int current_length;
};

//初始化栈
struct Stack *Stack_init(int size);

//栈是否为空;返回1为空
int Stack_isEmpty();

//压栈
int Stack_push(struct Stack *stack, struct Node *node);

//弹出栈
struct Node *Stack_pop(struct Stack *stack);

//读取栈顶
struct Node Stack_readPop(struct Stack *stack);

//打印栈
void Stack_print(char *title, struct Stack stack);

#endif