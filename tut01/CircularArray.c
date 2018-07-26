#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void initQueue(Queue *q) {
    q = malloc(sizeof(Queue));
    q->nitems = 0;
    q->head = 0;
    q->tail = 0;
}

void enterQueue(Queue *q, int item) {
    int pos;
    if (!q->nitems)
        pos = (q->tail + 1) % MAXQ;
    else
        pos = q->head;
    q->items[pos] = item;
    q->tail = pos;
    if (pos == q->head && q->nitems)
        q->head++;
    else
        q->nitems++;
}

int leaveQueue(Queue *q) {
    if (!q->nitems)
        return 0;
    int item = q->items[q->head];
    q->head = (q->head + 1) % MAXQ;
    q->nitems--;
    return item;
}

int lengthQueue(Queue q) {
    return q.nitems;
}

void showQueue(Queue q) {
    printf("< ");
    for (int i = 0; i < q.nitems; i++) {
        printf("%d ", q.items[(q.head + i) % MAXQ]);
    }
    printf(">\n");
}