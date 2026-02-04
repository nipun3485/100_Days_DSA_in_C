#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int k = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main() {
    int numsSize, val;
    int nums[100];

    // Input size
    scanf("%d", &numsSize);

    // Input array elements
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }

    // Input value to remove
    scanf("%d", &val);

    // Call function
    int k = removeElement(nums, numsSize, val);

    // Print result array (first k elements)
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
