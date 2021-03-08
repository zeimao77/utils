#ifndef __AVLTREE__
#define __AVLTREE__

#include "inode.h"

//二叉树
struct Avltree
{
    struct Avltree *parent;
    struct Avltree *lchild, *rchild;
    struct Node *node;
    unsigned int height;
};

//获取根节点
struct Avltree *Avltree_root(struct Avltree *node);
//初始化平衡二叉树
struct Avltree *Avltree_init(struct Node *node);
//销毁二叉树
void Avltree_destroy(struct Avltree *node);
void Avltree_show(struct Avltree *tree);
//展示树
void Avltree_showTree(struct Avltree *tree);
//计算树高
int Avltree_calcheight(struct Avltree *tree);
//计算平衡因子
int Avltree_balance(struct Avltree *tree);
//打印树 i=1表示中序  i=2表示前序  i=3表示后序
void Avltree_print(struct Avltree *tree, int i);

static void Avltree_right_left_rocation(struct Avltree *tree);
static void Avltree_left_right_rocation(struct Avltree *tree);
static void Avltree_left_left_rocation(struct Avltree *tree);
static void Avltree_right_right_rocation(struct Avltree *tree);
static int Avltree_private_append(struct Avltree *tree, struct Node *node);
static int Avltree_private_delete(struct Avltree *tree, struct Node *node);
static void Avltree_refresh_height(struct Avltree *node);
static struct Avltree *Avltree_private_search(struct Avltree *tree, struct Node node);
struct Node *Avltree_search(struct Avltree *tree, struct Node node);
struct Avltree *Avltree_append(struct Avltree *tree, struct Node *node);
struct Avltree *Avltree_delete(struct Avltree *tree, struct Node *node);
#endif