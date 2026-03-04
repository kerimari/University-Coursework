#include <stdio.h>

/**
 * Swaps two integers using their memory addresses (Call by Reference).
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Finds the index of the minimum element within a specific range of an array.
 */
int index_of_minimum(int arr[], int start_index, int size) {
    int min_index = start_index;
    for (int i = start_index + 1; i < size; i++) {
        if (arr[i] < arr[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}

/**
 * Sorts an array using the Selection Sort algorithm with pointer logic.
 */
void selection_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // Find the index of the smallest element in the remaining unsorted array
        int min_idx = index_of_minimum(arr, i, size);
        
        // Swap the found minimum element with the first element of the unsorted part
        swap(&arr[i], &arr[min_idx]);
    }
}

int main() {
    int data[] = {64, 25, 12, 22, 11};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) printf("%d ", data[i]);

    selection_sort(data, n);

    printf("\nSorted array:   ");
    for (int i = 0; i < n; i++) printf("%d ", data[i]);
    printf("\n");

    return 0;
}
