#include "queue.h"

int main(int argc, char const *argv[])
{
    struct Node *n1 = Node_init(32);
    struct Node *n2 = Node_init(2);
    struct Node *n3 = Node_init(82);
    struct Node *n4 = Node_init(29);
    struct Queue *q = Queue_init(6);
    Queue_append(q, n1);
    Queue_append(q, n2);
    Queue_append(q, n3);
    Queue_append(q, n4);
    Queue_delete(q, 2);

    Queue_sort(q);
    Queue_print("Queue List", q);
}