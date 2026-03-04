#include <stdio.h>
#include <string.h>

#define MAX_LINES 6
#define MAX_LENGTH 1000

int main() {
    char current_line[MAX_LENGTH];
    char longest_line[MAX_LENGTH] = "";
    int max_length = 0;

    printf("Please enter %d lines of text:\n", MAX_LINES);

    for (int i = 1; i <= MAX_LINES; i++) {
        printf("Line %d: ", i);
        fgets(current_line, sizeof(current_line), stdin);

        // Remove the newline character at the end of the input
        current_line[strcspn(current_line, "\n")] = 0;

        int current_length = strlen(current_line);
        
        // Check if the current line is longer than the previous maximum
        if (current_length > max_length) {
            max_length = current_length;
            strcpy(longest_line, current_line);
        }
    }

    // Output the results
    printf("\nAnalysis Complete:\n");
    printf("The longest line has %d characters.\n", max_length);
    printf("Content: %s\n", longest_line);

    return 0;
}
