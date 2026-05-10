#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced.
 */

int* maxSlidingWindow(int* nums, int numsSize,
                      int k, int* returnSize) {

    if(numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc(sizeof(int) * (numsSize - k + 1));

    int* deque = (int*)malloc(sizeof(int) * numsSize);

    int front = 0;
    int rear = -1;

    int idx = 0;

    for(int i = 0; i < numsSize; i++) {

        /* Remove indices out of current window */
        if(front <= rear && deque[front] <= i - k) {
            front++;
        }

        /* Remove smaller elements from back */
        while(front <= rear &&
              nums[deque[rear]] < nums[i]) {

            rear--;
        }

        /* Insert current index */
        deque[++rear] = i;

        /* Window starts forming */
        if(i >= k - 1) {

            result[idx++] = nums[deque[front]];
        }
    }

    *returnSize = idx;

    free(deque);

    return result;
}
