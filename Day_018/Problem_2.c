/*Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]. The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer. You must write an algorithm that runs in O(n) time and without using the division operation.*/

#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    
    *returnSize = numsSize;
    
    int* result = (int*)malloc(numsSize * sizeof(int));
    
    // Step 1: Compute prefix products
    result[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }
    
    // Step 2: Multiply with suffix products
    int suffix = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        result[i] = result[i] * suffix;
        suffix *= nums[i];
    }
    
    return result;
}
