#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void initQueue(Queue *q) {
    q = malloc(sizeof(Queue));
    q->nitems = 0;
}

void enterQueue(Queue *q, int item) {
    if (q->nitems < MAXQ) {
        q->items[q->nitems] = item;
        q->nitems++;
    }
}

int leaveQueue(Queue *q) {
    if (!q->nitems)
        return 0;
    int item = q->items[0];
    q->nitems--;
    for (int i = 0; i < q->nitems; i++)
        q->items[i] = q->items[i + 1];
    return item;
}

int lengthQueue(Queue q) {
    return q.nitems;
}

void showQueue(Queue q) {
    printf("< ");
    for (int i = 0; i < q.nitems; i++) {
        printf("%d ", q.items[i]);
    }
    printf(">\n");
}