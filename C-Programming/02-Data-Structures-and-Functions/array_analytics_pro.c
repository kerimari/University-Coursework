#include <stdio.h>
#include <stdlib.h> // for rand() ve srand() 
#include <time.h>   // for srand(time(NULL))

#define LEN 20 

// A function that finds the minimum value and its index.
void find_minimum(int arr[], int len) {
    int min = arr[0];
    int min_index = 0;
    for(int i = 1; i < len; i++) {
        if (arr[i] < min) {
            min = arr[i];
            min_index = i;
        }
    }
    printf("Minimum = %d (Found at index: %d)\n", min, min_index);
}

// A function that finds the maximum value and its index.
void find_maximum(int arr[], int len) {
    int max = arr[0];
    int max_index = 0;
    for(int i = 1; i < len; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_index = i;
        }
    }
    printf("Maximum = %d (Found at index: %d)\n", max, max_index);
}

// The function that calculates the sum.
int calculate_sum(int arr[], int len) {
    int s = 0;
    for(int i = 0; i < len; i++) {
        s += arr[i];
    }
    return s;
}

// The function that calculates the average.
float calculate_average(int arr[], int len) {
    return (float)calculate_sum(arr, len) / len;
}

int main(void) {
    int numbers[LEN];
    srand(time(NULL)); // To generate different numbers in each run

    printf("--- Array Data Generation ---\n");
    for(int i = 0; i < LEN; i++) {
        numbers[i] = rand() % 100; // For ease of analysis, use a range of 0-99.
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    printf("\n--- Advanced Analytics ---\n");
    find_minimum(numbers, LEN);
    find_maximum(numbers, LEN);
    
    int total_sum = calculate_sum(numbers, LEN);
    printf("Sum     = %d\n", total_sum);
    printf("Average = %.2f\n", calculate_average(numbers, LEN));

    return 0;
}
