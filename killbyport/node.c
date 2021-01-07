#include "node.h"

struct Node *Node_init(char *str)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    char *s = (char *)malloc(strlen(str) + 1);
    strcpy(s, str);
    n->str = s;
    return n;
}

//比较两个Node是否相同，如果相同则返回1否则返回0;
int Node_compare(struct Node node1, struct Node node2)
{
    if (strcmp(node1.str, node2.str) == 0)
    {
        return 1;
    }
    return 0;
}

// 打印元素节点
void Node_print(struct Node node)
{
    printf("%s\n", node.str);
}
