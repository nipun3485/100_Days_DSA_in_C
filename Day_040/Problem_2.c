#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced.
 */
int* dailyTemperatures(int* temperatures,
                       int temperaturesSize,
                       int* returnSize) {

    int* answer =
        (int*)calloc(temperaturesSize, sizeof(int));

    int* stack =
        (int*)malloc(sizeof(int) * temperaturesSize);

    int top = -1;

    for(int i = 0; i < temperaturesSize; i++) {

        /* Warmer temperature found */
        while(top != -1 &&
              temperatures[i] >
              temperatures[stack[top]]) {

            int prevIndex = stack[top--];

            answer[prevIndex] =
                i - prevIndex;
        }

        /* Push current index */
        stack[++top] = i;
    }

    *returnSize = temperaturesSize;

    free(stack);

    return answer;
}
