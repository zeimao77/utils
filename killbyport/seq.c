#include "seq.h"


//初始化队列表;
struct Seq *Seq_init(int size)
{
    struct Node *ns = (struct Node *)malloc(sizeof(struct Node) * size);
    struct Seq *seq = (struct Seq *)malloc(sizeof(struct Seq));
    seq->nodes = ns;
    seq->current_length = 0;
    return seq;
}

//追加元素节点;
int Seq_append(struct Seq *seq, struct Node *node)
{
    seq->nodes[seq->current_length] = *node;
    seq->current_length++;
    return 1;
}

//删除某个元素;
int Seq_delete(struct Seq *seq, int index)
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
void Seq_print(char *title, struct Seq *seq)
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
int Seq_search(struct Seq *seq, struct Node node)
{
    for (int i = 0; i < seq->current_length; i++)
    {
        struct Node n = seq->nodes[i];
        if (Node_compare(n, node) == 1)
        {
            return i;
        }
    }
    return -1;
}

//比较获取对象
struct Node Seq_compare_get(struct Seq *seq, struct Node node)
{
    for (int i = 0; i < seq->current_length; i++)
    {
        struct Node n = seq->nodes[i];
        if (Node_compare(n, node) == 1)
        {
            return seq->nodes[i];
        }
    }
}
