#include <stdio.h>
#include <stdlib.h>

typedef struct {

    int* maxHeap;
    int maxSize;

    int* minHeap;
    int minSize;

} MedianFinder;

/* ---------- Utility Swap ---------- */

void swap(int* a, int* b) {

    int temp = *a;
    *a = *b;
    *b = temp;
}

/* ---------- MAX HEAP FUNCTIONS ---------- */

void maxHeapifyUp(int* heap, int index) {

    while(index > 0) {

        int parent = (index - 1) / 2;

        if(heap[parent] < heap[index]) {

            swap(&heap[parent], &heap[index]);

            index = parent;
        }
        else {
            break;
        }
    }
}

void maxHeapifyDown(int* heap,
                    int size,
                    int index) {

    while(1) {

        int left = 2 * index + 1;
        int right = 2 * index + 2;

        int largest = index;

        if(left < size &&
           heap[left] > heap[largest]) {

            largest = left;
        }

        if(right < size &&
           heap[right] > heap[largest]) {

            largest = right;
        }

        if(largest != index) {

            swap(&heap[index], &heap[largest]);

            index = largest;
        }
        else {
            break;
        }
    }
}

/* ---------- MIN HEAP FUNCTIONS ---------- */

void minHeapifyUp(int* heap, int index) {

    while(index > 0) {

        int parent = (index - 1) / 2;

        if(heap[parent] > heap[index]) {

            swap(&heap[parent], &heap[index]);

            index = parent;
        }
        else {
            break;
        }
    }
}

void minHeapifyDown(int* heap,
                    int size,
                    int index) {

    while(1) {

        int left = 2 * index + 1;
        int right = 2 * index + 2;

        int smallest = index;

        if(left < size &&
           heap[left] < heap[smallest]) {

            smallest = left;
        }

        if(right < size &&
           heap[right] < heap[smallest]) {

            smallest = right;
        }

        if(smallest != index) {

            swap(&heap[index], &heap[smallest]);

            index = smallest;
        }
        else {
            break;
        }
    }
}

/* ---------- Constructor ---------- */

MedianFinder* medianFinderCreate() {

    MedianFinder* obj =
        (MedianFinder*)malloc(sizeof(MedianFinder));

    obj->maxHeap =
        (int*)malloc(sizeof(int) * 50000);

    obj->minHeap =
        (int*)malloc(sizeof(int) * 50000);

    obj->maxSize = 0;
    obj->minSize = 0;

    return obj;
}

/* ---------- Add Number ---------- */

void medianFinderAddNum(MedianFinder* obj, int num) {

    /* Insert into max heap */

    if(obj->maxSize == 0 ||
       num <= obj->maxHeap[0]) {

        obj->maxHeap[obj->maxSize] = num;

        maxHeapifyUp(obj->maxHeap,
                     obj->maxSize);

        obj->maxSize++;
    }
    else {

        obj->minHeap[obj->minSize] = num;

        minHeapifyUp(obj->minHeap,
                     obj->minSize);

        obj->minSize++;
    }

    /* Balance heaps */

    if(obj->maxSize > obj->minSize + 1) {

        int val = obj->maxHeap[0];

        obj->maxHeap[0] =
            obj->maxHeap[obj->maxSize - 1];

        obj->maxSize--;

        maxHeapifyDown(obj->maxHeap,
                       obj->maxSize,
                       0);

        obj->minHeap[obj->minSize] = val;

        minHeapifyUp(obj->minHeap,
                     obj->minSize);

        obj->minSize++;
    }

    else if(obj->minSize > obj->maxSize) {

        int val = obj->minHeap[0];

        obj->minHeap[0] =
            obj->minHeap[obj->minSize - 1];

        obj->minSize--;

        minHeapifyDown(obj->minHeap,
                       obj->minSize,
                       0);

        obj->maxHeap[obj->maxSize] = val;

        maxHeapifyUp(obj->maxHeap,
                     obj->maxSize);

        obj->maxSize++;
    }
}

/* ---------- Find Median ---------- */

double medianFinderFindMedian(MedianFinder* obj) {

    if(obj->maxSize > obj->minSize) {

        return obj->maxHeap[0];
    }

    return
        (obj->maxHeap[0]
        + obj->minHeap[0]) / 2.0;
}

/* ---------- Free Memory ---------- */

void medianFinderFree(MedianFinder* obj) {

    free(obj->maxHeap);

    free(obj->minHeap);

    free(obj);
}
