#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int freq;
} Pair;

/* Sort integers */
int compareNums(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/* Sort pairs by frequency descending */
int compareFreq(const void* a, const void* b) {

    Pair* p1 = (Pair*)a;
    Pair* p2 = (Pair*)b;

    return p2->freq - p1->freq;
}

/**
 * Note: The returned array must be malloced.
 */
int* topKFrequent(int* nums, int numsSize,
                  int k, int* returnSize) {

    qsort(nums, numsSize, sizeof(int), compareNums);

    Pair* arr = (Pair*)malloc(sizeof(Pair) * numsSize);

    int uniqueCount = 0;

    int i = 0;

    while(i < numsSize) {

        int count = 1;

        while(i + 1 < numsSize &&
              nums[i] == nums[i + 1]) {

            count++;
            i++;
        }

        arr[uniqueCount].num = nums[i];
        arr[uniqueCount].freq = count;

        uniqueCount++;

        i++;
    }

    qsort(arr, uniqueCount,
          sizeof(Pair), compareFreq);

    int* result = (int*)malloc(sizeof(int) * k);

    for(i = 0; i < k; i++) {

        result[i] = arr[i].num;
    }

    *returnSize = k;

    free(arr);

    return result;
}
