#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int *arr;
    int front;
    int rear;
    int capacity;
};

struct Queue* createQueue(int n) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = n;
    q->arr = (int*)malloc(sizeof(int) * n);
    q->front = 0;
    q->rear = -1;
    return q;
}

void enqueue(struct Queue* q, int val) {
    if (q->rear < q->capacity - 1)
        q->arr[++q->rear] = val;
}

void display(struct Queue* q) {
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d", q->arr[i]);
        if (i != q->rear)
            printf(" ");
    }
}

int main() {
    int n, x;
    scanf("%d", &n);

    struct Queue* q = createQueue(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(q, x);
    }

    display(q);

    return 0;
}
