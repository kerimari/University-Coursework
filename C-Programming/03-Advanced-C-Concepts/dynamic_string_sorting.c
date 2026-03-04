#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Swaps two character pointers (addresses) to reorder strings.
 */
void swap_strings(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    // Array of 5 pointers to characters
    char *students[5];
    char buffer[100]; // Temporary buffer for input
    int i, j;

    printf("Enter names of 5 students:\n");
    for (i = 0; i < 5; i++) {
        printf("Student %d: ", i + 1);
        scanf("%s", buffer);
        
        // Allocate exact memory needed for the string (+1 for null terminator)
        students[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(students[i], buffer);
    }

    // Alphabetical Sorting (Selection Sort using Pointers)
    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 5; j++) {
            if (strcmp(students[i], students[j]) > 0) {
                swap_strings(&students[i], &students[j]);
            }
        }
    }

    printf("\nSorted Student List:\n");
    for (i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, students[i]);
        // Free allocated memory to prevent memory leaks
        free(students[i]);
    }

    return 0;
}
