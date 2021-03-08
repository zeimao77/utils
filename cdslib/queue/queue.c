#include "queue.h"

//初始化队列表;
struct Queue *Queue_init(int size)
{
    struct Node *ns = (struct Node *)malloc(sizeof(struct Node) * size);
    struct Queue *seq = (struct Queue *)malloc(sizeof(struct Queue));
    seq->nodes = ns;
    seq->current_length = 0;
    return seq;
}

//追加元素节点;
int Queue_append(struct Queue *seq, struct Node *node)
{
    seq->nodes[seq->current_length] = *node;
    seq->current_length++;
    return 1;
}

//删除某个元素;
int Queue_delete(struct Queue *seq, int index)
{
    if (index < 0 || index >= seq->current_length)
    {
        return 0;
    }
    for (int i = index; i < seq->current_length; i++)
    {
        seq->nodes[i] = seq->nodes[i + 1];
    }
    seq->current_length--;
    return 1;
}

//打印队列表
void Queue_print(char *title, struct Queue *seq)
{
    if (seq->current_length > 0 && strlen(title) > 1)
    {
        printf("==========[%s]==========\n", title);
    }
    for (int i = 0; i < seq->current_length; i++)
    {
        Node_print(seq->nodes[i]);
    }
}

//查找元素，返回下标，如果不存在返回-1;
int Queue_search(struct Queue *seq, struct Node node)
{
    for (int i = 0; i < seq->current_length; i++)
    {
        struct Node n = seq->nodes[i];
        if (Node_compare(n, node) == 0)
        {
            return i;
        }
    }
    return -1;
}

//比较获取对象
struct Node *Queue_compare_get(struct Queue *seq, struct Node node)
{
    for (int i = 0; i < seq->current_length; i++)
    {
        struct Node n = seq->nodes[i];
        if (Node_compare(n, node) == 0)
        {
            return &seq->nodes[i];
        }
    }
    return NULL;
}

//冒泡排序
void Queue_sort(struct Queue *seq)
{
    char flag = 0x01;
    for (int i = 0; i < seq->current_length && flag; i++)
    {
        flag = 0x00;
        for (int j = seq->current_length - 1; j > i; j--)
        {
            if (Node_compare(seq->nodes[j - 1], seq->nodes[j]) > 0)
            {
                Node_change(&(seq->nodes[j]), &(seq->nodes[j - 1]));
                flag = 0x01;
            }
        }
    }
}
