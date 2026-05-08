/*
Question 3: Quick Sort

Description:
Implement quick sort to sort an integer array in ascending order.

Quick sort is a divide-and-conquer algorithm:
1. Choose a pivot element.
2. Partition the array so that elements smaller than or equal to
   the pivot come before it, and elements greater than the pivot
   come after it.
3. Recursively sort the left and right parts.

You should implement:

    void quickSort(int arr[], int size);

You may design your own helper functions.
Suggested helper functions:

    void quickSortHelper(int arr[], int low, int high);
    int partition(int arr[], int low, int high);

For simplicity, you may use the last element as the pivot.

Example:
Input:  [10, 7, 8, 9, 1, 5]
Output: [1, 5, 7, 8, 9, 10]

Notes:
- If the array is empty or has only one element, do nothing.
- The sorting should be done in ascending order.
*/

// Helper function to swap two elements
static void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Suggested helper function to partition the array
static int partition(int arr[], int low, int high) {
    // Using the last element as the pivot as suggested
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Suggested helper function to handle recursion
static void quickSortHelper(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(int arr[], int size) {
    // Notes: If the array is empty or has only one element, do nothing.
    if (arr == (void*)0 || size <= 1) {
        return;
    }

    quickSortHelper(arr, 0, size - 1);
}