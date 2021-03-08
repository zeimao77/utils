#include "avltree.h"

struct Avltree *Avltree_root(struct Avltree *node)
{
    struct Avltree *root = node;
    while (root->parent != NULL)
    {
        root = root->parent;
    }
    return root;
}

struct Avltree *Avltree_init(struct Node *node)
{
    struct Avltree *tree = (struct Avltree *)malloc(sizeof(struct Avltree));
    tree->lchild = NULL;
    tree->rchild = NULL;
    tree->parent = NULL;
    tree->node = node;
    tree->height = 1;
    return tree;
}

void Avltree_destroy(struct Avltree *t)
{
    if (t->node != NULL)
    {
        Node_destroy(t->node);
        t->node = NULL;
    }
    free(t);
    t = NULL;
}

void Avltree_show(struct Avltree *tree)
{
    printf("=========[node:%d;height:%d]===========\n", tree->node->value, tree->height);
    if (tree->parent != NULL)
    {
        printf("node.parent:%d\n", tree->parent->node->value);
    }
    if (tree->lchild != NULL)
    {
        printf("node.left:%d\n", tree->lchild->node->value);
    }
    if (tree->rchild != NULL)
    {
        printf("node.right:%d\n", tree->rchild->node->value);
    }
}

void Avltree_showTree(struct Avltree *tree)
{
    if (tree->lchild != NULL)
    {
        Avltree_showTree(tree->lchild);
    }
    Avltree_show(tree);
    if (tree->rchild != NULL)
    {
        Avltree_showTree(tree->rchild);
    }
}

int Avltree_calcheight(struct Avltree *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else if (tree->lchild == NULL && tree->rchild == NULL)
    {
        tree->height = 1;
    }
    else
    {
        int lh = Avltree_calcheight(tree->lchild);
        int rh = Avltree_calcheight(tree->rchild);
        tree->height = lh > rh ? lh + 1 : rh + 1;
    }
    return tree->height;
}

int Avltree_balance(struct Avltree *tree)
{
    int lh = 0, rh = 0;
    if (tree->lchild != NULL)
    {
        lh = tree->lchild->height;
    }
    if (tree->rchild != NULL)
    {
        rh = tree->rchild->height;
    }
    return lh - rh;
}

void Avltree_print(struct Avltree *tree, int i)
{
    switch (i)
    {
    case 1:
        Node_print(*(tree->node));
        if (tree->lchild != NULL)
        {
            Avltree_print(tree->lchild, i);
        }
        if (tree->rchild != NULL)
        {
            Avltree_print(tree->rchild, i);
        }
        break;
    case 2:
        if (tree->lchild != NULL)
        {
            Avltree_print(tree->lchild, i);
        }
        Node_print(*(tree->node));
        if (tree->rchild != NULL)
        {
            Avltree_print(tree->rchild, i);
        }
        break;
    case 3:
        if (tree->rchild != NULL)
        {
            Avltree_print(tree->rchild, i);
        }
        Node_print(*(tree->node));
        if (tree->lchild != NULL)
        {
            Avltree_print(tree->lchild, i);
        }
        break;
    default:
        break;
    }
}

static void Avltree_right_left_rocation(struct Avltree *tree)
{
    Avltree_left_left_rocation(tree->rchild);
    tree->rchild->height++;
    tree->rchild->rchild->height++;
    Avltree_right_right_rocation(tree);
}

static void Avltree_left_right_rocation(struct Avltree *tree)
{
    Avltree_right_right_rocation(tree->lchild);
    tree->lchild->height++;
    tree->lchild->lchild->height++;
    Avltree_left_left_rocation(tree);
}

static void Avltree_left_left_rocation(struct Avltree *tree)
{
    if (tree->parent != NULL && tree->parent->lchild == tree)
    {
        tree->parent->lchild = tree->lchild;
    }
    else if (tree->parent != NULL && tree->parent->rchild == tree)
    {
        tree->parent->rchild = tree->lchild;
    }
    tree->lchild->parent = tree->parent;
    struct Avltree *temp = tree->lchild;
    tree->lchild = tree->lchild->rchild;
    if (tree->lchild != NULL)
    {
        tree->lchild->parent = tree;
    }
    tree->parent = temp;
    temp->rchild = tree;
    tree->height -= 2;
}

static void Avltree_right_right_rocation(struct Avltree *tree)
{
    if (tree->parent != NULL && tree->parent->lchild == tree)
    {
        tree->parent->lchild = tree->rchild;
    }
    else if (tree->parent != NULL && tree->parent->rchild == tree)
    {
        tree->parent->rchild = tree->rchild;
    }
    tree->rchild->parent = tree->parent;
    struct Avltree *temp = tree->rchild;
    tree->rchild = tree->rchild->lchild;
    if (tree->rchild != NULL)
    {
        tree->rchild->parent = tree;
    }
    tree->parent = temp;
    temp->lchild = tree;
    tree->height -= 2;
}

struct Avltree *Avltree_append(struct Avltree *tree, struct Node *node)
{
    printf(">>>append node ==>> %d\n", node->value);
    Avltree_private_append(tree, node);
    return Avltree_root(tree);
}

struct Avltree *Avltree_delete(struct Avltree *tree, struct Node *node)
{
    printf(">>>delete node ==>> %d\n", node->value);
    Avltree_private_delete(tree, node);
    return Avltree_root(tree);
}

static int Avltree_private_delete(struct Avltree *tree, struct Node *node)
{
    int result = 0;
    int compare = Node_compare(*node, *(tree->node));
    struct Avltree *t = tree;
    struct Avltree *deleteNode = NULL;
    if (compare == 0)
    {
        if (t->lchild == NULL && t->rchild == NULL)
        {
            deleteNode = t;
        }
        else if (t->lchild != NULL && t->rchild == NULL)
        {
            deleteNode = t->lchild;
            while (deleteNode->rchild != NULL)
            {
                deleteNode = deleteNode->rchild;
            }
            Node_change(t->node,deleteNode->node);
        }
        else if (t->lchild == NULL && t->rchild != NULL)
        {
            deleteNode = t->rchild;
            while (deleteNode->lchild != NULL)
            {
                deleteNode = deleteNode->lchild;
            }
            Node_change(t->node,deleteNode->node);
        }
        else
        {
            deleteNode = t->lchild;
            while (deleteNode->rchild != NULL)
            {
                deleteNode = deleteNode->rchild;
            }
            Node_change(t->node,deleteNode->node);
        }
        if (deleteNode->parent == NULL)
        {
            return 1;
        }
        else if (deleteNode == deleteNode->parent->lchild && deleteNode->parent->rchild == NULL)
        {
            deleteNode->parent->lchild = NULL;
        }
        else if (deleteNode == deleteNode->parent->lchild && deleteNode->parent->rchild != NULL)
        {
            deleteNode->parent->lchild = NULL;
        }
        else if (deleteNode == deleteNode->parent->rchild && deleteNode->parent->lchild == NULL)
        {
            deleteNode->parent->rchild = NULL;
        }
        else if (deleteNode == deleteNode->parent->rchild && deleteNode->parent->lchild != NULL)
        {
            deleteNode->parent->rchild = NULL;
        }
        struct Avltree *temp = deleteNode -> parent;
        while (temp != NULL)
        {
            Avltree_refresh_height(temp);
            int check = Avltree_balance(temp);
            if(check == 2) {
                int lcheck = Avltree_balance(temp->lchild);
                if(lcheck >= 0) {
                    Avltree_left_left_rocation(temp);
                } else if(lcheck < 0) {
                    Avltree_left_right_rocation(temp);
                }
            } else if(check == -2) {
                int rcheck = Avltree_balance(temp->rchild);
                if(rcheck > 0) {
                    Avltree_right_left_rocation(temp);
                } else if(rcheck <= 0) {
                    Avltree_right_right_rocation(temp);
                }
            }
            temp = temp -> parent;
        }
    }
    else if (compare > 0)
    {
        result = Avltree_private_delete(tree->rchild, node);
    }
    else
    {
        result = Avltree_private_delete(tree->lchild, node);
    }
    return result;
}

static int Avltree_private_append(struct Avltree *tree, struct Node *node)
{
    int result = 0;
    int compare = Node_compare(*node, *(tree->node));
    if (compare > 0)
    {
        if (tree->rchild == NULL)
        {
            struct Avltree *newNode = Avltree_init(node);
            tree->rchild = newNode;
            newNode->parent = tree;
            result = 1;
        }
        else
        {
            result = Avltree_private_append(tree->rchild, node);
        }
    }
    else if (compare < 0)
    {
        if (tree->lchild == NULL)
        {
            struct Avltree *newNode = Avltree_init(node);
            tree->lchild = newNode;
            newNode->parent = tree;
            result = 1;
        }
        else
        {
            result = Avltree_private_append(tree->lchild, node);
        }
    }
    else
    {
        return 0;
    }
    Avltree_refresh_height(tree);
    int check = Avltree_balance(tree);
    if(check == 2) {
        int lcheck = Avltree_balance(tree->lchild);
        if(lcheck >= 0) {
            Avltree_left_left_rocation(tree);
        } else if(lcheck < 0) {
            Avltree_left_right_rocation(tree);
        }
    } else if(check == -2) {
        int rcheck = Avltree_balance(tree->rchild);
        if(rcheck > 0) {
            Avltree_right_left_rocation(tree);
        } else if(rcheck <= 0) {
            Avltree_right_right_rocation(tree);
        }
    }
    return result;
}

static void Avltree_refresh_height(struct Avltree *node) {
    int lheight = 0,rheight = 0;
    if(node -> lchild != NULL) {
        lheight = node -> lchild -> height;
    }
    if(node -> rchild != NULL) {
        rheight = node -> rchild -> height;
    }
    node -> height = lheight>rheight?lheight+1:rheight+1;
}

static struct Avltree *Avltree_private_search(struct Avltree *tree, struct Node node)
{
    int compare = Node_compare(node, *(tree->node));
    if (compare == 0)
    {
        return tree;
    }
    else if (compare > 0)
    {
        return Avltree_private_search(tree->rchild, node);
    }
    else
    {
        return Avltree_private_search(tree->lchild, node);
    }
    return NULL;
}

struct Node *Avltree_search(struct Avltree *tree, struct Node node)
{
    struct Avltree *t = Avltree_private_search(tree, node);
    return t->node;
}