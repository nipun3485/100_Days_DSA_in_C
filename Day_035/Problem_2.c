#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *s1;
    int *s2;
    int top1;
    int top2;
    int capacity;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->capacity = 10000;
    obj->s1 = (int*)malloc(sizeof(int) * obj->capacity);
    obj->s2 = (int*)malloc(sizeof(int) * obj->capacity);
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->s1[++obj->top1] = x;
}

void shiftStacks(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->s2[++obj->top2] = obj->s1[obj->top1--];
        }
    }
}

int myQueuePop(MyQueue* obj) {
    shiftStacks(obj);
    return obj->s2[obj->top2--];
}

int myQueuePeek(MyQueue* obj) {
    shiftStacks(obj);
    return obj->s2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj->s1);
    free(obj->s2);
    free(obj);
}
