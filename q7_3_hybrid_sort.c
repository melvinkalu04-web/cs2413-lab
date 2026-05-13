#include <stdio.h>
#include <stdlib.h>

// Q7.3: Hybrid Merge Sort using Insertion Sort for small subarrays
// Based on Q2 (merge sort) and Q4 (insertion sort)
//
// Strategy: When a subarray's size is <= K, use insertion sort instead of
// continuing to divide. This avoids recursion overhead on small inputs.

#define K 4  // Threshold: subarrays of size <= K use insertion sort

// From Q4: Insertion sort on subarray arr[left..right]
void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// From Q2: Merge two sorted halves arr[left..mid] and arr[mid+1..right]
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else               arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

// Hybrid merge sort: use insertion sort when subarray size <= K
void hybridMergeSort(int arr[], int left, int right) {
    if (right - left + 1 <= K) {
        // Small subarray: use insertion sort (fast in practice for small n)
        insertionSort(arr, left, right);
        return;
    }

    // Large subarray: standard merge sort divide-and-conquer
    int mid = left + (right - left) / 2;
    hybridMergeSort(arr, left, mid);
    hybridMergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {39, 9, 81, 45, 90, 27, 72, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Input array:  ");
    printArray(arr, n);

    hybridMergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
