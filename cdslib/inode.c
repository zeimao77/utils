#include "inode.h"

struct Node *Node_init(long value)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->value = value;
    return n;
}

//比较两个Node是否相同，如果相同则返回1否则返回0;
int Node_compare(struct Node node1, struct Node node2)
{
    if (node1.value == node2.value)
    {
        return 0;
    }
    else if (node1.value > node2.value)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

// 打印元素节点
void Node_print(struct Node node)
{
    printf("Node.value=%d\n", node.value);
}

//销毁节点
void Node_destroy(struct Node *node)
{
    free(node);
    node = NULL;
}

//交换节点
void Node_change(struct Node *node1, struct Node *node2)
{
    struct Node temp = *node2;
    *node2 = *node1;
    *node1 = temp;
}