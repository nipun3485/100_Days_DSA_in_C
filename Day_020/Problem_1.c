#include <stdio.h>

int countZeroSumSubarrays(int arr[], int n) {
    int prefixSum = 0;
    int count = 0;

    // Map implemented using arrays (since constraints are reasonable)
    int freq[200001] = {0};
    int offset = 100000;   // To handle negative sums

    freq[offset] = 1;  // prefix sum = 0 initially

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        count += freq[prefixSum + offset];
        freq[prefixSum + offset]++;
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", countZeroSumSubarrays(arr, n));
    return 0;
}
