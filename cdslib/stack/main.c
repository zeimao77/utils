#include "stack.h"

int main(int argc, char const *argv[])
{
    struct Stack *s = Stack_init(8);
    struct Node *n1 = Node_init(32);
    struct Node *n2 = Node_init(2);
    struct Node *n3 = Node_init(82);

    Stack_push(s, n1);
    Stack_push(s, n2);
    Stack_push(s, n3);
    struct Node *pop = Stack_pop(s);
    Node_print(*pop);
    Stack_print("stack List", *s);
}