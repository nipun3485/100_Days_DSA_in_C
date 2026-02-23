/*You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively. 

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].*/

#include <stdio.h>

// Function to merge nums2 into nums1
void merge(int nums1[], int m, int nums2[], int n) {
    int i = m - 1;        // Last valid element in nums1
    int j = n - 1;        // Last element in nums2
    int k = m + n - 1;    // Last index of nums1

    // Merge from the end
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // Copy remaining elements of nums2 (if any)
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    int m, n;

    // Input size of nums1 (valid elements)
    scanf("%d", &m);
    int nums1[m + 10];   // Extra space for nums2 elements

    // Input elements of nums1
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    // Input size of nums2
    scanf("%d", &n);
    int nums2[n];

    // Input elements of nums2
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    // Fill remaining positions of nums1 with 0
    for (int i = m; i < m + n; i++) {
        nums1[i] = 0;
    }

    // Call merge function
    merge(nums1, m, nums2, n);

    // Print merged array
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }

    return 0;
}

