#include <stdio.h>

int missingNum(int arr[], int size) {
    long long n = size + 1;
    long long expectedSum = n * (n + 1) / 2;
    long long actualSum = 0;

    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }

    return (int)(expectedSum - actualSum);
}

int main() {
    int arr[] = {1, 2, 3, 5};
    int size = 4;

    printf("Missing number: %d\n", missingNum(arr, size));
    return 0;
}
