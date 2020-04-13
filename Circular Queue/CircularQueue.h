#ifndef CIRCULARQUEUE_H_INCLUDED
#define CIRCULARQUEUE_H_INCLUDED
#define CAPACITY 7

struct queue
{
    int array[CAPACITY];
    int nr_elem;
    int head;
    int tail;
};

void enqueue(struct queue *my_queue, int key);
int dequeue(struct queue *my_queue);
void print_queue_contents(struct queue my_queue);

#endif // CIRCULARQUEUE_H_INCLUDED
