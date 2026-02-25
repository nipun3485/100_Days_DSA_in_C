//Given an integer array nums, find the subarray with the largest sum, and return its sum.//
int maxSubArray(int* nums, int numsSize) {
    
    int currentSum = nums[0];
    int maxSum = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        
        // Either start fresh from nums[i] or continue previous sum
        if (currentSum + nums[i] > nums[i])
            currentSum = currentSum + nums[i];
        else
            currentSum = nums[i];
        
        // Update maximum sum found so far
        if (currentSum > maxSum)
            maxSum = currentSum;
    }
    
    return maxSum;
}
