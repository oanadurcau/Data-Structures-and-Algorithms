#include <stdlib.h>
#include <stdio.h>
#include "CircularQueue.h"
#define CAPACITY 7


void enqueue(struct queue *my_queue, int key)
{
    //TODO add code here
    if(my_queue->nr_elem < CAPACITY)
    {
        my_queue->array[my_queue->tail] = key;
        my_queue->tail = (my_queue->tail + 1) % CAPACITY;
        my_queue->nr_elem++;
    }
    else
    {
        printf("Overflow\n");
    }

}

int dequeue(struct queue *my_queue)
{
    //TODO add code here
    if(my_queue->nr_elem != 0)
    {
        int val = my_queue->array[my_queue->head];
        my_queue->head = (my_queue->head + 1) % CAPACITY;
        my_queue->nr_elem--;
        return val;
    }
    return -1;
}

void print_queue_contents(struct queue my_queue)
{
    //TODO add code here);
    for (int i = 0; i < my_queue.nr_elem ; i++)
    {
        int p = (i + my_queue.head) % CAPACITY;
        printf("%d ", my_queue.array[p]);

    }
    printf("\n");

}
