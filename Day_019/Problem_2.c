int maxSubarraySumCircular(int* nums, int n) {
    int total_sum = 0;
    int max_sum = nums[0], cur_max = 0;
    int min_sum = nums[0], cur_min = 0;

    for(int i = 0; i < n; i++) {
        total_sum += nums[i];

        // Maximum subarray (Kadane)
        cur_max = (cur_max > 0) ? cur_max + nums[i] : nums[i];
        if(cur_max > max_sum)
            max_sum = cur_max;

        // Minimum subarray
        cur_min = (cur_min < 0) ? cur_min + nums[i] : nums[i];
        if(cur_min < min_sum)
            min_sum = cur_min;
    }

    // If all elements are negative
    if(max_sum < 0)
        return max_sum;

    return (max_sum > total_sum - min_sum) ? max_sum : total_sum - min_sum;
}
