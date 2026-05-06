int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

int *result = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    int freq[1001] = {0};   // assuming values are in range 0–1000
    
    // Count frequency of nums1
    for(int i = 0; i < nums1Size; i++) {
        freq[nums1[i]]++;
    }
    
    int k = 0;
    
    // Check nums2
    for(int i = 0; i < nums2Size; i++) {
        if(freq[nums2[i]] > 0) {
            result[k++] = nums2[i];
            freq[nums2[i]]--;
        }
    }
    
    *returnSize = k;
    return result;
}

