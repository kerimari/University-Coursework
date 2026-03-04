#include <stdio.h>
#include <string.h>

/**
 * Iterates through the string and swaps the case of each alphabetic character.
 * Uses ASCII values for manual conversion (e.g., 'a' - 32 = 'A').
 */
void alternate_case(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        // Check if character is lowercase
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; // Convert to uppercase
        }
        // Check if character is uppercase
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; // Convert to lowercase
        }
    }
}

int main() {
    char text[100];

    printf("Enter a line of text: ");
    // Using fgets instead of scanf to safely handle spaces in input
    fgets(text, sizeof(text), stdin);

    alternate_case(text);

    printf("Converted text: %s", text);

    return 0;
}
