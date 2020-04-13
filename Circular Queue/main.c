#include <stdlib.h>
#include <stdio.h>
#include "CircularQueue.h"
#define CAPACITY 7

int main()
{

    struct queue a_queue = {{0},0,0,0};

    enqueue(&a_queue, 1);
    enqueue(&a_queue, 3);
    enqueue(&a_queue, 5);
    enqueue(&a_queue, 2);

    print_queue_contents(a_queue); // 1 3 5 2

    dequeue(&a_queue);
    dequeue(&a_queue);

    print_queue_contents(a_queue); // 5 2

    enqueue(&a_queue, 4);
    enqueue(&a_queue, 9);
    enqueue(&a_queue, 2);
    enqueue(&a_queue, 6);

    print_queue_contents(a_queue); // 5 2 4 9 2 6

    dequeue(&a_queue);

    print_queue_contents(a_queue); // 2 4 9 2 6

    enqueue(&a_queue, 3);
    enqueue(&a_queue, 7);

    print_queue_contents(a_queue); // 2 4 9 2 6 3 7

    enqueue(&a_queue, 9); //overflow
    dequeue(&a_queue);
    dequeue(&a_queue);
    dequeue(&a_queue);
    dequeue(&a_queue);
    dequeue(&a_queue);
    dequeue(&a_queue);
    dequeue(&a_queue);
    dequeue(&a_queue);

    print_queue_contents(a_queue); // 2 4 9 2 6

    return 0;
}
