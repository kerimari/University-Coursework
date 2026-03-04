#include <stdio.h>
#include <string.h>

/**
 * Reverses the given character string in-place.
 */
void reverse(char s[], int size) {
    int i;
    char temp;
    for (i = 0; i < size / 2; i++) {
        temp = s[i];
        s[i] = s[size - 1 - i];
        s[size - 1 - i] = temp;
    }
}

/**
 * Deletes every occurrence of character 'c' from string 's'.
 * Shifts the remaining characters to fill the gaps.
 */
void delete_char(char s[], char c, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        if (s[i] == c) {
            // Shift all characters after 'c' one position to the left
            for (j = i; j < size - 1; j++) {
                s[j] = s[j + 1];
            }
            s[size - 1] = '\0'; // Set the new end of string
            size--; // Reduce size after deletion
            i--; // Re-check the current index for consecutive target chars
        }
    }
}

int main() {
    char str1[100], str2[100], target_char;
    
    printf("Enter a string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline
    
    strcpy(str2, str1); // Create a copy for step 2
    printf("Enter character to delete: ");
    scanf(" %c", &target_char);

    // Step 1: Reverse then delete
    reverse(str1, strlen(str1));
    delete_char(str1, target_char, strlen(str1));
    printf("Result 1 (Reverse -> Delete): %s\n", str1);

    // Step 2: Delete then reverse
    delete_char(str2, target_char, strlen(str2));
    reverse(str2, strlen(str2));
    printf("Result 2 (Delete -> Reverse): %s\n", str2);

    // Step 3: Compare results
    if (strcmp(str1, str2) == 0) {
        printf("Comparison: Both methods yielded the same result.\n");
    } else {
        printf("Comparison: Methods yielded different results.\n");
    }

    return 0;
}
