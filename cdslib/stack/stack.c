#include "stack.h"

struct Stack *Stack_init(int size)
{
    struct Node *ns = (struct Node *)malloc(sizeof(struct Node) * size);
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->current_length = 0;
    stack->nodes = ns;
    return stack;
}

int Stack_isEmpty(struct Stack *stack)
{
    if (stack->current_length == 0)
    {
        return 1;
    }
    return 0;
}

int Stack_push(struct Stack *stack, struct Node *node)
{
    stack->nodes[stack->current_length] = *node;
    stack->current_length++;
    return 1;
}

struct Node *Stack_pop(struct Stack *stack)
{
    stack->current_length--;
    return &stack->nodes[stack->current_length];
}

struct Node Stack_readPop(struct Stack *stack)
{
    return stack->nodes[stack->current_length];
}

void Stack_print(char *title, struct Stack stack)
{
    if (stack.current_length > 0 && strlen(title) > 1)
    {
        printf("==========[%s]==========\n", title);
    }
    for (int i = stack.current_length - 1; i >= 0; i--)
    {
        Node_print(stack.nodes[i]);
    }
}