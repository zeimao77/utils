#include "avltree.h"

int main(int argc, char const *argv[])
{
    int nums[29] = {1,6,7,2,5,3,4,8,20,19,15,14,13,12,17,18,45,43,23,55,67,76,55,44,32,23,54,65,88};
    int numss[3] = {5,6,12};
    int length = sizeof(nums) / 4;
    int length2 = sizeof(numss) / 4;
    struct Avltree *a = NULL;
    for (size_t i = 0; i < length; i++)
    {
        struct Node *n = Node_init(nums[i]);
        if(a == NULL) {
            a = Avltree_init(n);
        } else {
            a = Avltree_append(a,n);
        }
    }
    for (size_t i = 0; i < length2; i++)
    {
        struct Node *n = Node_init(numss[i]);
        a = Avltree_delete(a,n);
    }
    Avltree_showTree(a);
    Avltree_print(a,2);
}