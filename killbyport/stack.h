#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node.h"

#define STACK_MAX_LENGTH 16

struct Stack
{
    struct Node list[STACK_MAX_LENGTH];
    int current_length;
};

struct Stack *Stack_init();

int Stack_isEmpty();

int Stack_push(struct Stack *stack, struct Node *node);

struct Node Stack_pop(struct Stack *stack);

struct Node Stack_readPop(struct Stack *stack);

//打印栈
void Stack_print(char *title, struct Stack *seq);

#endif
